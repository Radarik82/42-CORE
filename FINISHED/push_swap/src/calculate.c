/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:38:22 by ariazano          #+#    #+#             */
/*   Updated: 2023/10/04 14:09:38 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// sets a position to each element of stack in ascend
static void	get_position(t_arg **stack)
{
	t_arg	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

// current position of the element with the lowest index
int	get_lowest_index_position(t_arg *stack)
{
	t_arg	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = stack;
	lowest_index = INT_MAX;
	get_position(&stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

// choose the target position in A for given B. if in A there is an element 
// with bigger index. if NO than puts to smallest index element in A
static int	get_target(t_arg **a, int b_index, int t_index, int t_pos)
{
	t_arg	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_index && tmp_a->index < t_index)
		{
			t_index = tmp_a->index;
			t_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (t_index != INT_MAX)
		return (t_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < t_index)
		{
			t_index = tmp_a->index;
			t_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (t_pos);
}

// sets a target position in stack B to each element of stack A.
void	get_target_pos(t_arg **a, t_arg **b)
{
	t_arg	*tmp_b;
	int		t_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	t_pos = 0;
	while (tmp_b)
	{
		t_pos = get_target(a, tmp_b->index, INT_MAX, t_pos);
		tmp_b->target_pos = t_pos;
		tmp_b = tmp_b->next;
	}
}
