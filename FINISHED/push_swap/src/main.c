/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:53:01 by ariazano          #+#    #+#             */
/*   Updated: 2023/10/04 14:31:48 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// check if stack is sorted
int	is_sorted(t_arg *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// how to sort 
static void	push_swap(t_arg **a, t_arg **b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*a))
		sa(a);
	else if (stack_size == 3)
		sort_3(a);
	else if (stack_size > 3 && !is_sorted(*a))
		sort(a, b);
}

int	free_split(char **split)
{
	while (*split)
	{
		free(*split);
		split++;
	}
	return (0);
}

int	execute(char **av)
{
	t_arg	*a;
	t_arg	*b;
	int		stack_size;

	if (!is_correct_input(av))
		exit_error(NULL, NULL);
	b = NULL;
	a = fill_stack_values(av);
	stack_size = is_stack_size(a);
	assign_index(a, stack_size + 1);
	push_swap(&a, &b, stack_size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

int	main(int ac, char **av)
{
	char	**split;

	if (ac < 2)
		exit_error(NULL, NULL);
	else if (ac > 2)
	{
		av = av + 1;
		execute(av);
	}
	else if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		execute(split);
		free_split(split);
		free(split);
	}
	return (0);
}
