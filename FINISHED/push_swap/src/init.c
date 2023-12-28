/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:43:16 by ariazano          #+#    #+#             */
/*   Updated: 2023/10/04 14:28:13 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// fill a_stack with argument values
t_arg	*fill_stack_values(char **av)
{
	t_arg		*a;
	long int	number;
	int			i;

	a = NULL;
	number = 0;
	i = 0;
	while (av[i])
	{
		number = ft_atoi(av[i]);
		if (number > INT_MAX || number < INT_MIN)
			exit_error(&a, NULL);
		if (i == 0)
			a = stack_new((int)number);
		else
			add_bottom(&a, stack_new((int)number));
		i++;
	}
	return (a);
}

// Assigns an index to each value in stack a
void	assign_index(t_arg *a, int stack_size)
{
	t_arg	*ptr;
	t_arg	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
