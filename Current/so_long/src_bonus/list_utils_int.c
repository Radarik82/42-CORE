/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:41:41 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/28 21:26:28 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

// too many functions

void	enemy_lstadd_back(t_enemy **lst, t_enemy *new)
{
	t_enemy	*last;

	if (!*lst)
	{
		*lst = new;
		(*lst)->next = NULL;
	}
	else if (new)
	{
		last = enemy_lstlast(*lst);
		last->next = new;
	}
}

void	enemy_lstiter(t_enemy *lst, void (*f)(t_enemy *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst);
			lst = lst->next;
		}
	}
}

t_enemy	*enemy_lstnew(int x, int y)
{
	t_enemy	*elem;

	elem = malloc(sizeof(t_enemy));
	if (elem == NULL)
		return (NULL);
	elem->x = x;
	elem->y = y;
	elem->next = NULL;
	return (elem);
}

t_enemy	*enemy_first_node(int num)
{
	t_enemy	*elem;

	elem = malloc(sizeof(t_enemy));
	if (elem == NULL)
		return (NULL);
	elem->number = num;
	elem->next = NULL;
	return (elem);
}

t_enemy	*enemy_lstlast(t_enemy *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_enemy	*enemy_is_bottom(t_enemy *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}
