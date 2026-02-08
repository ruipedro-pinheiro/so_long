/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/29 10:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>

# define TILE_SIZE 128
# define MAX_WIN_W 1280
# define MAX_WIN_H 720
# define MSG_WIN "You escaped! Moves: "
# define MSG_LOSE "Game Over! You died!"
# define ANIM_SPEED 150000
# define ENEMY_SPEED 500000
# define MAX_ENEMIES 50
# define DIR_DOWN 0
# define DIR_UP 1
# define DIR_LEFT 2
# define DIR_RIGHT 3

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_enemy
{
	t_pos	pos;
	int		dir;
	int		active;
}			t_enemy;

typedef struct s_anim
{
	void	*frames[4];
	int		current;
	int		count;
	long	last_update;
}			t_anim;

typedef struct s_img
{
	void	*ground;
	void	*wall;
	void	*collect;
	void	*exit_open;
	void	*exit_closed;
	t_anim	player;
	t_anim	enemy;
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
	t_enemy	enemies[MAX_ENEMIES];
	int		enemy_count;
	int		moves;
	int		game_over;
	int		player_dir;
	long	last_enemy_move;
}			t_game;

/* main_bonus.c */
int			main(int argc, char **argv);

/* init_bonus.c */
int			init_game(t_game *game, char *map_file);
void		init_map_struct(t_map *map);

/* map_parse_bonus.c */
int			parse_map(t_game *game, char *file);
int			read_map_file(char *file, char **content);
int			count_lines(char *content);
int			check_rectangular(t_map *map);

/* map_validate_bonus.c */
int			validate_map(t_map *map);
int			check_walls(t_map *map);
int			check_characters(t_map *map);
int			count_elements(t_map *map);

/* map_pathfind_bonus.c */
int			check_valid_path(t_map *map);
char		**copy_map(char **grid, int height);
void		flood_fill(char **grid, int x, int y, t_map *map);
int			check_flood_result(char **grid, t_map *map);

/* sprites_bonus.c */
int			load_sprites(t_game *game);
int			load_sprite(t_game *game, void **img, char *path);
void		destroy_sprites(t_game *game);
int			load_anim(t_game *game, t_anim *anim, char *base, int count);

/* render_bonus.c */
int			render(t_game *game);
void		render_tile(t_game *game, int x, int y);
void		render_player(t_game *game);
void		render_ui(t_game *game);
void		put_img_cam(t_game *game, void *img, int x, int y);

/* player_bonus.c */
int			handle_keypress(int keysym, t_game *game);
void		move_player(t_game *game, int dx, int dy);
int			can_move(t_game *game, int x, int y);
void		check_tile(t_game *game, int x, int y);

/* game_bonus.c */
int			close_game(t_game *game);
void		win_game(t_game *game);
void		lose_game(t_game *game);
long		get_time_ms(void);
void		update_camera(t_game *game);

/* cleanup_bonus.c */
void		free_map(char **map);
void		cleanup_game(t_game *game);

/* error_bonus.c */
int			error_msg(char *msg);
int			error_exit(t_game *game, char *msg);

/* utils_bonus.c */
int			ft_strcmp(const char *s1, const char *s2);
int			check_extension(char *file, char *ext);
char		*ft_strjoin_free(char *s1, char *s2);

/* enemy_bonus.c */
void		init_enemies(t_game *game);
void		update_enemies(t_game *game);
void		render_enemies(t_game *game);
int			check_enemy_collision(t_game *game);

/* animation_bonus.c */
void		update_animations(t_game *game);
void		*get_current_frame(t_anim *anim);

#endif
