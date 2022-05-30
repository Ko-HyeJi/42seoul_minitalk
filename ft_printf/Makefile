# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 15:05:44 by hyko              #+#    #+#              #
#    Updated: 2022/05/12 15:05:52 by hyko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAG = -Wall -Wextra -Werror

RM = rm -rf

SRC = ft_printf.c ft_printf_utils.c

%.o : %.c
	$(CC) $(CFLAG) -c $^ -o $@

OBJ = $(SRC:.c=.o)

all : $(NAME)
	
$(NAME) : $(OBJ)
	ar rc $@ $^	

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re