/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:24:03 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/28 01:32:43 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

void	rotate(t_imglist **stack)
{
	t_imglist	*tmp;
	t_imglist	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = is_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	t_to_list(t_imglist **imglist, char *img)
{
	t_imglist	*new_node;

	new_node = so_lstnew(img);
	if (new_node)
		so_lstadd_back(imglist, new_node);
}

void	rotate_enemy(t_enemy **stack)
{
	t_enemy	*head;
	t_enemy	*tail;

	head = *stack;
	*stack = (*stack)->next;
	tail = enemy_lstlast(head);
	tail->next = head;
	head->next = NULL;
}

void	e_to_list(t_enemy **enemy_list, int x, int y)
{
	t_enemy	*new_node;

	new_node = enemy_lstnew(x, y);
	if (new_node)
		enemy_lstadd_back(enemy_list, new_node);
}
