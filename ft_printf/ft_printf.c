/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:05:39 by hyko              #+#    #+#             */
/*   Updated: 2022/05/12 15:05:51 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

int	parse_format(va_list *ap, char fmt)
{
	int	ret;

	ret = 0;
	if (fmt == '%')
		ret = ft_putchar('%', ret);
	else if (fmt == 'c')
		ret = ft_putchar(va_arg(*ap, int), ret);
	else if (fmt == 's')
		ret = ft_putstr(va_arg(*ap, char *), ret);
	else if (fmt == 'd' || fmt == 'i')
		ret = ft_putnbr(va_arg(*ap, int), ret);
	else if (fmt == 'u')
		ret = ft_putnbr_unsigned((unsigned int)va_arg(*ap, int), ret);
	else if (ft_strchr("xX", fmt))
		ret = ft_puthex((unsigned int)va_arg(*ap, int), ret, fmt);
	else if (fmt == 'p')
	{
		ret = ft_putstr("0x", ret);
		ret = ft_puthex((unsigned long long)va_arg(*ap, void *), ret, fmt);
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		result;
	va_list	ap;

	i = 0;
	result = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			result = ft_putchar(format[i], result);
		else if (ft_strchr("%csdiuxXp", format[i + 1]))
		{
			i++;
			result += parse_format(&ap, format[i]);
		}
		else
			i++;
		i++;
	}
	va_end(ap);
	return (result);
}
