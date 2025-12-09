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

void	ft_texture(t_game *game)
{
	t_a(game, &game->play.play_idle_0, "rscs/textures/play_idle_0.xpm");
	t_a(game, &game->play.play_idle_1, "rscs/textures/play_idle_1.xpm");
	t_a(game, &game->play.play_idle_2, "rscs/textures/play_idle_2.xpm");
	t_a(game, &game->play.play_idle_3, "rscs/textures/play_idle_3.xpm");
	t_a(game, &game->play.play_idle_4, "rscs/textures/play_idle_4.xpm");
	t_a(game, &game->play.play_idle_5, "rscs/textures/play_idle_5.xpm");
	t_a(game, &game->play.play_run_0, "rscs/textures/play_run_0.xpm");
	t_a(game, &game->play.play_run_1, "rscs/textures/play_run_1.xpm");
	t_a(game, &game->play.play_run_2, "rscs/textures/play_run_2.xpm");
	t_a(game, &game->play.play_run_3, "rscs/textures/play_run_3.xpm");
	t_a(game, &game->play.play_run_4, "rscs/textures/play_run_4.xpm");
	t_a(game, &game->wind.wall_0, WALL_0);
	t_a(game, &game->wind.floor_0, "rscs/textures/floor_0.xpm");
	t_a(game, &game->wind.exit_close, "rscs/textures/exit_c_clean.xpm");
	t_a(game, &game->coin.coin, "rscs/textures/chest_0.xpm");
	t_a(game, &game->coin.coin_0, "rscs/textures/chest_0.xpm");
	t_a(game, &game->coin.coin_1, "rscs/textures/chest_1.xpm");
	t_a(game, &game->coin.coin_2, "rscs/textures/chest_2.xpm");
	t_a(game, &game->coin.coin_3, "rscs/textures/chest_3.xpm");
	t_a(game, &game->coin.coin_4, "rscs/textures/chest_4.xpm");
	t_a(game, &game->coin.coin_5, "rscs/textures/chest_5.xpm");
	t_a(game, &game->coin.coin_6, "rscs/textures/chest_6.xpm");
	t_a(game, &game->coin.coin_7, "rscs/textures/chest_7.xpm");
	t_a(game, &game->wind.exiting, WALL_0);
	t_a(game, &game->wind.exit_open, "rscs/textures/exit_open.xpm");
}
