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


#include "../src_bonus/so_long.h"

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
//	draw_any_list(game, &game->tspikes, 1, 2, 8);
//	draw_any_list(game, &game->tgoo,2, 5);
//	draw_any_list(game, &game->ttroll, 1, 6);
//	draw_any_list(game, &game->tgoode, 1, 6);
//}

void	draw_any_list(t_game *game, t_imglist **imglist, int row, int col, int z)
{
	void	*img;
	int		h;
	int		w;

	if (game->alive == 1)
	{
		if (game->frame % z == 0)
		{
			char *a = (*imglist)->content;
			img = mlx_xpm_file_to_image(game->mlx_ptr, a, &h, &w);
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
//	char	*a;

	if (game->alive == 1)
	{
		if (game->frame % z == 0)
		{
			if (game->direction == 1)
			{
				img = mlx_xpm_file_to_image(game->mlx_ptr, game->tidlel->content, &h, &w);
				rotate(&game->tidlel);
			}
			if (game->direction == 0)
			{
				img = mlx_xpm_file_to_image(game->mlx_ptr, game->tidle->content, &h, &w);
				rotate(&game->tidle);
			}
//			char *a = (*imglist)->content;
//			img = mlx_xpm_file_to_image(game->mlx_ptr, a, &h, &w);
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_window,
									img, col * CELL, row * CELL);

		}
	}
}

void	draw_enemy(t_game *game, t_imglist **imglist, int row, int col)
{
	void	*img;
	int		h;
	int		w;

	ft_tile_draw(game, game->wind.floor_0, row, col);
	if (game->alive == 1)
	{
		if (game->frame % 5 == 0)
		{
			char *a = (*imglist)->content;
			img = mlx_xpm_file_to_image(game->mlx_ptr, a, &h, &w);
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_window,
				img, col * CELL, row * CELL);
			rotate(imglist);
		}
	}
}

void	draw_exit(t_game *game, t_imglist **imglist, int row, int col)
{
	void	*exit;
	int		h;
	int		w;

	if (game->frame % 7 == 0 && game->exit_opened < 26 && game->inv_n_coins == 0) {
		char *a = (*imglist)->content;
		exit = mlx_xpm_file_to_image(game->mlx_ptr, a, &h, &w);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, exit, col * CELL, row * CELL);
		rotate(imglist);
		game->exit_opened++;
	}
}

void	draw_goo_d(t_game *game, t_imglist **imglist)
{
	void	*goo;
	int		h;
	int		w;

	if (game->frame % 6 == 0 && game->goo_death < 29 && game->stepped_in_goo == 1) {
		char *a = (*imglist)->content;
		goo = mlx_xpm_file_to_image(game->mlx_ptr, a, &h, &w);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, goo, game->killed_x * CELL, game->killed_y * CELL);
		rotate(imglist);
		game->goo_death++;
	}
}

void	draw_walking(t_game *game, t_imglist **imglist, int row, int col)
{
	void	*img;
	int		h;
	int		w;
	if (game->alive == 1)
	{
		if (game->frame % 5 == 0)
		{
			char *a = (*imglist)->content;
			img = mlx_xpm_file_to_image(game->mlx_ptr, a, &h, &w);
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_window,
				img, col * CELL, row * CELL);
			rotate(imglist);
		}
	}
}
