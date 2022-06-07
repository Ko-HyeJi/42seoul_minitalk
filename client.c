/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:06:28 by hyko              #+#    #+#             */
/*   Updated: 2022/06/07 18:27:48 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_signal(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		write(1, "./client [PID] [MSG]\n", 21);
		return (0);
	}
	while (argv[2][i])
	{
		ft_send_signal(pid, argv[2][i]);
		i++;
	}
	ft_send_signal(pid, '\n');
	return (0);
}
