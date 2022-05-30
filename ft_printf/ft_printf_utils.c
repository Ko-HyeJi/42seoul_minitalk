/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:05:35 by hyko              #+#    #+#             */
/*   Updated: 2022/05/12 15:05:50 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int ret)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (ret + 1);
}

int	ft_putstr(char *s, int ret)
{
	int	i;

	if (s == NULL)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (ret + 6);
	}
	i = 0;
	while (s[i] != '\0')
	{
		if (write(1, &s[i], 1) < 0)
			return (-1);
		ret += 1;
		i++;
	}
	return (ret);
}

int	ft_putnbr(int n, int ret)
{
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) < 0)
			return (-1);
		return (ret + 11);
	}
	if (n < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		ret += 1;
		n *= -1;
	}
	if (n > 9)
		ret = ft_putnbr(n / 10, ret);
	if (write(1, &"0123456789"[n % 10], 1) < 0)
		return (-1);
	ret += 1;
	return (ret);
}

int	ft_putnbr_unsigned(unsigned int n, int ret)
{
	if (n > 9)
		ret = ft_putnbr_unsigned(n / 10, ret);
	if (write(1, &"0123456789"[n % 10], 1) < 0)
		return (-1);
	ret += 1;
	return (ret);
}

int	ft_puthex(unsigned long long h, int ret, char fmt)
{
	if (h > 15)
		ret = ft_puthex(h / 16, ret, fmt);
	if (fmt == 'x' || fmt == 'p')
	{
		if (write(1, &"0123456789abcdef"[h % 16], 1) < 0)
			return (-1);
		ret += 1;
	}
	else
	{
		if (write(1, &"0123456789ABCDEF"[h % 16], 1) < 0)
			return (-1);
		ret += 1;
	}
	return (ret);
}
