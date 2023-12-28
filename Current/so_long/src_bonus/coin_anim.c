



#include "../src_bonus/so_long.h"

void	coin_list_anim_map(t_game *game, t_imglist **imglist, t_enemy **enemy)
{
	void	*coin;
	int		h;
	int		w;
	int		i;

	i = 0;
	if (game->frame % 5 == 0 && game->coin_delay <= 45)
	{
		while (game->mapcoin && i < game->inv_n_coins)
		{
			coin = mlx_xpm_file_to_image(game->mlx_ptr, (*imglist)->content, &h, &w);
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_window, coin,
									game->mapcoin->y * CELL, game->mapcoin->x * CELL);
			if (game->mapcoin->next != NULL)
				rotate_enemy(enemy);
			i++;
		}
		rotate(imglist);
	}
	game->coin_delay++;
	if (game->coin_delay == 200)
		game->coin_delay = 0;
}

void	coin_collect(t_game *game, int y, int x)
{
	game->map_full[game->play_row + y][game->play_col + x] = '0';
	free_coin(&game->mapcoin);
	game->mapcoin = NULL;
	loop_alloc_coin(game);
}

void	loop_alloc_coin(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->inv_n_coins = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_first_row)
		{
			if (game->map_full[i][j] == COIN)
			{
				alloc_coins(game, i, j);
			}
			j++;
		}
		i++;
	}
}

void	free_coin(t_enemy **enemy)
{
	t_enemy	*current;
	t_enemy	*nextnode;

	current = *enemy;
	while (current != NULL)
	{
		nextnode = current->next;
		free(current);
		current = nextnode;
	}
}
