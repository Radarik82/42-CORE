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

void	draw_walk_l(t_game *game, int y, int x)
{
	game->walking = 1;
	game->play_row += y;
	game->play_col += x;
	game->map_full[game->play_row][game->play_col] = PLAY;
	game->map_full[game->play_row][game->play_col + 1] = EMPTY;
	ft_draw_map(game, game->play_row, (game->play_col + 1));
	ft_show_moves(game);
}

void	draw_walk_r(t_game *game, int y, int x)
{
	game->walking = 1;
	game->play_row += y;
	game->play_col += x;
	game->map_full[game->play_row][game->play_col] = PLAY;
	game->map_full[game->play_row][game->play_col - 1] = EMPTY;
	ft_draw_map(game, game->play_row, (game->play_col - 1));
	ft_show_moves(game);
}

void	go_anim(t_game *game, int row, int col)
{
	if (game->direction == 0)
		go_anim_l(game, &game->twalkl, row, col);
	else if (game->direction == 1)
		go_anim_r(game, &game->twalk, row, col);
}

void	go_anim_l(t_game *game, t_imglist **imglist, int row, int col)
{
	void	*walk;
	int		h;
	int		w;

	if (game->frame % 1 == 0 && game->alive == 1)
	{
		if (game->walking != 0 && game->walking <= 19)
		{
			walk = mlx_xpm_file_to_image(game->mlx_ptr,
					(*imglist)->content, &h, &w);
			mlx_put_image_to_window(game->mlx_ptr,
				game->mlx_window, walk, col * CELL, row * CELL);
			if ((*imglist)->next != NULL)
				rotate(imglist);
			game->walking++;
		}
		if (game->walking == 19)
			game->walking = 0;
	}
}

void	go_anim_r(t_game *game, t_imglist **imglist, int row, int col)
{
	void	*walk;
	int		h;
	int		w;

	if (game->frame % 1 == 0 && game->alive == 1)
	{
		if (game->walking != 0 && game->walking <= 19)
		{
			walk = mlx_xpm_file_to_image(game->mlx_ptr,
					(*imglist)->content, &h, &w);
			mlx_put_image_to_window(game->mlx_ptr,
				game->mlx_window, walk, (col - 1) * CELL, row * CELL);
			if ((*imglist)->next != NULL)
				rotate(imglist);
			game->walking++;
		}
		if (game->walking == 19)
			game->walking = 0;
	}
}
