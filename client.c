/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:57:28 by efarhat           #+#    #+#             */
/*   Updated: 2023/01/19 14:49:15 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sigbit(int c, pid_t pid)
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
	int	i;
	int	pid;

	if (argc != 3)
	{
		ft_printf("Error : Args!");
		exit(EXIT_FAILURE);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		ft_sigbit(argv[2][i], pid);
		i++;
	}
	return (0);
}
