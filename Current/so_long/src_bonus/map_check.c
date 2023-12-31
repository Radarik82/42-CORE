/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:41:26 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/14 18:17:36 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

// checking paths to all coins and at least one exit
int	filler(t_game *game, int j, int i)
{
	if (game->inv_n_coin_check == 0 && game->exit_found)
		return (1);
	if (game->map_copy[i][j] == COIN)
		game->inv_n_coin_check--;
	if (game->map_copy[i][j] == EXIT)
		game->exit_found = 1;
	if (game->map_copy[i][j] != WALL && game->map_copy[i][j]
		!= EXIT && game->map_copy[i][j] != '-' && game->map_copy[i][j] != GOO
			&& game->map_copy[i][j] != SPIKES)
	{
		game->map_copy[i][j] = '-';
		if (j > 0)
			filler(game, j - 1, i);
		if (i < (game->map_first_row - 1))
			filler(game, j + 1, i);
		if (i > 0)
			filler(game, j, i - 1);
		if (i < (game->map_rows - 1))
			filler(game, j, i + 1);
	}
	return (0);
}

// check the wall around
void	ft_check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game && i < game->map_rows)
	{
		j = 0;
		while (game && j < game->map_first_row)
		{
			if (game && (i == 0 || j == 0 || i == game->map_rows - 1
					|| j == game->map_first_row - 1))
			{
				if (game->map_full && game->map_full[i]
					&& game->map_full[i][j] != WALL)
					ft_error_msg("Wall is not intact", game);
			}
			j++;
		}
		i++;
	}
	ft_check_map_obj(game);
	ft_check_total(game);
}

// check all of map objects
void	ft_check_map_obj(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_first_row)
		{
			if (game->map_full[i][j] == PLAY)
				ft_pos_player(game, i, j);
			else if (game->map_full[i][j] == EMPTY)
				game->inv_n_empty++;
			else if (game->map_full[i][j] != WALL)
				check_map_1(game, i, j);
			j++;
		}
		i++;
	}
}

void	check_map_1(t_game *game, int i, int j)
{
	if (game->map_full[i][j] == COIN)
		alloc_coins(game, i, j);
	else if (game->map_full[i][j] == EXIT)
		alloc_exit(game, i, j);
	else if (game->map_full[i][j] == SPIKES)
		alloc_spikes(game, i, j);
	else if (game->map_full[i][j] == GOO)
		alloc_goo(game, i, j);
	else
		game->invalid_char++;
}

void	ft_check_total(t_game *game)
{
	if (game->inv_n_players != 1)
		ft_error_msg("There can be only ONE!!", game);
	if (game->inv_n_coins < 1)
		ft_error_msg("No Money - No honey", game);
	if (game->inv_n_exits != 1)
		ft_error_msg("1000000 paths. They all point to certain death.", game);
	if (game->invalid_char != 0)
		ft_error_msg("Unidentified symbol found", game);
	game->inv_n_coin_check = game->inv_n_coins;
	filler(game, game->play_col, game->play_row);
	if (!(game->inv_n_coin_check == 0 && game->exit_found))
		ft_error_msg("1000000 paths. They all point to certain death.", game);
}
