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

#include "../src_bonus/so_long.h"

// too many functions

void	t_a(t_game *game, void **img, char *path)
{
	int		w;
	int		h;

	if ((char **)img == NULL)
		ft_error_msg("Image problem", game);
	*img = mlx_xpm_file_to_image(game->mlx_ptr, path, &h, &w);
}

void	ft_tile_draw(t_game *game, void *img, int w, int h)
{
	if ((char *)img == NULL)
		ft_error_msg("Image print problem", game);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_window,
		img, h * CELL, w * CELL);
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
	if (game->map_full[row][col] == SPIKED)
		death_in_spikes(game, game->play_row, game->play_col);
	if (game->map_full[row][col] == EMPTY || game->map_full[row][col] == COIN
		|| game->map_full[row][col] == GOO)
		ft_tile_draw(game, game->wind.floor_0, row, col);
	if (game->map_full[row][col] == WALL)
		ft_tile_draw(game, game->wind.wall_0, row, col);
	if (game->map_full[row][col] == EXIT && game->inv_n_coins != 0)
		ft_tile_draw(game, game->wind.exit_close, row, col);
	return (1);
}

void	death_in_spikes(t_game *game, int row, int col)
{
	ft_tile_draw(game, game->play.spiked, row, col);
}
