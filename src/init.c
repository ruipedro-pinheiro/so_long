/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/29 10:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map_struct(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->collectibles = 0;
	map->collected = 0;
	map->exit_count = 0;
	map->player_count = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->exit.x = 0;
	map->exit.y = 0;
}

static void	init_img_struct(t_img *img)
{
	img->ground = NULL;
	img->wall = NULL;
	img->player = NULL;
	img->collect = NULL;
	img->exit_open = NULL;
	img->exit_closed = NULL;
}

static void	free_grid(t_game *game)
{
	free_map(game->map.grid);
	game->map.grid = NULL;
}

int	init_game(t_game *game, char *map_file)
{
	game->mlx = NULL;
	game->win = NULL;
	game->win_w = 0;
	game->win_h = 0;
	game->moves = 0;
	game->game_over = 0;
	init_map_struct(&game->map);
	init_img_struct(&game->img);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (error_msg("Error\nFailed to initialize MLX"));
	if (!parse_map(game, map_file))
		return (0);
	if (!validate_map(&game->map))
		return (free_grid(game), 0);
	if (!check_valid_path(&game->map))
		return (free_grid(game), error_msg("Error\nNo valid path in map"));
	return (1);
}
