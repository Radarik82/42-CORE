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

void	ft_move(t_game *game, int y, int x)
{
	if (game->map_full[game->play_row + y][game->play_col + x] == SPIKES)
		draw_spiked(game, y, x);
	else if (game->map_full[game->play_row + y][game->play_col + x] == GOO)
		kill_in_goo(game, game->play_row + y, game->play_col + x);
	else if (game->map_full[game->play_row + y][game->play_col + x] == EXIT
			&& game->exit_opened == 25)
		draw_exiting(game, y, x);
	else if (game->map_full[game->play_row + y][game->play_col + x] != WALL
		&& game->map_full[game->play_row + y][game->play_col + x] != EXIT)
		draw_walk(game, y, x);
}

void	ft_move_left(t_game *game)
{
	if (game->alive && game->map_full[game->play_row][game->play_col - 1] != WALL)
	{
		game->direction = 0;
		if (game->map_full[game->play_row][game->play_col - 1] == COIN)
			coin_collect(game, 0, -1);
		if (game->map_full[game->play_row][game->play_col - 1] == GOO)
			game->alive = 0;
		printf("x = %d  y = %d\n", game->play_row, (game->play_col - 1));
		game->walking = 1;
		ft_move_side(game, 0, -1);
	}
}

void	ft_move_right(t_game *game)
{
	if (game->alive && game->map_full[game->play_row][game->play_col + 1] != WALL)
	{
		game->direction = 1;
		if (game->map_full[game->play_row][game->play_col + 1] == COIN)
			coin_collect(game, 0, 1);
		if (game->map_full[game->play_row][game->play_col + 1] == GOO)
			game->alive = 0;
		printf("x = %d  y = %d\n", game->play_row, (game->play_col + 1));
		game->walking = 1;
		ft_move_side(game, 0, 1);
	}
}

void	ft_move_up(t_game *game)
{
	if (game->alive && game->map_full[game->play_row - 1][game->play_col] != WALL)
	{
		if (game->map_full[game->play_row - 1][game->play_col] == COIN)
			coin_collect(game, -1, 0);
		if (game->map_full[game->play_row - 1][game->play_col] == GOO)
			game->alive = 0;
		ft_move(game, -1, 0);
	}
}

void	ft_move_down(t_game *game)
{
	if (game->alive && game->map_full[game->play_row + 1][game->play_col] != WALL)
	{
		if (game->map_full[game->play_row + 1][game->play_col] == COIN)
			coin_collect(game, 1, 0);
		if (game->map_full[game->play_row + 1][game->play_col] == GOO)
			game->alive = 0;
		ft_move(game, 1, 0);
	}
}
