/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:52:16 by ariazano          #+#    #+#             */
/*   Updated: 2023/10/04 14:32:07 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// push the top element of src stack to the top of dest stack
static void	push(t_arg **src, t_arg **dest)
{
	t_arg	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

// push top b to a
void	pa(t_arg **a, t_arg **b)
{
	push(b, a);
	ft_putstr("pa\n");
}

// push top a to b
void	pb(t_arg **a, t_arg **b)
{
	push(a, b);
	ft_putstr("pb\n");
}
