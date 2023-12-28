# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 21:41:36 by ariazano          #+#    #+#              #
#    Updated: 2023/10/07 23:43:51 by ariazano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=		ft_printf.c \
				ft_processor.c \
				libft_prn.c \
				ft_printf_d_i_u.c \
				ft_printf_c_s.c \
				ft_printf_p.c \
				ft_printf_x.c
HEADER	=		ft_printf.h
OBJ		= 		$(SRC:.c=.o)
RM		= 		rm -f
NAME	= 		libftprintf.a
FLAGS	=		-Wall -Wextra -Werror

bonus:			all

all:			$(NAME)

$(NAME):		$(OBJ)
				ar rcs	$(NAME) $(OBJ)
clean: 
				$(RM)	$(OBJ)  $(BOBJ)

fclean:			clean
				$(RM)	$(NAME)			
re: 			fclean all

.PHONY: all clean fclean re