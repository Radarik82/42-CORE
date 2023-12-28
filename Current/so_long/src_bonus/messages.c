/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:50:56 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/14 18:43:32 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

int	ft_error_msg(char *msg, t_game *game)
{
	game->map_alloc = 0;
	ft_printf(RED"Error\n"GREY"%s\n"RESET, msg);
	exit (EXIT_FAILURE);
}

void	ft_quit(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->mlx_window);
	free(game->mlx_ptr);
	ft_printf(GREY"Shutting down...\n"RESET);
	exit (EXIT_SUCCESS);
}

int	ft_exit_game(t_game *game)
{
	ft_printf(RED"QUITTER\n"GREY"\n"RESET);
	ft_quit(game);
	return (0);
}

void	ft_finish_game(t_game *game, int col, int row)
{
	ft_printf("You moved %i times.\n", game->moves);
	ft_tile_draw(game, game->wind.wall_0, col, row);
	ft_printf(RED"SUCCESS\n"GREY"\n"RESET);
	ft_quit(game);
}
