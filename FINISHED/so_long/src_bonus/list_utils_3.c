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

#include "so_long.h"

t_imglist	*so_lstnew(char *content)
{
	t_imglist	*elem;

	elem = malloc(sizeof(t_imglist));
	if (elem == NULL)
		return (NULL);
	elem->content = ft_strdup(content);
	elem->next = NULL;
	return (elem);
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
