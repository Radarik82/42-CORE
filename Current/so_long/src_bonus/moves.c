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

// 5 func already

void	ft_move(t_game *game, int y, int x)
{
	if (game->map_full[game->play_row + y][game->play_col + x] == SPIKES)
		draw_spiked(game, y, x);
	else if (game->map_full[game->play_row + y][game->play_col + x] == GOO)
		kill_in_goo(game, game->play_row + y, game->play_col + x);
	else if (game->map_full[game->play_row + y][game->play_col + x] == EXIT
			&& game->inv_n_coins == 0)
		draw_exiting(game, y, x);
	else if (game->map_full[game->play_row + y][game->play_col + x] != WALL
		&& game->map_full[game->play_row + y][game->play_col + x] != EXIT)
		draw_walk(game, y, x);
}

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
		draw_walk_l(game, y, x);
	else if (game->map_full[game->play_row + y][game->play_col + x] != WALL
			 && game->map_full[game->play_row + y][game->play_col + x] != EXIT
			 	&& game->direction == 1)
		draw_walk_r(game, y, x);
}

void	kill_in_goo(t_game *game, int y, int x)
{
	game->map_full[game->play_row][game->play_col] = EMPTY;
	ft_draw_map(game, game->play_row, game->play_col);
	game->stepped_in_goo = 1;
	game->killed_y = y;
	game->killed_x = x;
}

void	draw_spiked(t_game *game, int y, int x)
{
	game->map_full[game->play_row][game->play_col] = EMPTY;
	ft_draw_map(game, game->play_row, game->play_col);
	game->play_row += y;
	game->play_col += x;
	game->map_full[game->play_row][game->play_col] = SPIKED;
	ft_draw_map(game, game->play_row, game->play_col);
	ft_show_moves(game);
}

void	draw_exiting(t_game *game, int y, int x)
{
	game->map_full[game->play_row][game->play_col] = EMPTY;
	ft_draw_map(game, game->play_row, game->play_col);
	game->play_row += y;
	game->play_col += x;
	game->map_full[game->play_row][game->play_col] = EXITING;
	ft_draw_map(game, game->play_row, game->play_col);
	ft_show_moves(game);
}

void	draw_walk_l(t_game *game, int y, int x)
{
	game->map_full[game->play_row][game->play_col] = EMPTY;
	ft_draw_map(game, game->play_row, game->play_col);
	game->play_row += y;
	game->play_col += x;
	game->map_full[game->play_row][game->play_col] = PLAY;
	ft_draw_map(game, game->play_row, game->play_col);
	ft_show_moves(game);
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

void	draw_walk_r(t_game *game, int y, int x)
{
	game->walking = 1;
	game->map_full[game->play_row][game->play_col] = EMPTY;
	ft_draw_map(game, game->play_row, game->play_col);
//	draw_any_list(game, &game->twalk, game->play_row, game->play_col, 2); // new
	game->play_row += y;
	game->play_col += x;
	game->map_full[game->play_row][game->play_col] = PLAY;
	ft_draw_map(game, game->play_row, game->play_col);
	ft_show_moves(game);
	game->walking = 0;
}

void	ft_move_up(t_game *game)
{
	if (game->alive)
	{
		if (game->map_full[game->play_row - 1][game->play_col] == COIN)
			coin_collect(game, -1, 0);
		if (/*game->map_full[game->play_row - 1][game->play_col] == SPIKES
				|| */game->map_full[game->play_row - 1][game->play_col] == GOO)
			game->alive = 0;
		ft_move(game, -1, 0);
	}
}

void	ft_move_down(t_game *game)
{
	if (game->alive)
	{
		if (game->map_full[game->play_row + 1][game->play_col] == COIN)
			coin_collect(game, 1, 0);
		if (game->map_full[game->play_row + 1][game->play_col] == SPIKES
				|| game->map_full[game->play_row + 1][game->play_col] == GOO)
			game->alive = 0;
		ft_move(game, 1, 0);
	}
}

void	ft_move_left(t_game *game)
{
	if (game->alive)
	{
		game->direction = 0;
		if (game->map_full[game->play_row][game->play_col - 1] == COIN)
			coin_collect(game, 0, -1);
		if (/*game->map_full[game->play_row][game->play_col - 1] == SPIKES
			|| */game->map_full[game->play_row][game->play_col - 1] == GOO)
			game->alive = 0;
		ft_move_side(game, 0, -1);
	}
}

void	ft_move_right(t_game *game)
{
	if (game->alive)
	{
		game->direction = 1;
		if (game->map_full[game->play_row][game->play_col + 1] == COIN)
			coin_collect(game, 0, 1);
		if (/*game->map_full[game->play_row][game->play_col + 1] == SPIKES
				|| */game->map_full[game->play_row][game->play_col + 1] == GOO)
			game->alive = 0;
		ft_move_side(game, 0, 1);
	}
}
