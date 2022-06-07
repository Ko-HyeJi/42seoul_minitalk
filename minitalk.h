/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:05:33 by hyko              #+#    #+#             */
/*   Updated: 2022/06/05 20:13:10 by hyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

void	ft_signal_handler(int sig);
void	ft_send_signal(char *pid, char c);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(const char *str);

#endif