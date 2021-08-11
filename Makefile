# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 20:46:22 by rtomiki           #+#    #+#              #
#    Updated: 2021/08/03 22:27:57 by rtomiki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBS = -L./libft -lft
LIBFT = libft.a
SRCS = main_server.c main_client.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -C ./libft

$(SERVER): main_server.o
	$(CC) main_server.o $(LIBS) -o $(SERVER)

$(CLIENT): main_client.o
	$(CC) main_client.o $(LIBS) -o $(CLIENT)

clean:
	rm -rf *.o ./libft/*.o

fclean:	clean
	rm -rf $(CLIENT) $(SERVER) ./libft/libft.a

re: fclean all
