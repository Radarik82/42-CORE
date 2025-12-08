/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:18:11 by ariazano          #+#    #+#             */
/*   Updated: 2023/10/08 00:02:12 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char	*haystack, const char *niddle, size_t n);
int		ft_atoi(const char *str);

void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// ft_printf

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

void	ft_p_p(unsigned int num, int nulls, int base, t_arg *param);
void	ft_put_minus(t_arg *param);
void	ft_putprefix(t_arg *param);
int		ft_printf(const char *str, ...);
void	ft_parser(const char **str, t_arg *param);
void	ft_processor(t_arg *param, va_list *args);
int		ft_atoi_move(const char **str);
void	ft_putnbr_prn(unsigned num, unsigned base, t_arg *param);
int		ft_numlen_prn(unsigned num, unsigned base);
void	ft_putchar_prn(char c, t_arg *param);
void	ft_putstr_prn(char *str, int strlen, t_arg *param);
void	ft_put_width(int numlen, t_arg *param);
void	ft_print_d(unsigned num, unsigned base, t_arg *param);
void	ft_p_d_2(unsigned int n, int len, int nulls, t_arg *param);
void	ft_print_s(char *str, t_arg *param);
void	ft_print_c(char c, t_arg *param);
void	ft_print_p(void *n, t_arg *param);
void	ft_print_p_part2(unsigned long n, t_arg *param, int len);
void	ft_print_x(unsigned int num, unsigned int base, t_arg *param);
void	ft_p_x_2(unsigned int num, int numlen, int nulls, t_arg *param);

#endif