/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:50:56 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/16 22:49:42 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

//	coin_list_anim(game, &game->tcoin);
//	coin_list_anim_map(game, &game->tcoin, &game->mapcoin);
//	d_a_l(game, &game->tspikes, 1, 2);
//	d_a_l(game, &game->twalk, 3, 5);
//	draw_walking(game, &game->twalkl, game->play_row, game->play_col - 1, 1);

int	ft_refresh(t_game *game)
{
	game->frame += 1;
	if (game->inv_n_coins == 0)
		game->exit_open = 1;
	player_moves(game);
	draw_exit(game, &game->texit, game->wind.exit_y, game->wind.exit_x);
	draw_goo_d(game, &game->tgoode);
	goo_anim_map(game, &game->tgoo, &game->mapgoo);
	spikes_anim_map(game, &game->tspikes, &game->mapspikes);
	draw_idle_p(game, game->play_row, game->play_col, 3);
	coin_list_anim_map(game, &game->tcoin, &game->mapcoin);
	return (1);
}
//
//void	coin_list_anim(t_game *game, t_imglist **imglist)
//{
//	void	*coin;
//	int		h;
//	int		w;
//
//	if (game->frame % 5 == 0 && game->coin_delay <= 45)
//	{
//		coin = mlx_xpm_file_to_image(game->mlx_ptr,
//				(*imglist)->content, &h, &w);
//		mlx_put_image_to_window(game->mlx_ptr, game->mlx_window,
//			coin, 1 * CELL, 1 * CELL);
//		rotate(imglist);
//	}
//	game->coin_delay++;
//	if (game->coin_delay == 200)
//		game->coin_delay = 0;
//}
