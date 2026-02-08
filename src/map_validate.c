/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/29 10:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1')
			return (error_msg("Error\nMap not enclosed by walls (top)"));
		if (map->grid[map->height - 1][i] != '1')
			return (error_msg("Error\nMap not enclosed by walls (bottom)"));
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1')
			return (error_msg("Error\nMap not enclosed by walls (left)"));
		if (map->grid[i][map->width - 1] != '1')
			return (error_msg("Error\nMap not enclosed by walls (right)"));
		i++;
	}
	return (1);
}

int	check_characters(t_map *map)
{
	int		x;
	int		y;
	char	c;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			c = map->grid[y][x];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				return (error_msg("Error\nInvalid character in map"));
		}
	}
	return (1);
}

static void	set_pos(t_map *map, char c, int x, int y)
{
	if (c == 'E' && ++map->exit_count)
	{
		map->exit.x = x;
		map->exit.y = y;
	}
	else if (c == 'P' && ++map->player_count)
	{
		map->player.x = x;
		map->player.y = y;
	}
}

int	count_elements(t_map *map)
{
	int		x;
	int		y;
	char	c;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			c = map->grid[y][x];
			if (c == 'C')
				map->collectibles++;
			else
				set_pos(map, c, x, y);
		}
	}
	return (1);
}

int	validate_map(t_map *map)
{
	if (!check_characters(map))
		return (0);
	if (!check_walls(map))
		return (0);
	count_elements(map);
	if (map->player_count != 1)
		return (error_msg("Error\nMap must have exactly 1 player (P)"));
	if (map->exit_count != 1)
		return (error_msg("Error\nMap must have exactly 1 exit (E)"));
	if (map->collectibles < 1)
		return (error_msg("Error\nMap must have at least 1 collectible (C)"));
	return (1);
}
