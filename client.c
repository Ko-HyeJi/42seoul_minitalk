/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:06:28 by hyko              #+#    #+#             */
/*   Updated: 2022/05/27 02:35:38 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	long long	i;
	long long	sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		if (result * sign > 2147483647)
			return (-1);
		else if (result * sign < -2147483648)
			return (0);
		i++;
	}
	return (result * sign);
}

void	ft_kill(char *pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> (7 - i)) % 2 == 0)
			kill(ft_atoi(pid), SIGUSR1);
		else
			kill(ft_atoi(pid), SIGUSR2);
		i++;
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[2][i])
	{
		ft_kill(argv[1], argv[2][i]);
		i++;
	}
	j = 0;
	ft_kill(argv[1], '\n');
	return (0);
}
