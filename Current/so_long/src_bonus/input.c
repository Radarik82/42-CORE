/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:50:56 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/14 19:01:01 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

int	ft_keyboard(int key, t_game *game)
{
	if (game->walking == 0)
	{
		if (key == W || key == UP)
			ft_move_up(game);
		else if (key == A || key == LEFT)
			ft_move_left(game);
		else if (key == S || key == DOWN)
			ft_move_down(game);
		else if (key == D || key == RIGHT)
			ft_move_right(game);
		else if (key == ESC)
			ft_exit_game(game);
	}
	return (1);
}

int	ft_show_moves(t_game *game)
{
	ft_printf("You moved %i times.\n", game->moves);
	game->moves++;
	return (1);
}

int	player_moves(t_game *game)
{
	char	*moves;

	ft_tile_draw(game, game->wind.wall_0, 0, 0);
	mlx_string_put(game->mlx_ptr, game->mlx_window,
		1, 16, 0x00FFFFFF, "Moves: ");
	moves = ft_itoa (game->moves);
	mlx_string_put(game->mlx_ptr, game->mlx_window,
		42, 16, 0x00FF0000, moves);
	free(moves);
	return (0);
}
