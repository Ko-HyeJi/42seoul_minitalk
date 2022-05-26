/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:06:23 by hyko              #+#    #+#             */
/*   Updated: 2022/05/27 02:45:03 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

char	g_char = 0;
int		g_cnt = 0;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 0)
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
	}
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		write(1, "-", 1);
		if (-10 < nb)
			ft_putchar(nb * -1 + '0');
		else
		{
			ft_putnbr(nb * -1 / 10);
			ft_putnbr(nb * -1 % 10);
		}
	}
}

void	handler(int sig)
{
	if (g_cnt < 8)
	{
		g_char = g_char << 1;
		if (sig == SIGUSR2)
			g_char += 0B00000001;
		g_cnt++;
	}
	if (g_cnt == 8)
	{
		write(1, &g_char, 1);
		g_char = 0;
		g_cnt = 0;
	}
}

int	main(void)
{
	int	s_pid;

	s_pid = getpid();
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	write(1, "PID : ", 6);
	ft_putnbr(s_pid);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
