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

#include "so_long.h"

// 5 func already

void	ft_move(t_game *game, int y, int x)
{
	if (game->map_full[game->play_row + y][game->play_col + x] != WALL
		&& game->map_full[game->play_row + y][game->play_col + x] != EXIT)
	{
		game->map_full[game->play_row][game->play_col] = EMPTY;
		ft_draw_map(game, game->play_row, game->play_col);
		game->play_row += y;
		game->play_col += x;
		game->map_full[game->play_row][game->play_col] = PLAY;
		ft_draw_map(game, game->play_row, game->play_col);
		ft_show_moves(game);
	}
	else if (game->map_full[game->play_row + y][game->play_col + x] == EXIT
		&& game->inv_n_coins == 0)
	{
		game->map_full[game->play_row][game->play_col] = EMPTY;
		ft_draw_map(game, game->play_row, game->play_col);
		game->play_row += y;
		game->play_col += x;
		game->map_full[game->play_row][game->play_col] = EXITING;
		ft_draw_map(game, game->play_row, game->play_col);
		ft_show_moves(game);
	}
}

void	ft_move_up(t_game *game)
{
	if (game->map_full[game->play_row - 1][game->play_col] == COIN)
		game->inv_n_coins--;
	ft_move(game, -1, 0);
}

void	ft_move_down(t_game *game)
{
	if (game->map_full[game->play_row + 1][game->play_col] == COIN)
		game->inv_n_coins--;
	ft_move(game, 1, 0);
}

void	ft_move_left(t_game *game)
{
	if (game->map_full[game->play_row][game->play_col - 1] == COIN)
		game->inv_n_coins--;
	ft_move(game, 0, -1);
}

void	ft_move_right(t_game *game)
{
	if (game->map_full[game->play_row][game->play_col + 1] == COIN)
		game->inv_n_coins--;
	ft_move(game, 0, 1);
}
