#include "so_long.h"

static void	draw_tile(t_game *game, t_img *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img->img,
		x * TILE_SIZE, y * TILE_SIZE);
}

static void	draw_scaled(t_game *game, t_img *img, int x, int y)
{
	int	px;
	int	py;

	px = x * TILE_SIZE;
	py = y * TILE_SIZE - (img->height - TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, img->img, px, py);
}

static void	render_map(t_game *game)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			draw_tile(game, &game->grass, x, y);
			c = game->map.grid[y][x];
			if (c == '1')
				draw_tile(game, &game->wall, x, y);
			else if (c == 'C')
				draw_tile(game, &game->collectible, x, y);
			else if (c == 'E')
				draw_tile(game, &game->exit_img, x, y);
			x++;
		}
		y++;
	}
}

static void	render_player(t_game *game)
{
	t_img	*sprite;

	sprite = &game->player_img[game->player.dir][game->player.frame];
	draw_scaled(game, sprite, game->player.x, game->player.y);
}

void	render(t_game *game)
{
	render_map(game);
	render_player(game);
}
