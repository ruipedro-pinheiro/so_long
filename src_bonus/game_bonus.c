/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/29 10:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	update_camera(t_game *game)
{
	int	px;
	int	py;
	int	map_pw;
	int	map_ph;

	px = game->map.player.x * TILE_SIZE + TILE_SIZE / 2;
	py = game->map.player.y * TILE_SIZE + TILE_SIZE / 2;
	game->cam.x = px - game->win_w / 2;
	game->cam.y = py - game->win_h / 2;
	map_pw = game->map.width * TILE_SIZE;
	map_ph = game->map.height * TILE_SIZE;
	if (game->cam.x < 0)
		game->cam.x = 0;
	if (game->cam.y < 0)
		game->cam.y = 0;
	if (game->cam.x > map_pw - game->win_w)
		game->cam.x = map_pw - game->win_w;
	if (game->cam.y > map_ph - game->win_h)
		game->cam.y = map_ph - game->win_h;
}

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + tv.tv_usec);
}

void	win_game(t_game *game)
{
	ft_printf("\n%s%d\n", MSG_WIN, game->moves);
	game->game_over = 1;
	close_game(game);
}

void	lose_game(t_game *game)
{
	ft_printf("\n%s\n", MSG_LOSE);
	game->game_over = 1;
	close_game(game);
}

int	close_game(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}
