/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pathfind_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/29 10:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

char	**copy_map(char **grid, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(grid[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

void	flood_fill(char **grid, int x, int y, t_map *map)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (grid[y][x] == '1' || grid[y][x] == 'F')
		return ;
	grid[y][x] = 'F';
	flood_fill(grid, x + 1, y, map);
	flood_fill(grid, x - 1, y, map);
	flood_fill(grid, x, y + 1, map);
	flood_fill(grid, x, y - 1, map);
}

int	check_flood_result(char **grid, t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (grid[y][x] == 'C')
				return (0);
			if (grid[y][x] == 'E')
				return (0);
		}
	}
	return (1);
}

int	check_valid_path(t_map *map)
{
	char	**grid_copy;
	int		result;

	grid_copy = copy_map(map->grid, map->height);
	if (!grid_copy)
		return (0);
	flood_fill(grid_copy, map->player.x, map->player.y, map);
	result = check_flood_result(grid_copy, map);
	free_map(grid_copy);
	return (result);
}
