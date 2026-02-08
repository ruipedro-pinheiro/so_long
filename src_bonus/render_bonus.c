/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/30 22:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	put_img_cam(t_game *game, void *img, int x, int y)
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

void	render_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map.grid[y][x];
	put_img_cam(game, game->img.ground, x, y);
	if (tile == '1')
		put_img_cam(game, game->img.wall, x, y);
	else if (tile == 'C')
		put_img_cam(game, game->img.collect, x, y);
	else if (tile == 'E')
	{
		if (game->map.collected >= game->map.collectibles)
			put_img_cam(game, game->img.exit_open, x, y);
		else
			put_img_cam(game, game->img.exit_closed, x, y);
	}
}

void	render_player(t_game *game)
{
	void	*frame;

	frame = get_current_frame(&game->img.player);
	if (frame)
		put_img_cam(game, frame, game->map.player.x, game->map.player.y);
}

void	render_ui(t_game *game)
{
	char	*moves_str;
	char	*display;

	moves_str = ft_itoa(game->moves);
	if (!moves_str)
		return ;
	display = ft_strjoin("Moves: ", moves_str);
	free(moves_str);
	if (!display)
		return ;
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, display);
	free(display);
}

int	render(t_game *game)
{
	int	x;
	int	y;

	if (!game->win || game->game_over)
		return (0);
	update_animations(game);
	update_enemies(game);
	if (check_enemy_collision(game))
		return (0);
	update_camera(game);
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
	render_enemies(game);
	render_player(game);
	render_ui(game);
	return (0);
}
