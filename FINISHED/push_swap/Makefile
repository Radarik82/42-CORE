# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/17 18:16:40 by ariazano          #+#    #+#              #
#    Updated: 2023/10/04 14:44:38 by ariazano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRC_PATH = src/
OBJ_PATH = obj/
SRC = calculate.c \
		init.c \
		input_check_2.c \
		input_check_utils.c \
		input_check.c \
		main.c \
		move.c \
		movecost.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		sort_three.c \
		sort.c \
		stacking.c \
		swap.c \
		utils.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
INCS = -I ./inc/
LIBFT_DIR =	./libft
LIBFT =	$(LIBFT_DIR)/libft.a


#all : $(NAME)

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

#$(OBJ_PATH)%.o: $(SRC_PATH)%.c
#	$(CC) -O1 -g -fsanitize=address -fno-omit-frame-pointer $(CFLAGS) -c $< -o $@ $(INCS)

$(NAME): 
#	$(CC) -O1 -g -fsanitize=address -fno-omit-frame-pointer $(CFLAGS) -c $(SRCS) $(INCS)
	@$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

clean:
	rm -rf $(OBJ_PATH) $(LIBFT_DIR)/*.o

fclean: clean
	rm -f $(NAME) $(LIBFT_DIR)/*.o libft/libft.a

re: fclean all

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re 