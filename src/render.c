/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/30 22:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_img(t_game *game, void *img, int x, int y)
{
	int	sx;
	int	sy;

	if (!img)
		return ;
	sx = x * TILE_SIZE - game->cam.x;
	sy = y * TILE_SIZE - game->cam.y;
	if (sx + TILE_SIZE < 0 || sx > game->win_w)
		return ;
	if (sy + TILE_SIZE < 0 || sy > game->win_h)
		return ;
	mlx_put_image_to_window(game->mlx, game->win, img, sx, sy);
}

static void	render_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map.grid[y][x];
	put_img(game, game->img.ground, x, y);
	if (tile == '1')
		put_img(game, game->img.wall, x, y);
	else if (tile == 'C')
		put_img(game, game->img.collect, x, y);
	else if (tile == 'E')
	{
		if (game->map.collected >= game->map.collectibles)
			put_img(game, game->img.exit_open, x, y);
		else
			put_img(game, game->img.exit_closed, x, y);
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}

void	render_player(t_game *game)
{
	put_img(game, game->img.ground, game->map.player.x, game->map.player.y);
	put_img(game, game->img.player, game->map.player.x, game->map.player.y);
}

void	render_game(t_game *game)
{
	render_map(game);
	render_player(game);
}
