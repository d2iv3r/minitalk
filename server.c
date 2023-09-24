/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:34:08 by efarhat           #+#    #+#             */
/*   Updated: 2023/01/19 14:48:59 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	i;
	static int	pid;

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
		ft_printf("%c", c);
		c = 0;
		i = 0;
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
