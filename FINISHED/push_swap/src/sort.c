/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:21:12 by ariazano          #+#    #+#             */
/*   Updated: 2023/10/04 14:32:23 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// push all elements A to B, except three last
static void	push_all_but_three(t_arg **a, t_arg **b)
{
	int	size;
	int	pushed;
	int	i;

	size = is_stack_size(*a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(a, b);
		pushed++;
	}
}

/* shift stack a until the lowest value is at the top */
static void	shift_stack(t_arg **a)
{
	int	lowest_pos;
	int	size;

	size = is_stack_size(*a);
	lowest_pos = get_lowest_index_position(*a);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			rra(a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(a);
			lowest_pos--;
		}
	}
}

/* sort more than 3 arguments */
void	sort(t_arg **a, t_arg **b)
{
	push_all_but_three(a, b);
	sort_3(a);
	while (*b)
	{
		get_target_pos(a, b);
		get_cost(a, b);
		cheapest_move(a, b);
	}
	if (!is_sorted(*a))
		shift_stack(a);
}
