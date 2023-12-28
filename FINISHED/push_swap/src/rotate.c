/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:03:52 by ariazano          #+#    #+#             */
/*   Updated: 2023/10/04 14:32:17 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* send the top element of the stack to the bottom */
static void	rotate(t_arg **stack)
{
	t_arg	*tmp;
	t_arg	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = is_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

/* rotate a */
void	ra(t_arg **a)
{
	rotate(a);
	ft_putstr("ra\n");
}

/* rotate b */
void	rb(t_arg **b)
{
	rotate(b);
	ft_putstr("rb\n");
}

/* ra and rb at the same time*/
void	rr(t_arg **a, t_arg **b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}
