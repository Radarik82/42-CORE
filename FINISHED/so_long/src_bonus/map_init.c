/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:38:22 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/14 18:49:13 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map(t_game *game)
{
	ft_open_map(game);
	close(game->map_fd);
}

void	ft_map_size(t_game *game)
{
	int	i;

	i = 0;
	while (1)
	{
		game->n_read = read(game->map_fd, game->buffer, BUFFER_SIZE);
		if (game->n_read < 0 || game->n_read == 0)
			break ;
		while (i < game->n_read)
		{
			game->new_lines++;
			if (game->buffer[i] == '\n')
			{
				if (game->map_rows == 0)
					game->map_first_row = i - 1;
				if (game->map_rows > 0)
					if ((game->new_lines - 2) != game->map_first_row)
						ft_error_msg("Nice try! Map incorrect", game);
				game->map_rows++;
				game->new_lines = 0;
			}
			i++;
		}
	}
	ft_map_size1(game, i);
}

void	ft_map_size1(t_game *game, int i)
{
	game->map_rows++;
	if ((i + 2) - (((game->map_first_row + 2) * game->map_rows)) != 0)
		ft_error_msg("Map is wrong.", game);
}

void	ft_open_map(t_game *game)
{
	game->map_fd = open(game->game_argv[1], O_RDONLY);
	if (game->map_fd == -1)
		ft_error_msg("Cannot open the map. Please check the file...", game);
	ft_map_size(game);
	close(game->map_fd);
	if (!game->map_rows || game->map_rows < 3 || game->map_first_row < 3)
	{
		ft_error_msg("Map is wrong", game);
		close(game->map_fd);
		free(game);
	}
	ft_map_alloc(game);
	ft_check_wall(game);
}

void	ft_map_alloc(t_game *game)
{
	char	*line_tmp;
	int		i;

	i = 0;
	game->map_full = (char **)malloc((game->map_rows + 1) * sizeof(char *));
	game->map_copy = (char **)malloc((game->map_rows + 1) * sizeof(char *));
	if (game->map_full == NULL || game->map_copy == NULL)
		ft_error_msg("Cannot open the map. Please check the file...", game);
	game->map_full[game->map_rows] = NULL;
	game->map_copy[game->map_rows] = NULL;
	game->map_fd = open(game->game_argv[1], O_RDONLY);
	while (i < game->map_rows)
	{
		line_tmp = get_next_line(game->map_fd);
		game->map_full[i] = line_tmp;
		game->map_copy[i] = ft_strdup(line_tmp);
		i++;
	}
	game->map_alloc = 1;
	close(game->map_fd);
}
