/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:57:02 by ariazano          #+#    #+#             */
/*   Updated: 2023/10/04 14:33:14 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// swap top 2 elements on stack. do nothing if only 1 or no elements
static void	swap(t_arg *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

/* swap A */
void	sa(t_arg **a)
{
	swap(*a);
	ft_putstr("sa\n");
}

/* swap B */
void	sb(t_arg **b)
{
	swap(*b);
	ft_putstr("sb\n");
}

/* sa and sb at the same tine */
void	ss(t_arg **a, t_arg **b)
{
	swap(*a);
	swap(*b);
	ft_putstr("ss\n");
}
