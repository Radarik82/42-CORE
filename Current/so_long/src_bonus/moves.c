/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:50:56 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/14 20:03:01 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long.h"

// 5 func already

void	ft_move(t_game *game, int y, int x)
{
	if (game->map_full[game->play_row + y][game->play_col + x] == SPIKES)
		draw_spiked(game, y, x);
	else if (game->map_full[game->play_row + y][game->play_col + x] == GOO)
		kill_in_goo(game, game->play_row + y, game->play_col + x);
	else if (game->map_full[game->play_row + y][game->play_col + x] == EXIT
			&& game->inv_n_coins == 0)
		draw_exiting(game, y, x);
	else if (game->map_full[game->play_row + y][game->play_col + x] != WALL
		&& game->map_full[game->play_row + y][game->play_col + x] != EXIT)
		draw_walk(game, y, x);
}

void	kill_in_goo(t_game *game, int y, int x)
{
	game->map_full[game->play_row][game->play_col] = EMPTY;
	ft_draw_map(game, game->play_row, game->play_col);
	game->stepped_in_goo = 1;
	game->killed_y = y;
	game->killed_x = x;
}

void	draw_spiked(t_game *game, int y, int x)
{
	game->map_full[game->play_row][game->play_col] = EMPTY;
	ft_draw_map(game, game->play_row, game->play_col);
	game->play_row += y;
	game->play_col += x;
	game->map_full[game->play_row][game->play_col] = SPIKED;
	ft_draw_map(game, game->play_row, game->play_col);
	ft_show_moves(game);
}

void	draw_exiting(t_game *game, int y, int x)
{
	game->map_full[game->play_row][game->play_col] = EMPTY;
	ft_draw_map(game, game->play_row, game->play_col);
	game->play_row += y;
	game->play_col += x;
	game->map_full[game->play_row][game->play_col] = EXITING;
	ft_draw_map(game, game->play_row, game->play_col);
	ft_show_moves(game);
}

void	draw_walk(t_game *game, int y, int x)
{
	game->map_full[game->play_row][game->play_col] = EMPTY;
	ft_draw_map(game, game->play_row, game->play_col);
	game->play_row += y;
	game->play_col += x;
	game->map_full[game->play_row][game->play_col] = PLAY;
	ft_draw_map(game, game->play_row, game->play_col);
	ft_show_moves(game);
}

void	ft_move_up(t_game *game)
{
	if (game->alive)
	{
		if (game->map_full[game->play_row - 1][game->play_col] == COIN)
		{
			game->inv_n_coins--;
			coin_collect(game, -1, 0);
		}
		else if (game->map_full[game->play_row - 1][game->play_col] == SPIKES
			|| game->map_full[game->play_row - 1][game->play_col] == TROLL
				|| game->map_full[game->play_row - 1][game->play_col] == GOO)
			game->alive = 0;
		ft_move(game, -1, 0);
	}
}

//void	lstclear_enemy(t_enemy **lst, void (*del)(void *))
//{
//    t_enemy	*tmp;
//    t_enemy	*nextelem;
//
//    if (lst && del)
//    {
//        tmp = *lst;
//        while (tmp)
//        {
//            nextelem = tmp->next;
//            lstdelone_enemy(tmp, del);
//            tmp = nextelem;
//        }
//        *lst = NULL;
//    }
//}
//
//void	lstdelone_enemy(t_enemy *lst, void (*del)(void *))
//{
//    if (lst && del)
//    {
//        del(lst->x);
//        del(lst->y);
//        free(lst);
//    }
//}

void	ft_move_down(t_game *game)
{
	if (game->alive)
	{
		if (game->map_full[game->play_row + 1][game->play_col] == COIN)
		{
			game->inv_n_coins--;
			coin_collect(game, 1, 0);
		}
		else if (game->map_full[game->play_row + 1][game->play_col] == SPIKES
			|| game->map_full[game->play_row + 1][game->play_col] == TROLL
				|| game->map_full[game->play_row + 1][game->play_col] == GOO)
			game->alive = 0;
		ft_move(game, 1, 0);
	}
}

void	ft_move_left(t_game *game)
{
	if (game->alive)
	{
		if (game->map_full[game->play_row][game->play_col - 1] == COIN)
		{
			game->inv_n_coins--;
			coin_collect(game, 0, -1);
		}
		if (game->map_full[game->play_row][game->play_col - 1] == SPIKES
		/*|| game->map_full[game->play_row][game->play_col - 1] == TROLL
		|| game->map_full[game->play_row][game->play_col - 1] == GOO*/)
		{
			game->alive = 0;
		}
			game->direction = 0;
		ft_move(game, 0, -1);
	}
}

void	ft_move_right(t_game *game)
{
	if (game->alive)
	{
		if (game->map_full[game->play_row][game->play_col + 1] == COIN)
		{
			game->inv_n_coins--;
			coin_collect(game, 0, 1);
		}

		else if (game->map_full[game->play_row][game->play_col + 1] == SPIKES
			|| game->map_full[game->play_row][game->play_col + 1] == TROLL
				|| game->map_full[game->play_row][game->play_col + 1] == GOO)
			game->alive = 0;
		game->direction = 1;
		ft_move(game, 0, 1);
	}
}
