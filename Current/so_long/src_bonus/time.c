/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:35:21 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/28 21:26:57 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

void	timestamp(t_game *game)
{
	gettimeofday(&(game->tv), 0);
	game->t_s = game->tv.tv_sec;
	game->t_su = game->tv.tv_usec;
}
