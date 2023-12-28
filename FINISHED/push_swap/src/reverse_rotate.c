/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:13:28 by ariazano          #+#    #+#             */
/*   Updated: 2023/10/04 14:32:12 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* bring the bottom element of a stack to the top */
static void	rev_rotate(t_arg **stack)
{
	t_arg	*tmp;
	t_arg	*tail;
	t_arg	*before_tail;

	tail = is_bottom(*stack);
	before_tail = is_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

/* reverse rotate a */
void	rra(t_arg **a)
{
	rev_rotate(a);
	ft_putstr("rra\n");
}

/* reverse rotate b */
void	rrb(t_arg **b)
{
	rev_rotate(b);
	ft_putstr("rrb\n");
}

/* rra and rrb at the same time */
void	rrr(t_arg **a, t_arg **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putstr("rrr\n");
}
