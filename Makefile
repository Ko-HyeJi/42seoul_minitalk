# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyko <hyko@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 20:06:31 by hyko              #+#    #+#              #
#    Updated: 2022/05/29 16:09:10 by hyko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client

SERVER_DIR = ./
CLIENT_DIR = ./
OBJ_DIR = ./obj

PRINTF = ./ft_printf/libftprintf.a
LIBFT = ./libft/libft.a

SERVER_FILES = server.c

CLIENT_FILES = client.c

IFLAGS = -I./libft -I./ft_printf
LFLAGS = -L./libft -L./ft_printf -lftprintf -lft

SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(SERVER_FILES:.c=.o))
CLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(CLIENT_FILES:.c=.o))

CFLAGS = -Wall -Werror -Wextra
CC = gcc
RM = rm -rf

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJ_DIR) $(SERVER) $(CLIENT)

bonus: all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) -o $(SERVER) $(LFLAGS)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) -o $(CLIENT) $(LFLAGS) 

$(OBJ_DIR)/%.o: $(SERVER_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(CLIENT_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(PRINTF):
	make -C ./ft_printf

$(LIBFT):
	make -C ./libft

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	make -C ./libft fclean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re: fclean all