/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:41:26 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/14 18:17:36 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	alloc_exit(t_game *game, int i, int j)
{
	game->inv_n_exits++;
	game->wind.exit_x = j;
	game->wind.exit_y = i;
}

void	alloc_spikes(t_game *game, int i, int j)
{
	game->spikes++;
	e_to_list(&game->mapspikes, i, j);
}

void	alloc_coins(t_game *game, int i, int j)
{
	game->inv_n_coins++;
	e_to_list(&game->mapcoin, i, j);
}

void	alloc_goo(t_game *game, int i, int j)
{
	game->goo++;
	e_to_list(&game->mapgoo, i, j);
}

void	ft_pos_player(t_game *game, int i, int j)
{
	game->inv_n_players++;
	game->play_row = i;
	game->play_col = j;
	game->alive = 1;
}
