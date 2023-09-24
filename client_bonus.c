/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:46:55 by efarhat           #+#    #+#             */
/*   Updated: 2023/01/19 14:49:04 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("\nThe signal has received!\n");
}

void	ft_sigbit(char c, int pid)
{
	int	j;

	j = 0;
	while (j <= 7)
	{
		if (((c >> j) & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(800);
		j++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;
	int	len;

	if (argc != 3)
	{
		ft_printf("Error : Args!");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, &sig_handler);
	i = 0;
	len = ft_strlen(argv[2]);
	pid = ft_atoi(argv[1]);
	while (i <= len)
	{
		ft_sigbit(argv[2][i], pid);
		i++;
	}
	return (0);
}
