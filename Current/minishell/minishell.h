/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:43:33 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/14 18:56:23 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
// # include <X11/X.h>
// # include <X11/keysym.h>
# include "../libft/libft.h"

// COLORS
# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

// MAP legend
# define PLAY 'P'
# define EXIT 'E'
# define COIN 'C'
# define WALL '1'
# define EMPTY '0'
# define EXITING 'X'

// Keys
# define ESC 53
# define W 13
# define UP 12_
# define A 0
# define LEFT 123
# define S 1
# define DOWN 125
# define D 2
# define RIGHT 124
# define RESTART 35

// MLX
// # define WINDOW 1080
# define CELL 64

// Textures
# define WALL_0 "rscs/textures/wall_0.xpm"

typedef struct s_anim
{
	int	frames;
}				t_anim;

typedef struct s_play
{
	void	*play_up;			// textures
	void	*play_down;
	void	*play_left;
	void	*play_rigth;
	void	*coin;
	void	*exit_open;
	void	*exit_close;
	void	*play_idle_0;
	void	*play_idle_1;
	void	*play_idle_2;
	void	*play_idle_3;
	void	*play_idle_4;
	void	*play_idle_5;
	void	*play_run_0;
	void	*play_run_1;
	void	*play_run_2;
	void	*play_run_3;
	void	*play_run_4;
	void	*play_run_5;
}				t_play;

typedef struct s_coin
{
	void	*coin;
	void	*coin_0;
	void	*coin_1;
	void	*coin_2;
	void	*coin_3;
	void	*coin_4;
	void	*coin_5;
	void	*coin_6;
	void	*coin_7;
}				t_coin;

typedef struct s_wind
{
	void	*play_up;	// window
	void	*play_down;
	void	*play_left;
	void	*play_rigth;
	void	*floor_0;
	void	*wall_0;
	void	*exit_open;
	void	*exit_close;
	void	*exiting;
}				t_wind;

typedef struct s_game
{
	int		play_row;
	int		play_col;
	// int		exit_pos_row;
	// int		exit_pos_col;
	char	**map_full;
	char	**map_copy;
	int		map_size;
	int		map_col;
	int		new_lines;
	char	*map_tmp;
	int		map_rows;
	// int		map_gold;
	int		map_exit_access;
	int		map_npc;
	int		game_argc;
	char	**game_argv;
	int		invalid_char;
	int		inv_n_players;
	int		inv_n_ghosts;
	int		inv_n_coins;
	int		inv_n_exits;
	int		inv_n_empty;
	int		inv_n_coin_check;
	// int		inv_borders;
	int		map_alloc;
	int		map_fd;
	int		map_first_row;
	int		exit_found;
	char	buffer[BUFFER_SIZE];
	void	*mlx_ptr;
	void	*mlx_window;
	int		moves;
	int		frame;
	int		n_read;

	t_play	play;
	t_wind	wind;
	t_anim	anim;
	t_coin	coin;
}			t_game;

void	ft_map_input_check(t_game *game);
int		ft_error_msg(char *msg, t_game *game);
void	ft_init_map(t_game *game);
void	ft_open_map(t_game *game);
void	ft_map_alloc(t_game *game);
void	ft_check_wall(t_game *game);
void	ft_check_total(t_game *game);
void	ft_check_map_obj(t_game *game);
int		filler(t_game *game, int j, int i);
void	print_2d_array(char **array, t_game *game);
void	ft_pos_player(t_game *game, int i, int j);
void	ft_init_game(t_game *game);
void	t_a(t_game *game, void **img, char *path);
void	ft_texture(t_game *game);
void	ft_map_size(t_game *game);
void	ft_map_size1(t_game *game, int i);
int		ft_draw_map1(t_game *game);
int		ft_draw_map(t_game *game, int col, int row);
void	ft_start_gameplay(t_game *game);
int		ft_exit_game(t_game *game);
void	ft_non_move(int key, t_game *game);
int		ft_keyboard(int key, t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
int		ft_refresh(t_game *game);
void	ft_move(t_game *game, int x, int y);
int		ft_show_moves(t_game *game);
void	ft_finish_game(t_game *game, int col, int row);
void	ft_tile_draw(t_game *game, void *img, int w, int h);
void	ft_quit(t_game *game);
void	ft_struct_ini(t_game **game);
void	struct_ini1(t_game **game);
void	coin_anim(t_game *game);
void	exit_open_anim(t_game *game);

#endif
