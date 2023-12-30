/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariazano <ariazano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:43:33 by ariazano          #+#    #+#             */
/*   Updated: 2023/12/16 23:42:51 by ariazano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
//# include <sys/time.h>
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
# define GOO 'G'
# define GOOED 'g'
# define SPIKES 'S'
# define SPIKED 's'
# define EXITING 'X'

// Keys
# define ESC 53
# define W 13
# define UP 126
# define A 0
# define LEFT 123
# define S 1
# define DOWN 125
# define D 2
# define RIGHT 124
# define RESTART 35
# define B 46

# define CELL 64

# define WALL_0 "rscs/textures/wall_0.xpm"

typedef struct s_anim
{
	int	frames;
}				t_anim;

typedef struct s_imglist
{
	char				*content;

	struct s_imglist	*next;
}			t_imglist;

typedef struct s_enemy
{
	int					x;
	int					y;
	int					number;
	struct s_enemy		*next;
}				t_enemy;

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
	void	*play_idle_00;
	void	*play_idle_01;
	void	*play_idle_02;
	void	*play_idle_03;
	void	*play_idle_04;
	void	*play_idle_05;
	void	*play_run_0;
	void	*play_run_1;
	void	*play_run_2;
	void	*play_run_3;
	void	*play_run_4;
	void	*play_run_5;
	void	*spiked;
}				t_play;

typedef struct s_coin
{
	void	*coin;
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
	int		exit_x;
	int		exit_y;
//	void	*exit_open_0;
//	void	*exit_open_1;
//	void	*exit_open_2;
//	void	*exit_open_3;
//	void	*exit_open_4;
//	void	*exit_open_5;
//	void	*exit_open_6;
}				t_wind;

typedef struct s_game
{
	int			play_row;
	int			play_col;
	// int			exit_pos_row;
	// int			exit_pos_col;
	char		**map_full;
	char		**map_copy;
	int			map_size;
	int			map_col;
	int			new_lines;
	char		*map_tmp;
	int			map_rows;
	// int			map_gold;
	int			map_exit_access;
	// int			map_npc;
	int			game_argc;
	char		**game_argv;
	int			invalid_char;
	int			inv_n_players;
	int			inv_n_coins;
	int			inv_n_exits;
	int			inv_n_empty;
	int			inv_n_coin_check;
	// int			inv_borders;
	int			map_alloc;
	int			map_fd;
	int			map_first_row;
	int			exit_found;
	int			exit_open;
	int			exit_closed;
	char		buffer[BUFFER_SIZE];
	void		*mlx_ptr;
	void		*mlx_window;
	int			moves;
	int			frame;
	int			n_read;
//	long		t_s;
//	long		t_su;
	int			exit_opened;
	long		start_time;
	long		current_time;
	int			alive;
	int			stepped_in_goo;
	int			enemy;
	int			spikes;
	int			goo;
	int			coin_delay;
	int			spike_delay;
	int			goo_death;
	int			killed_y;
	int			killed_x;
	int			direction;
	int			walking;
	int			deadly;
	int			walked;

	t_play		play;
	t_wind		wind;
	t_anim		anim;
	t_coin		coin;
	t_imglist	*tspikes;
	t_imglist	*texit;
	t_imglist	*tplay_idle;
	t_imglist	*tgoo;
	t_imglist	*play_run;
	t_imglist	*tgoode;
	t_imglist	*tcoin;
	t_imglist	*twalkl;
	t_imglist	*twalk;
	t_imglist	*tidlel;
	t_imglist	*tidle;

	t_enemy		*mapspikes;
	t_enemy		*mapgoo;
	t_enemy		*mapcoin;
}			t_game;

void		ft_map_input_check(t_game *game);
int			ft_error_msg(char *msg, t_game *game);
void		ft_init_map(t_game *game);
void		ft_open_map(t_game *game);
void		ft_map_alloc(t_game *game);
void		ft_check_wall(t_game *game);
void		ft_check_total(t_game *game);
void		ft_check_map_obj(t_game *game);
int			filler(t_game *game, int j, int i);
void		print_2d_array(char **array, t_game *game);
void		ft_pos_player(t_game *game, int i, int j);
void		ft_init_game(t_game *game);
void		t_a(t_game *game, void **img, char *path);
void		ft_texture(t_game *game);
void		ft_map_size(t_game *game);
void		ft_map_size1(t_game *game, int i);
int			ft_draw_map1(t_game *game);
int			ft_draw_map(t_game *game, int col, int row);
void		ft_start_gameplay(t_game *game);
int			ft_exit_game(t_game *game);
void		ft_non_move(int key, t_game *game);
int			ft_keyboard(int key, t_game *game);
void		ft_move_up(t_game *game);
void		ft_move_down(t_game *game);
void		ft_move_left(t_game *game);
void		ft_move_right(t_game *game);
void		ft_move(t_game *game, int x, int y);
void		draw_spiked(t_game *game, int y, int x);
void		draw_exiting(t_game *game, int y, int x);
void		draw_walk(t_game *game, int y, int x);
void		draw_walk_l(t_game *game, int y, int x);
void		draw_walk_r(t_game *game, int y, int x);

int			ft_refresh(t_game *game);
int			ft_show_moves(t_game *game);
void		ft_finish_game(t_game *game, int col, int row);
void		ft_tile_draw(t_game *game, void *img, int w, int h);
void		ft_quit(t_game *game);
void		ft_struct_ini(t_game **game);
void		struct_ini1(t_game **game);
void		coin_anim(t_game *game);
void		exit_open_anim(t_game *game);
void		exit_open_anim(t_game *game);
void		exit_opening(t_game *game);
void		ft_texture1(t_game *game);
void		timestamp(t_game *game);
int			player_moves(t_game *game);
void		t_to_list(t_imglist **list, char *img);
t_imglist	*so_lstlast(t_imglist *lst);
void		so_lstiter(t_imglist *lst, void (*f)(char *));
t_imglist	*so_lstnew(char *content);
void		so_lstadd_back(t_imglist **lst, t_imglist *new);
void		rotate(t_imglist **stack);
void		draw_list(t_game *game, int row, int col);
t_imglist	*is_bottom(t_imglist *stack);
void		t_a_list(t_game *game, t_imglist *imglist, char *path);

void		death_in_spikes(t_game *game, int row, int col);
void		check_map_1(t_game *game, int i, int j);
void		enemy_lstadd_back(t_enemy **lst, t_enemy *new);
void		enemy_lstiter(t_enemy *lst, void (*f)(t_enemy *));
t_enemy		*enemy_lstnew(int x, int y);
t_enemy		*enemy_lstlast(t_enemy *lst);
t_enemy		*enemy_is_bottom(t_enemy *stack);
void		e_to_list(t_enemy **enemy_list, int x, int y);
void		alloc_spikes(t_game *game, int i, int j);
void		alloc_goo(t_game *game, int i, int j);
void		draw_many_spikes(t_game *game);
void		d_a_l(t_game *game, t_imglist **imglist, int row, int col);
void		draw_enemy(t_game *game, t_imglist **imglist, int row, int col);
void		draw_exit(t_game *game, t_imglist **imglist, int row, int col);
void		coin_list_anim(t_game *game, t_imglist **imglist);
void		draw_goo_d(t_game *game, t_imglist **imglist);
void		draw_gooed(t_game *game, int y, int x);
void		kill_in_goo(t_game *game, int y, int x);
void		draw_play(t_game *game, int row, int col);
void		coin_list_anim_map(t_game *game,
				t_imglist **imglist, t_enemy **enemy);
t_enemy		*is_bottom_enemy(t_enemy *stack);
void		rotate_enemy(t_enemy **stack);
void		alloc_coins(t_game *game, int i, int j);
void		coin_collect(t_game *game, int y, int x);
void		free_coin(t_enemy **enemy);
t_enemy		*enemy_first_node(int num);
void		alloc_exit(t_game *game, int i, int j);
void		loop_alloc_coin(t_game *game);
void		goo_anim_map(t_game *game, t_imglist **imglist, t_enemy **enemy);
void		ft_move_side(t_game *game, int y, int x);
void		spikes_anim_map(t_game *game, t_imglist **imglist, t_enemy **enemy);
void		draw_idle_p(t_game *game, int row, int col, int z);
void		spike_delay(t_game *game);
void		draw_walking(t_game *game, t_imglist **imglist, int row, int col);
void		go_anim(t_game *game, int row, int col);
void		go_anim_b(t_game *game, t_imglist **imglist, int row, int col);
void		go_anim_l(t_game *game, t_imglist **imglist, int row, int col);
void		go_anim_r(t_game *game, t_imglist **imglist, int row, int col);



#endif
