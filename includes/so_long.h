#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define TILE_SIZE 128
# define PLAYER_H 128

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_ESC 65307

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	int		x;
	int		y;
	int		dir;
	int		frame;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		collected;
	int		exit_x;
	int		exit_y;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_img		grass;
	t_img		wall;
	t_img		collectible;
	t_img		exit_img;
	t_img		player_img[4][4];
	int			moves;
	int			win_state;
}	t_game;

int		parse_map(t_game *game, char *file);
int		validate_map(t_game *game);
int		flood_fill_check(t_game *game);
int		init_graphics(t_game *game);
void	render(t_game *game);
int		handle_key(int keycode, t_game *game);
int		close_game(t_game *game);
void	free_map(t_map *map);
void	error_exit(char *msg, t_game *game);

#endif
