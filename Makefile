# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 20:06:31 by hyko              #+#    #+#              #
#    Updated: 2022/06/07 18:05:46 by hyko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client

CC = cc
CFLAG = -Wall -Wextra -Werror
RM = rm -rf

SERVER_SRCS = server.c minitalk_utils.c
CLIENT_SRCS = client.c minitalk_utils.c

SERVER_OBJS = server.o minitalk_utils.o
CLIENT_OBJS = client.o minitalk_utils.o

all : $(NAME)

$(NAME) : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJS)
	$(CC) $(CFLAG) -o $@ $^
	
$(CLIENT) : $(CLIENT_OBJS)
	$(CC) $(CFLAG) -o $@ $^

clean :
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean : clean
	$(RM) $(SERVER) $(CLIENT)

re : fclean all