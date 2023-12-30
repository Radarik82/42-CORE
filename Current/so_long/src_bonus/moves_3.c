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
