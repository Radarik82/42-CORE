/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:47:21 by ariazano          #+#    #+#             */
/*   Updated: 2023/10/04 20:43:51 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_arg
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_arg	*next;
	struct s_arg	*new;
	// struct s_arg	*prev;
	// long			number;
	// long			position;
}				t_arg;

// movecost
void			get_cost(t_arg **a, t_arg **b);
void			cheapest_move(t_arg **a, t_arg **b);

// init
t_arg			*fill_stack_values(char **av);
void			assign_index(t_arg *a, int stack_size);

// swap
// static void		swap(t_arg *stack);
void			sa(t_arg **a);
void			sb(t_arg **b);
void			ss(t_arg **a, t_arg **b);

// push
// static void		push(t_arg **src, t_arg **dest);
void			pa(t_arg **a, t_arg **b);
void			pb(t_arg **a, t_arg **b);

// rotate
// static void		rotate(t_arg **stack);
void			ra(t_arg **a);
void			rb(t_arg **b);
void			rr(t_arg **a, t_arg **b);

// revers rotate
// static void		rev_rotate(t_arg **stack);
void			rrr(t_arg **a, t_arg **b);
void			rra(t_arg **a);
void			rrb(t_arg **b);

// stacking
t_arg			*is_bottom(t_arg *stack);
t_arg			*is_before_bottom(t_arg *stack);
t_arg			*stack_new(int value);
void			add_bottom(t_arg **stack, t_arg *new);
int				is_stack_size(t_arg *stack);

// utils
void			free_stack(t_arg **stack);
void			exit_error(t_arg **a, t_arg **b);
long int		ft_atoi(const char *str);
void			ft_putstr(char *str);
int				nb_abs(int nb);

// Input Check
int				arg_is_number(char *av);
int				have_duplicates(char **av);
int				arg_is_zero(char *av);
int				is_correct_input(char **av);
int				int_handle(char **av);
int				symbol_handle(char **av);
int				zero_handle(char **av);

// input check utils
int				is_digit(char c);
int				is_sign(char c);
int				nbstr_cmp(const char *s1, const char *s2);

// calculate
// static void		get_position(t_arg **stack);
int				get_lowest_index_position(t_arg *stack);
// static int		get_target(t_arg **a, int b_index, int t_index, int t_pos);
void			get_target_pos(t_arg **a, t_arg **b);

// main
int				main(int ac, char **av);
int				is_sorted(t_arg *stack);
int				execute(char **av);
// static void		push_swap(t_arg **a, t_arg **b, int stack_size);

// move
// static void		rev_rotate_both(t_arg **a, t_arg **b,
							// int *cost_a, int *cost_b);
// static void		rotate_both(t_arg **a, t_arg **b, int *cost_a, int *cost_b);
// static void		rotate_a(t_arg **a, int *cost);
// static void		rotate_b(t_arg **b, int *cost);
void			move(t_arg **a, t_arg **b, int cost_a, int cost_b);

// sort_three
// static int		find_highest_index(t_arg *stack);
void			sort_3(t_arg **stack);

// sort
// static void		push_all_but_three(t_arg **a, t_arg **b);
// static void		shift_stack(t_arg **a);
void			sort(t_arg **a, t_arg **b);

#endif