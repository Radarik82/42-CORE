/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:35:21 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/28 21:26:21 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// too many functions

void	so_lstadd_back(t_imglist **lst, t_imglist *new)
{
	t_imglist	*last;

	if (!*lst)
	{
		*lst = new;
		(*lst)->next = NULL;
	}
	else if (new)
	{
		last = so_lstlast(*lst);
		last->next = new;
	}
}

void	so_lstiter(t_imglist *lst, void (*f)(char *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}

t_imglist	*so_lstlast(t_imglist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_imglist	*is_bottom(t_imglist *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_enemy	*is_bottom_enemy(t_enemy *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}
