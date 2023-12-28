# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 01:12:50 by ariazano          #+#    #+#              #
#    Updated: 2023/11/19 13:26:05 by ariazano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
RM = rm -rf

SERVER = server
CLIENT = client
SRCS = src/server.c
OBJS = $(SRCS:.c=.o)

CLIENT_SRCS = src/client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
BONUS_SRCS = src/server_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CLIENT_BONUS_SRCS = src/client_bonus.c
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -C ./libft
$(SERVER): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o server
$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o client
	
$(SERVER_BONUS): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o server_bonus
$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(LIBFT) -o client_bonus

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS) $(CLIENT_OBJS)
	$(RM) $(BONUS_OBJS) $(CLIENT_BONUS_OBJS) 
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(SERVER) $(CLIENT)
	$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)
re: fclean all bonus

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)