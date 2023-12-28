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

void	ft_texture(t_game *game)
{
	t_a(game, &game->play.play_idle_0, "rscs/textures/play_idle_0.xpm");
	t_a(game, &game->play.play_idle_1, "rscs/textures/play_idle_1.xpm");
	t_a(game, &game->play.play_idle_2, "rscs/textures/play_idle_2.xpm");
	t_a(game, &game->play.play_idle_3, "rscs/textures/play_idle_3.xpm");
	t_a(game, &game->play.play_idle_4, "rscs/textures/play_idle_4.xpm");
	t_a(game, &game->play.play_idle_5, "rscs/textures/play_idle_5.xpm");
	t_a(game, &game->play.play_idle_00, "rscs/textures/play_idle_r0.xpm");
	t_a(game, &game->play.play_idle_01, "rscs/textures/play_idle_r1.xpm");
	t_a(game, &game->play.play_idle_02, "rscs/textures/play_idle_r2.xpm");
	t_a(game, &game->play.play_idle_03, "rscs/textures/play_idle_r3.xpm");
	t_a(game, &game->play.play_idle_04, "rscs/textures/play_idle_r4.xpm");
	t_a(game, &game->play.play_idle_05, "rscs/textures/play_idle_r5.xpm");
	t_a(game, &game->play.play_run_0, "rscs/textures/play_run_0.xpm");
	t_a(game, &game->play.play_run_1, "rscs/textures/play_run_1.xpm");
	t_a(game, &game->play.play_run_2, "rscs/textures/play_run_2.xpm");
	t_a(game, &game->play.play_run_3, "rscs/textures/play_run_3.xpm");
	t_a(game, &game->play.play_run_4, "rscs/textures/play_run_4.xpm");
	t_a(game, &game->play.play_run_5, "rscs/textures/play_run_5.xpm");

	t_a(game, &game->wind.wall_0, WALL_0);
	t_a(game, &game->wind.floor_0, "rscs/textures/floor_0.xpm");
	t_a(game, &game->wind.exit_close, "rscs/textures/exit_c_clean.xpm");
	t_a(game, &game->coin.coin, "rscs/textures/chest_0.xpm");
	t_a(game, &game->wind.exiting, WALL_0);
	t_a(game, &game->wind.exit_open, "rscs/textures/exit_open.xpm");
	ft_texture1(game);
}

void	ft_texture1(t_game *game)
{
//	t_a(game, &game->wind.exit_open_0, "rscs/textures/play_run_0.xpm");
//	t_a(game, &game->wind.exit_open_1, "rscs/textures/play_run_1.xpm");
//	t_a(game, &game->wind.exit_open_2, "rscs/textures/play_run_2.xpm");
//	t_a(game, &game->wind.exit_open_3, "rscs/textures/play_run_3.xpm");
//	t_a(game, &game->wind.exit_open_4, "rscs/textures/play_run_4.xpm");
//	t_a(game, &game->wind.exit_open_5, "rscs/textures/play_run_5.xpm");
	t_a(game, &game->play.spiked, "rscs/textures/death_in_spike.xpm");
	t_a(game, &game->play.spiked, "rscs/textures/spiked.xpm");

//	t_to_list(&game->tspikes, "rscs/textures/spike_0.xpm");
	t_to_list(&game->tspikes, "rscs/textures/spike_1.xpm");
	t_to_list(&game->tspikes, "rscs/textures/spike_2.xpm");
	t_to_list(&game->tspikes, "rscs/textures/spike_3.xpm");
	t_to_list(&game->tspikes, "rscs/textures/spike_4.xpm");
	t_to_list(&game->tspikes, "rscs/textures/spike_5.xpm");
	t_to_list(&game->tspikes, "rscs/textures/spike_6.xpm");
	t_to_list(&game->tspikes, "rscs/textures/spike_7.xpm");
	t_to_list(&game->tspikes, "rscs/textures/spike_8.xpm");
	t_to_list(&game->tspikes, "rscs/textures/spike_9.xpm");
	t_to_list(&game->tspikes, "rscs/textures/spike_0.xpm");


	t_to_list(&game->tgoo, "rscs/textures/goo_idle_0.xpm");
	t_to_list(&game->tgoo, "rscs/textures/goo_idle_1.xpm");
	t_to_list(&game->tgoo, "rscs/textures/goo_idle_2.xpm");
	t_to_list(&game->tgoo, "rscs/textures/goo_idle_3.xpm");
	t_to_list(&game->tgoo, "rscs/textures/goo_idle_4.xpm");
	t_to_list(&game->tgoo, "rscs/textures/goo_idle_5.xpm");

	t_to_list(&game->texit, "rscs/textures/dor_open_0.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_1.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_2.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_3.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_4.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_5.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_6.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_7.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_8.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_9.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_10.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_11.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_12.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_13.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_14.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_15.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_16.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_17.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_18.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_19.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_20.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_21.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_22.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_23.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_24.xpm");
	t_to_list(&game->texit, "rscs/textures/dor_open_25.xpm");

	t_to_list(&game->tcoin, "rscs/textures/chest_0.xpm");
	t_to_list(&game->tcoin, "rscs/textures/chest_1.xpm");
	t_to_list(&game->tcoin, "rscs/textures/chest_2.xpm");
	t_to_list(&game->tcoin, "rscs/textures/chest_3.xpm");
	t_to_list(&game->tcoin, "rscs/textures/chest_4.xpm");
	t_to_list(&game->tcoin, "rscs/textures/chest_5.xpm");
	t_to_list(&game->tcoin, "rscs/textures/chest_6.xpm");
	t_to_list(&game->tcoin, "rscs/textures/chest_7.xpm");
	t_to_list(&game->tcoin, "rscs/textures/chest_0.xpm");

	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo1.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo2.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo3.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo4.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo5.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo6.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo7.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo8.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo9.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo10.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo11.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo12.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo13.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo14.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo15.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo16.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo17.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo18.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo19.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo20.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo21.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo22.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo23.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo24.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo25.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo26.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo27.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo28.xpm");
	t_to_list(&game->tgoode, "rscs/textures/dead_in_goo29.xpm");

	t_to_list(&game->twalk, "rscs/textures/right_01.xpm");
	t_to_list(&game->twalk, "rscs/textures/right_02.xpm");
	t_to_list(&game->twalk, "rscs/textures/right_03.xpm");
	t_to_list(&game->twalk, "rscs/textures/right_04.xpm");
	t_to_list(&game->twalk, "rscs/textures/right_05.xpm");
	t_to_list(&game->twalk, "rscs/textures/right_06.xpm");
	t_to_list(&game->twalk, "rscs/textures/right_07.xpm");
	t_to_list(&game->twalk, "rscs/textures/right_08.xpm");
	t_to_list(&game->twalk, "rscs/textures/right_09.xpm");
	t_to_list(&game->twalk, "rscs/textures/right_10.xpm");
	t_to_list(&game->twalk, "rscs/textures/right_11.xpm");
	t_to_list(&game->twalk, "rscs/textures/right_12.xpm");
	t_to_list(&game->twalk, "rscs/textures/right_13.xpm");
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
