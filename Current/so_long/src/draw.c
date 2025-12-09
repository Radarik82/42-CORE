/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:50:56 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/14 19:46:35 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	t_a(t_game *game, void **img, char *path)
{
	int		w;
	int		h;

	*img = mlx_xpm_file_to_image(game->mlx_ptr, path, &h, &w);
	if (*img == NULL)
		ft_error_msg("Image problem", game);
}

void	ft_tile_draw(t_game *game, void *img, int w, int h)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_window,
		img, h * CELL, w * CELL);
	if (img == NULL)
		ft_error_msg("Image print problem", game);
}

int	ft_draw_map1(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map_full[row])
	{
		col = 0;
		while (game->map_full[row][col])
		{
			ft_draw_map(game, row, col);
			col++;
		}
		row++;
	}
	return (0);
}

int	ft_draw_map(t_game *game, int row, int col)
{
	if (game->map_full[row][col] == EXITING)
		ft_finish_game(game, row, col);
	if (game->map_full[row][col] == EMPTY)
		ft_tile_draw(game, game->wind.floor_0, row, col);
	if (game->map_full[row][col] == COIN)
	{
		ft_tile_draw(game, game->wind.floor_0, row, col);
		ft_tile_draw(game, game->coin.coin, row, col);
	}
	if (game->map_full[row][col] == WALL)
		ft_tile_draw(game, game->wind.wall_0, row, col);
	if (game->map_full[row][col] == PLAY)
	{
		ft_tile_draw(game, game->wind.floor_0, row, col);
		ft_tile_draw(game, game->play.play_idle_0, row, col);
	}
	if (game->map_full[row][col] == EXIT && game->inv_n_coins == 0)
		ft_tile_draw(game, game->wind.exit_open, row, col);
	if (game->map_full[row][col] == EXIT && game->inv_n_coins != 0)
		ft_tile_draw(game, game->wind.exit_close, row, col);
	return (1);
}
