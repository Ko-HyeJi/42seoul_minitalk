/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:06:28 by hyko              #+#    #+#             */
/*   Updated: 2022/05/30 16:28:49 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_signal(char *pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) % 2 == 0)
			kill(ft_atoi(pid), SIGUSR1);
		else
			kill(ft_atoi(pid), SIGUSR2);
		i--;
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("./client [PID] [MSG]\n");
		return (0);
	}
	while (argv[2][i])
	{
		ft_send_signal(argv[1], argv[2][i]);
		i++;
	}
	ft_send_signal(argv[1], '\n');
	return (0);
}
