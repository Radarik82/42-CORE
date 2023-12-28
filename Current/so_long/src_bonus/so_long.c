/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:50:56 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/16 22:06:46 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

void	ft_map_input_check(t_game *game)
{
	int	name_len;

	game->map_alloc = 0;
	name_len = ft_strlen(game->game_argv[1]);
	if (game->game_argc > 2)
		ft_error_msg("Too many arguments. Yes, only ONE map)", game);
	if (game->game_argc < 2)
		ft_error_msg("The Map file is missing.", game);
	if (!ft_strnstr(&game->game_argv[1][name_len - 4], ".ber", 4))
		ft_error_msg("Map file extention is wrong (It should be .ber).", game);
}

void	ft_init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_error_msg("Game no init", game);
	game->mlx_window = mlx_new_window(game->mlx_ptr, game->map_first_row * CELL,
			game->map_rows * CELL, "Scary Wolfsburg");
	ft_texture(game);
	ft_draw_map1(game);
	ft_start_gameplay(game);
	mlx_loop(game->mlx_ptr);
}

void	ft_start_gameplay(t_game *game)
{
	game->moves = 1;
	game->frame = 0;
	mlx_hook(game->mlx_window, 17, 0, ft_exit_game, game);
	mlx_hook(game->mlx_window, 2, 1, ft_keyboard, game);
	mlx_loop_hook(game->mlx_ptr, ft_refresh, game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	ft_struct_ini(&game);
	game->game_argc = argc;
	game->game_argv = argv;
	ft_map_input_check(game);
	ft_init_map(game);
	ft_init_game(game);
}
