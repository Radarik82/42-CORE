/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:50:56 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/14 20:03:01 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

void	ft_move_side(t_game *game, int y, int x)
{
	if (game->map_full[game->play_row + y][game->play_col + x] == SPIKES)
		draw_spiked(game, y, x);
	else if (game->map_full[game->play_row + y][game->play_col + x] == GOO)
		kill_in_goo(game, game->play_row + y, game->play_col + x);
	else if (game->map_full[game->play_row + y][game->play_col + x] == EXIT
			 && game->inv_n_coins == 0)
		draw_exiting(game, y, x);
	else if (game->map_full[game->play_row + y][game->play_col + x] != WALL
			 && game->map_full[game->play_row + y][game->play_col + x] != EXIT
			 && game->direction == 0)
		draw_walk_l(game, y, x - 1);
	else if (game->map_full[game->play_row + y][game->play_col + x] != WALL
			 && game->map_full[game->play_row + y][game->play_col + x] != EXIT
			 && game->direction == 1)
		draw_walk_r(game, y, x);
}

void	draw_walk(t_game *game, int y, int x)
{
	game->map_full[game->play_row][game->play_col] = EMPTY;
	ft_draw_map(game, game->play_row, game->play_col);
	game->play_row += y;
	game->play_col += x;
	game->map_full[game->play_row][game->play_col] = PLAY;
	ft_draw_map(game, game->play_row, game->play_col);
	ft_show_moves(game);
}

void	draw_walk_l(t_game *game, int y, int x)
{
	game->map_full[game->play_row][game->play_col] = EMPTY;
	ft_draw_map(game, game->play_row, game->play_col);
//	draw_walking(game, &game->twalkl, game->play_row, game->play_col - 1, 1);
	game->play_row += y;
	game->play_col += x;
	game->map_full[game->play_row][game->play_col] = PLAY;
	ft_draw_map(game, game->play_row, game->play_col);
	ft_show_moves(game);
//	game->walking = 0;
}

void	draw_walk_r(t_game *game, int y, int x)
{
	game->map_full[game->play_row][game->play_col] = EMPTY;
	ft_draw_map(game, game->play_row, game->play_col);
//	d_a_l(game, &game->twalk, game->play_row, game->play_col); // new
	game->play_row += y;
	game->play_col += x;
	game->map_full[game->play_row][game->play_col] = PLAY;
	ft_draw_map(game, game->play_row, game->play_col);
	ft_show_moves(game);
//	game->walking = 0;
}
