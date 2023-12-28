/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:02:41 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/14 18:57:15 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

// mooooore than 25 lines

void	ft_struct_ini(t_game **game)
{
	(*game) = ft_calloc(1, sizeof(t_game));
	if ((*game) == NULL)
		return ;
	(*game)->play.play_idle_0 = NULL;
	(*game)->play.play_down = NULL;
	(*game)->play.play_left = NULL;
	(*game)->play.play_rigth = NULL;
	(*game)->play.coin = NULL;
	(*game)->play.exit_open = NULL;
	(*game)->play.exit_close = NULL;
	(*game)->play.play_idle_0 = NULL;
	(*game)->play.play_idle_1 = NULL;
	(*game)->play.play_idle_2 = NULL;
	(*game)->play.play_idle_3 = NULL;
	(*game)->play.play_idle_4 = NULL;
	(*game)->play.play_idle_5 = NULL;
	(*game)->play.play_run_0 = NULL;
	(*game)->play.play_run_1 = NULL;
	(*game)->play.play_run_2 = NULL;
	(*game)->play.play_run_3 = NULL;
	(*game)->play.play_run_4 = NULL;
	(*game)->play.play_run_5 = NULL;
	struct_ini1(game);
}

void	struct_ini1(t_game **game)
{
	(*game)->exit_closed = 1;
	(*game)->exit_open = 0;
	(*game)->wind.play_up = NULL;
	(*game)->wind.play_down = NULL;
	(*game)->wind.play_left = NULL;
	(*game)->wind.play_rigth = NULL;
	(*game)->wind.floor_0 = NULL;
	(*game)->wind.wall_0 = NULL;
	(*game)->wind.exit_open = NULL;
	(*game)->wind.exit_close = NULL;
	(*game)->map_full = NULL;
	(*game)->map_copy = NULL;
	(*game)->map_tmp = NULL;
	(*game)->game_argv = NULL;
	(*game)->mlx_ptr = NULL;
	(*game)->mlx_window = NULL;
	(*game)->coin.coin = NULL;
//	(*game)->coin.coin_0 = NULL;
//	(*game)->coin.coin_1 = NULL;
//	(*game)->coin.coin_2 = NULL;
//	(*game)->coin.coin_3 = NULL;
//	(*game)->coin.coin_4 = NULL;
//	(*game)->coin.coin_5 = NULL;
	(*game)->tspikes = NULL;
	(*game)->exit_opened = 0;
	(*game)->coin_delay = 0;
	(*game)->goo_death = 0;
	(*game)->stepped_in_goo = 0;
	(*game)->direction = 0;
//	(*game)->mapspikes = enemy_first_node(1);
//	(*game)->mapcoin = enemy_first_node(1);
//	(*game)->mapgoo = enemy_first_node(1);
//	(*game)->maptroll = enemy_first_node(1);
}
