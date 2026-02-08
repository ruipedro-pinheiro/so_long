/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/29 10:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
	int	i;

	img->ground = NULL;
	img->wall = NULL;
	img->collect = NULL;
	img->exit_open = NULL;
	img->exit_closed = NULL;
	img->player.count = 0;
	img->player.current = 0;
	img->enemy.count = 0;
	img->enemy.current = 0;
	i = 0;
	while (i < 4)
	{
		img->player.frames[i] = NULL;
		img->enemy.frames[i] = NULL;
		i++;
	}
}

static void	init_enemies_array(t_game *game)
{
	int	i;

	game->enemy_count = 0;
	i = 0;
	while (i < MAX_ENEMIES)
	{
		game->enemies[i].pos.x = 0;
		game->enemies[i].pos.y = 0;
		game->enemies[i].dir = 0;
		game->enemies[i].active = 0;
		i++;
	}
}

static void	init_game_struct(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->win_w = 0;
	game->win_h = 0;
	game->moves = 0;
	game->game_over = 0;
	game->player_dir = DIR_DOWN;
	game->last_enemy_move = 0;
	init_map_struct(&game->map);
	init_img_struct(&game->img);
	init_enemies_array(game);
}

int	init_game(t_game *game, char *map_file)
{
	init_game_struct(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (error_msg("Error\nFailed to initialize MLX"));
	if (!parse_map(game, map_file))
		return (0);
	if (!validate_map(&game->map))
	{
		free_map(game->map.grid);
		game->map.grid = NULL;
		return (0);
	}
	if (!check_valid_path(&game->map))
	{
		free_map(game->map.grid);
		game->map.grid = NULL;
		return (error_msg("Error\nNo valid path in map"));
	}
	return (1);
}
