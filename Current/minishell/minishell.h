/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:43:33 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/14 18:56:23 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

// COLORS
# define GREEN	"\033[0;32m"
# define RED	"\033[1;31m"
# define GREY	"\033[0;90m"
# define CYAN	"\033[1;96m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[1;34m"
# define RESET	"\033[0m"

// Keys
# define ESC 53
# define W 13
# define UP 12_
# define A 0
# define LEFT 123
# define S 1
# define DOWN 125
# define D 2
# define RIGHT 124
# define RESTART 35


// types of token |  &  ;  <  >  (  )  $  `  \  "  '  <space>  <tab>  <newline>
typedef enum e_token_type
{
	T_NEWLINE,
	T_SPACE,
	T_DOLLAR,
	T_AMPER,
	T_TAB,
	T_APPEND,
	T_PIPE,
	T_OR,
	T_AND,
	T_DELIM,
	T_LPAR,
	T_RPAR,
//	T_WORD = 1,
//	T_RED_INP,
//	T_RED_OUT,
//	T_THREE_IN,
//	T_THREE_OUT,
//	T_IN_OUT,
}			t_token_type;





typedef struct	s_data
{
	int		argc;
	char	**argv;
	char	*env;
}				t_data;

typedef struct	s_token
{
	t_token_type	type;
	char			*word;
	struct s_token	*next;
	struct s_token	*prev;
}				t_token;












#endif