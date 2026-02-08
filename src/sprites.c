/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/29 10:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	load_sprite(t_game *game, void **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!*img)
		return (0);
	return (1);
}

void	destroy_sprites(t_game *game)
{
	if (game->img.ground)
		mlx_destroy_image(game->mlx, game->img.ground);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.collect)
		mlx_destroy_image(game->mlx, game->img.collect);
	if (game->img.exit_open)
		mlx_destroy_image(game->mlx, game->img.exit_open);
	if (game->img.exit_closed)
		mlx_destroy_image(game->mlx, game->img.exit_closed);
}

int	load_sprites(t_game *game)
{
	if (!load_sprite(game, &game->img.ground, "assets/ground.xpm"))
		return (0);
	if (!load_sprite(game, &game->img.wall, "assets/wall.xpm"))
		return (0);
	if (!load_sprite(game, &game->img.player, "assets/player.xpm"))
		return (0);
	if (!load_sprite(game, &game->img.collect, "assets/collect.xpm"))
		return (0);
	if (!load_sprite(game, &game->img.exit_closed, "assets/exit_closed.xpm"))
		return (0);
	if (!load_sprite(game, &game->img.exit_open, "assets/exit_open.xpm"))
		return (0);
	return (1);
}
