/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:05:41 by hyko              #+#    #+#             */
/*   Updated: 2022/05/12 15:05:53 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		parse_format(va_list *ap, char fmt);
char	*ft_strchr(const char *s, int c);
int		ft_putchar(char c, int ret);
int		ft_putstr(char *s, int ret);
int		ft_putnbr(int d, int ret);
int		ft_putnbr_unsigned(unsigned int n, int ret);
int		ft_puthex(unsigned long long h, int ret, char fmt);

#endif