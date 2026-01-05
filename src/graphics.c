#include "so_long.h"

static int	load_img(t_game *game, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(game->mlx, path,
			&img->width, &img->height);
	if (!img->img)
		return (0);
	return (1);
}

static int	load_player_sprites(t_game *game)
{
	char	*dirs[4];
	char	path[64];
	char	num[2];
	int		d;
	int		f;

	dirs[0] = "down";
	dirs[1] = "right";
	dirs[2] = "up";
	dirs[3] = "left";
	num[1] = '\0';
	d = -1;
	while (++d < 4)
	{
		f = -1;
		while (++f < 4)
		{
			num[0] = '1' + f;
			ft_strlcpy(path, "assets/xpm/player_", 64);
			ft_strlcat(path, dirs[d], 64);
			ft_strlcat(path, "_", 64);
			ft_strlcat(path, num, 64);
			ft_strlcat(path, ".xpm", 64);
			if (!load_img(game, &game->player_img[d][f], path))
				return (0);
		}
	}
	return (1);
}

static int	load_sprites(t_game *game)
{
	if (!load_img(game, &game->grass, "assets/xpm/grass.xpm"))
		return (0);
	if (!load_img(game, &game->wall, "assets/xpm/wall.xpm"))
		return (0);
	if (!load_img(game, &game->collectible, "assets/xpm/collectible.xpm"))
		return (0);
	if (!load_img(game, &game->exit_img, "assets/xpm/exit.xpm"))
		return (0);
	if (!load_player_sprites(game))
		return (0);
	return (1);
}

int	init_graphics(t_game *game)
{
	int	win_w;
	int	win_h;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nMLX initialization failed\n", 2);
		return (0);
	}
	win_w = game->map.width * TILE_SIZE;
	win_h = game->map.height * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, win_w, win_h, "so_long - Stardew");
	if (!game->win)
	{
		ft_putstr_fd("Error\nWindow creation failed\n", 2);
		return (0);
	}
	if (!load_sprites(game))
	{
		ft_putstr_fd("Error\nSprite loading failed\n", 2);
		return (0);
	}
	return (1);
}
