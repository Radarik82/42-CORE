# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 15:21:33 by ariazano          #+#    #+#              #
#    Updated: 2023/12/16 18:40:56 by ariazano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell
# NAME_BONUS		=
HEADERS 		= minishell.h
GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m
LIBFT_DIR 		= libft/
LIBFT 			= $(LIBFT_DIR)/libft.a
CC 				= cc
#MLXLIB_DIR 		= mlx/
#MLXLIB 			= $(MLXLIB_DIR)/libmlx.a

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
					--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

RM 				= rm -rf
SRCS_DIR		= src/
OBJS_DIR		= objs/
#BONUS_SRCS_DIR	= src_bonus/

SRCS 			= $(addprefix $(BONUS_SRCS_DIR),\


OBJS 			:= $(SRCS:$(SRCS_DIR)%.c=$(SRCS_DIR)%.o)
#OBJS 			:= $(SRCS:$(BONUS_SRCS_DIR)%.c=$(BONUS_SRCS_DIR)%.o)

# SRCS_BONUS 		= $(addprefix $(BONUS_SRCS_DIR),\

CFLAGS 			= -Wall -Werror -Wextra -g -fsanitize=address


all: $(NAME)

$(NAME): $(OBJS)  $(LIBFT)
	mkdir -p $(OBJS_DIR)
	cc $(CFLAGS) -L$(MLXLIB_DIR) $(MLXFLAGS) $(LIBFT) $(OBJS) -o $@

$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)


bonus: all


clean:
	$(MAKE) clean -C $(LIBFT_DIR) 
	rm -f $(OBJS) 
	# make -C $(MLXLIB_DIR)  clean

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY:			all clean fclean re rebonus valgrind run run_bonus






#MLXFLAGS		= -lmlx -framework OpenGL -framework AppKit
 					#  -lXext -lm -Lmlx

# all:			${LIBFT} ${NAME}

# ${NAME}: 		 $(OBJS)
# 				# ${CC} ${SRCS} ${LIBFT} ${FLAGS} ${MLX_FLAGS}
# 					$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

# bonus:			${LIBFT} ${NAME_BONUS}

# ${NAME_BONUS}:
# 				${CC} ${SRCS_BONUS} ${LIBFT} ${FLAGS} ${MLX_FLAGS} ${NAME_BONUS}

# ${LIBFT}:
# 				make bonus -C Libft

# clean:
# 				$(MAKE) clean -C ./libft
# 				$(RM)	$(OBJ)  $(BOBJ)

# fclean:			clean
# 				$(MAKE) fclean -C ./libft
# 				$(RM)	$(NAME)


# re:				fclean all

# rebonus:		fclean ${NAME_BONUS}

# run:			${NAME}
# 				${VALGRIND} ./${NAME} assets/maps/valid/map4.ber

# run_bonus:		${NAME_BONUS}
# 				${VALGRIND} ./${NAME_BONUS} assets/maps/valid/bonus/map5.ber


#all: $(NAME)
#
#$(NAME): $(OBJS)  $(LIBFT)
#	mkdir -p $(OBJS_DIR)
#	cc $(CFLAGS) -L$(MLXLIB_DIR) $(MLXFLAGS) $(LIBFT) $(OBJS) -o $@
#
#$(LIBFT):
#	$(MAKE) bonus -C $(LIBFT_DIR)
#
#$(MLXLIB):
#	$(MAKE) -C $(MLXLIB_DIR)
#
#$(BONUS_SRCS_DIR)%.o: $(BONUS_SRCS_DIR)%.c $(HEADERS)
#	cc $(CFLAGS) -I. -c $< -o $@
#