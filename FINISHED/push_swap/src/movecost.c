/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movecost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:44:16 by ariazano          #+#    #+#             */
/*   Updated: 2023/10/04 14:31:59 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// find element in B with cheapest cost and move to A
void	cheapest_move(t_arg **a, t_arg **b)
{
	t_arg	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move(a, b, cost_a, cost_b);
}

// calculate cost of moving each element of B to correct position in A
void	get_cost(t_arg **a, t_arg **b)
{
	t_arg	*tmp_a;
	t_arg	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *a;
	tmp_b = *b;
	size_a = is_stack_size(tmp_a);
	size_b = is_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}
