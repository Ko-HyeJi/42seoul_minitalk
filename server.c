/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:06:23 by hyko              #+#    #+#             */
/*   Updated: 2022/05/30 16:27:48 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal_handler(int sig)
{
	static char	c;
	static int	i;

	if (i < 8)
	{
		c = c << 1;
		if (sig == SIGUSR2)
			c += 1;
		i++;
	}
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("PID : %d\n", getpid());
	signal(SIGUSR1, &ft_signal_handler);
	signal(SIGUSR2, &ft_signal_handler);
	while (1)
		pause();
	return (0);
}
