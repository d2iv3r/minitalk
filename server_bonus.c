/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:44:55 by efarhat           #+#    #+#             */
/*   Updated: 2023/01/19 14:53:06 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_j;

int	check_byts(unsigned char c)
{
	int	b;

	b = 0;
	if (c >= 0 && c <= 127)
		b = 1;
	else if (c >= 192 && c <= 223)
		b = 2;
	else if (c >= 224 && c <= 239)
		b = 3;
	else if (c >= 240 && c <= 247)
		b = 4;
	return (b);
}

void	unicode_handle(unsigned char c)
{
	static unsigned char	s[4];
	static int				byt;
	int						i;

	if (g_j == 0)
		byt = check_byts(c);
	if (g_j < byt)
	{
		s[g_j] = c;
		g_j++;
	}
	if (g_j == byt)
	{
		i = 0;
		while (i < byt)
		{
			ft_printf("%c", s[i]);
			i++;
		}
		g_j = 0;
		byt = 0;
		ft_bzero(s, 4);
	}
}

void	send_sig(int pid)
{
	if (kill(pid, SIGUSR1) == -1)
		exit(EXIT_FAILURE);
}

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	c;
	static int				i;
	static int				pid;

	(void)ucontext;
	if (info->si_pid != pid)
	{
		c = 0;
		i = 0;
	}
	pid = info->si_pid;
	if (sig == SIGUSR2)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		if (!c)
			send_sig(info->si_pid);
		else if (check_byts(c) == 1 && g_j == 0)
			ft_printf("%c", c);
		else
			unicode_handle(c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sigac;

	ft_printf("PID : %d\n", getpid());
	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = &sig_handler;
	if (sigaction(SIGUSR1, &sigac, 0) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sigac, 0) == -1)
		exit(EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
