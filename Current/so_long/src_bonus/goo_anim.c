/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goo_anim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 02:05:42 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/28 13:36:01 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

void	goo_anim_map(t_game *game, t_imglist **imglist, t_enemy **enemy)
{
	void	*coin;
	int		h;
	int		w;
	int		i;

	i = 0;
	if (game->frame % 5 == 0 && game->alive == 1)
	{
		while (game->mapgoo && i < game->goo)
		{
			coin = mlx_xpm_file_to_image(game->mlx_ptr, (*imglist)->content, &h, &w);
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, coin,
									game->mapgoo->y * CELL, game->mapgoo->x * CELL);
			if (game->mapgoo->next != NULL)
				rotate_enemy(enemy);
			i++;
		}
		rotate(imglist);
	}
//	game->coin_delay++;
//	if (game->coin_delay == 200)
//		game->coin_delay = 0;
}

void	spikes_anim_map(t_game *game, t_imglist **imglist, t_enemy **enemy)
{
	void	*coin;
	int		h;
	int		w;
	int		i;

	i = 0;
	if (game->frame % 5 == 0 && game->alive == 1 && game->spike_delay <= 50)
	{
		game->deadly = 1;
		while (game->mapspikes && i < game->spikes)
		{
			coin = mlx_xpm_file_to_image(game->mlx_ptr, (*imglist)->content, &h, &w);
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, coin,
									game->mapspikes->y * CELL, game->mapspikes->x * CELL);
			if (game->mapspikes->next != NULL)
				rotate_enemy(enemy);
			i++;
		}
		rotate(imglist);
	}
	spike_delay(game);
}

void	spike_delay(t_game *game)
{
	game->spike_delay++;
	if (game->spike_delay > 51 && game->spike_delay < 300)
		game->deadly = 0;
	if (game->spike_delay == 360)
		game->spike_delay = 0;
}
