#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map->grid)
		return ;
	i = 0;
	while (map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

static void	destroy_images(t_game *game)
{
	int	d;
	int	f;

	if (game->grass.img)
		mlx_destroy_image(game->mlx, game->grass.img);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->collectible.img)
		mlx_destroy_image(game->mlx, game->collectible.img);
	if (game->exit_img.img)
		mlx_destroy_image(game->mlx, game->exit_img.img);
	d = 0;
	while (d < 4)
	{
		f = 0;
		while (f < 4)
		{
			if (game->player_img[d][f].img)
				mlx_destroy_image(game->mlx, game->player_img[d][f].img);
			f++;
		}
		d++;
	}
}

int	close_game(t_game *game)
{
	destroy_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(&game->map);
	exit(0);
	return (0);
}

void	error_exit(char *msg, t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	if (game)
		close_game(game);
	exit(1);
}
