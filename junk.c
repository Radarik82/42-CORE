/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:50:56 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/14 18:48:50 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// int ft_no_events(t_game *game)
// {
	
// 	return (0);
// }

	// mlx_clear_window(game->mlx_ptr, game->mlx_window);

// mlx_loop_hook(game->mlx_window, ft_refresh, game);
	// mlx_loop_hook(game->mlx_window, ft_refresh, game);

void print_2d_array(char **array, t_game *game) // убрать потом
{
    for (int i = 0; i < game->map_rows; ++i) 
	{
        for (int j = 0; j < game->map_first_row; ++j) 
		{
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
}


int	cycle_f(t_game *game, void (*f))
{
	int	row;
	int	col;
	row = 0;
	while (game->map_full[row])
	{
		col = 0;
		while (game->map_full[row][col])
		{
			f(t_game *game, )
			col++;
		}
		row++;
	}
	return (0);
}

int	ft_show_moves(t_game *game)
{
	static int	prev_moves = -1;
	int			current_moves;

	current_moves = game->moves;
	if (current_moves != prev_moves)
	{
		ft_printf("You have moved %d times.\n", current_moves);
		prev_moves = current_moves;
	}
	return (1);
}

int	ft_ps_random(void)
{
	static int	seed = 3;

	seed++;
	if (seed > 1000)
		seed = 3;
	return (seed);
}


void func(t_game *game)
{
	cycle_array(game, free_array);
	cycle_array(game, f);
}

void	cycle_array(char **array, int *(f)(t_game *game, int row, int col))
{
	int	row;
	int	col;

	row = 0;
	
	while (game->map_full[row])
	{
		col = 0;
		while (game->map_full[row][col])
		{
			f(game, row, col);
			col++;
		}
		row++;
	}
}

int f(t_game *game, int row, int col)
{
	int	row;
	int	col;

	row = 0;
	while (game->map_full[row])
	{
		col = 0;
		while (game->map_full[row][col])
		{
			game->map_full[row][col] = 0;
			col++;
		}
		row++;
	}
}

int free_array(t_game *game, int row, int col)
{
	int	row;
	int	col;

	row = 0;
	while (game->map_copy[row])
	{
		free(game->map_copy[row]);
		row++;
	}
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map_alloc == 1)
	{
		free_array(game);
		free_array1(game);
		if (game->map_full)
			free(game->map_full);
		if (game->map_copy)
			free(game->map_copy);
	}
}

void	free_array(t_game *game)
{
	int	row;

	row = 0;
	while (game->map_full[row])
	{
		free(game->map_full[row]);
		row++;
	}
}

void	free_array1(t_game *game)
{
	int	row;

	row = 0;
	while (game->map_copy[row])
	{
		free(game->map_copy[row]);
		row++;
	}
}


//    timestamp(game);
//    game->start_time = (((game->t_s * 1000000) + game->t_su) / 10000);
//    timestamp(game);
//    game->current_time = (((game->t_s * 1000000) + game->t_su));
//    printf("time %ld   time1 %ld\n", game->current_time, game->start_time);
//    printf("time %ld   time1 %ld\n", game->t_s, game->t_su);


//void    draw_gooed(t_game *game, int y, int x)
//{
//    if (game->stepped_in_goo = 1)
//    {
//        game->map_full[game->play_row][game->play_col] = EMPTY;
//        ft_draw_map(game, game->play_row, game->play_col);
//        game->play_row += y;
//        game->play_col += x;
//        game->map_full[game->play_row][game->play_col] = GOOED;
//        draw_goo_d(game, &game->tgoode, game->play_row, game->play_col);
//        ft_show_moves(game);
//    }
//}

void print_enemy_list(t_enemy *enemy_list) {
	t_enemy *current = enemy_list;

	while (current != NULL) {
		printf("x: %d, y: %d\n", current->x, current->y);
		current = current->next;
	}
