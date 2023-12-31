/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_ini.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:50:56 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/16 23:45:10 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

void	ft_texture5(t_game *game)
{
	t_to_list(&game->twalk, "rscs/textures/right_14.xpm");
	t_to_list(&game->twalk, "rscs/textures/right_15.xpm");
	t_to_list(&game->twalk, "rscs/textures/right_16.xpm");
	t_to_list(&game->twalk, "rscs/textures/right_17.xpm");
	t_to_list(&game->twalk, "rscs/textures/right_18.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_01.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_02.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_03.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_04.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_05.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_06.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_07.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_08.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_09.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_10.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_11.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_12.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_13.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_14.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_15.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_16.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_17.xpm");
	t_to_list(&game->twalkl, "rscs/textures/left_18.xpm");
	t_to_list(&game->tidle, "rscs/textures/play_idle_r0.xpm");
	ft_texture6(game);
}

void	ft_texture6(t_game *game)
{
	t_to_list(&game->tidle, "rscs/textures/play_idle_r1.xpm");
	t_to_list(&game->tidle, "rscs/textures/play_idle_r2.xpm");
	t_to_list(&game->tidle, "rscs/textures/play_idle_r3.xpm");
	t_to_list(&game->tidle, "rscs/textures/play_idle_r4.xpm");
	t_to_list(&game->tidle, "rscs/textures/play_idle_r5.xpm");
	t_to_list(&game->tidlel, "rscs/textures/play_idle_0.xpm");
	t_to_list(&game->tidlel, "rscs/textures/play_idle_1.xpm");
	t_to_list(&game->tidlel, "rscs/textures/play_idle_2.xpm");
	t_to_list(&game->tidlel, "rscs/textures/play_idle_3.xpm");
	t_to_list(&game->tidlel, "rscs/textures/play_idle_4.xpm");
	t_to_list(&game->tidlel, "rscs/textures/play_idle_5.xpm");
}
