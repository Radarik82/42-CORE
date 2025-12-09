/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:18:33 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/28 21:26:01 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//void	draw_list(t_game *game, int row, int col)
//{
//	void	*img;
//	int		h;
//	int		w;
//
//	if (game->alive == 1)
//	{
//		if (game->frame % 5 == 0)
//		{
//			char *a = game->tspikes->content;
//			img = mlx_xpm_file_to_image(game->mlx_ptr, a, &h, &w);
//			mlx_put_image_to_window(game->mlx_ptr, game->mlx_window,
//				img, col * CELL, row * CELL);
//			rotate(&game->tspikes);
//		}
//	}
//}

//void	draw_many_spikes(t_game *game)
//{
//	d_a_l(game, &game->tspikes, 1, 2);
//	d_a_l(game, &game->tgoo,2, 5);
//	d_a_l(game, &game->ttroll, 1, 6);
//	d_a_l(game, &game->tgoode, 1, 6);
//}

void	d_a_l(t_game *game, t_imglist **imglist, int row, int col)
{
	void	*img;
	int		h;
	int		w;

	if (game->alive == 1)
	{
		if (game->frame % 5 == 0)
		{
			img = mlx_xpm_file_to_image(game->mlx_ptr,
					(*imglist)->content, &h, &w);
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_window,
				img, col * CELL, row * CELL);
			rotate(imglist);
		}
	}
}

void	draw_idle_p(t_game *game, int row, int col, int z)
{
	void	*img;
	int		h;
	int		w;

	if (game->frame % 9 == 0 && game->walking == 0 && game->alive == 1)
		ft_tile_draw(game, game->wind.floor_0, row, col);
	if (game->alive == 1 && game->walking == 0 && game->frame % z == 0)
	{
		if (game->direction == 1)
		{
			img = mlx_xpm_file_to_image(game->mlx_ptr,
					game->tidlel->content, &h, &w);
			rotate(&game->tidlel);
		}
		if (game->direction == 0)
		{
			img = mlx_xpm_file_to_image(game->mlx_ptr,
					game->tidle->content, &h, &w);
			rotate(&game->tidle);
		}
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_window,
			img, col * CELL, row * CELL);
	}
}

//void	draw_enemy(t_game *game, t_imglist **imglist, int row, int col)
//{
//	void	*img;
//	int		h;
//	int		w;
//
//	ft_tile_draw(game, game->wind.floor_0, row, col);
//	if (game->alive == 1)
//	{
//		if (game->frame % 5 == 0)
//		{
//			char *a = (*imglist)->content;
//			img = mlx_xpm_file_to_image(game->mlx_ptr, a, &h, &w);
//			mlx_put_image_to_window(game->mlx_ptr, game->mlx_window,
//				img, col * CELL, row * CELL);
//			rotate(imglist);
//		}
//	}
//}

void	draw_exit(t_game *game, t_imglist **imglist, int row, int col)
{
	void	*exit;
	int		h;
	int		w;

	if (game->frame % 7 == 0 && game->exit_opened < 26
		&& game->inv_n_coins == 0)
	{
		exit = mlx_xpm_file_to_image(game->mlx_ptr,
				(*imglist)->content, &h, &w);
		mlx_put_image_to_window(game->mlx_ptr,
			game->mlx_window, exit, col * CELL, row * CELL);
		rotate(imglist);
		game->exit_opened++;
	}
}

void	draw_goo_d(t_game *game, t_imglist **imglist)
{
	void	*goo;
	int		h;
	int		w;

	if (game->frame % 6 == 0 && game->goo_death < 29
		&& game->stepped_in_goo == 1)
	{
		goo = mlx_xpm_file_to_image(game->mlx_ptr, (*imglist)->content, &h, &w);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_window,
			goo, game->killed_x * CELL, game->killed_y * CELL);
		rotate(imglist);
		game->goo_death++;
	}
}

void	draw_walking(t_game *game, t_imglist **imglist, int row, int col)
{
	void	*img;
	int		h;
	int		w;

	game->walked = 0;
	if (game->alive == 1)
	{
		while (game->walked != 18)
		{
			game->walked += 1;
			if (game->frame % 5 == 0)
			{
				img = mlx_xpm_file_to_image(game->mlx_ptr,
						(*imglist)->content, &h, &w);
				mlx_put_image_to_window(game->mlx_ptr,
					game->mlx_window, img, col * CELL, row * CELL);
				rotate(imglist);
			}
		}
	}
}
