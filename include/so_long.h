/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:28:53 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/29 10:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>

# define TILE_SIZE 128
# define MAX_WIN_W 1280
# define MAX_WIN_H 720
# define MSG_WIN "You escaped! Moves: "

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_img
{
	void	*ground;
	void	*wall;
	void	*player;
	void	*collect;
	void	*exit_open;
	void	*exit_closed;
}			t_img;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		collected;
	int		exit_count;
	int		player_count;
	t_pos	player;
	t_pos	exit;
}			t_map;

typedef struct s_cam
{
	int		x;
	int		y;
	int		w;
	int		h;
}			t_cam;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
	t_cam	cam;
	int		win_w;
	int		win_h;
	int		moves;
	int		game_over;
}			t_game;

/* main.c */
int			main(int argc, char **argv);

/* init.c */
int			init_game(t_game *game, char *map_file);
void		init_map_struct(t_map *map);

/* map_parse.c */
int			parse_map(t_game *game, char *file);
int			read_map_file(char *file, char **content);
int			count_lines(char *content);
int			check_rectangular(t_map *map);

/* map_validate.c */
int			validate_map(t_map *map);
int			check_walls(t_map *map);
int			check_characters(t_map *map);
int			count_elements(t_map *map);

/* map_pathfind.c */
int			check_valid_path(t_map *map);
char		**copy_map(char **grid, int height);
void		flood_fill(char **grid, int x, int y, t_map *map);
int			check_flood_result(char **grid, t_map *map);

/* sprites.c */
int			load_sprites(t_game *game);
int			load_sprite(t_game *game, void **img, char *path);
void		destroy_sprites(t_game *game);

/* render.c */
void		render_map(t_game *game);
void		render_player(t_game *game);
void		render_game(t_game *game);

/* player.c */
int			handle_keypress(int keysym, t_game *game);
void		move_player(t_game *game, int dx, int dy);
int			can_move(t_game *game, int x, int y);
void		check_tile(t_game *game, int x, int y);

/* game.c */
int			close_game(t_game *game);
void		win_game(t_game *game);
void		print_moves(int moves);
void		update_camera(t_game *game);

/* cleanup.c */
void		free_map(char **map);
void		cleanup_game(t_game *game);

/* error.c */
int			error_msg(char *msg);
int			error_exit(t_game *game, char *msg);

/* utils.c */
int			ft_strcmp(const char *s1, const char *s2);
int			check_extension(char *file, char *ext);

#endif
