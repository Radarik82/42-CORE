/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:08:54 by ariazano          #+#    #+#             */
/*   Updated: 2023/10/07 23:42:53 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_arg
{
	int			len;
	int			width;
	int			precision;
	char		flag;
	char		type;
	int			minus;
	int			nul;
	int			space;
	int			hash;
	int			plus;
	int			dash;
	int			fail;
}				t_arg;

void			ft_p_p(unsigned int num, int nulls, int base, t_arg *param);
void			ft_put_minus(t_arg *param);
void			ft_putprefix(t_arg *param);
int				ft_printf(const char *str, ...);
void			ft_parser(const char **str, t_arg *param);
void			ft_processor(t_arg *param, va_list *args);
int				ft_atoi_move(const char **str);
void			ft_putnbr(unsigned num, unsigned base, t_arg *param);
int				ft_numlen(unsigned num, unsigned base);
void			ft_putchar_prn(char c, t_arg *param);
void			ft_putstr_prn(char *str, int strlen, t_arg *param);
int				ft_strlen(char *str);
void			ft_put_width(int numlen, t_arg *param);
void			ft_print_d(unsigned num, unsigned base, t_arg *param);
void			ft_p_d_2(unsigned int n, int len, int nulls, t_arg *param);
void			ft_print_s(char *str, t_arg *param);
void			ft_print_c(char c, t_arg *param);
void			ft_print_p(void *n, t_arg *param);
void			ft_print_p_part2(unsigned long n, t_arg *param, int len);
void			ft_print_x(unsigned int num, unsigned int base, t_arg *param);
void			ft_p_x_2(unsigned int num, int numlen, int nulls, t_arg *param);

#endif
