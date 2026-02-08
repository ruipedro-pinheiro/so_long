/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/29 10:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_lines(char *content)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!content || !content[0])
		return (0);
	while (content[i])
	{
		if (content[i] == '\n')
			count++;
		i++;
	}
	if (i > 0 && content[i - 1] != '\n')
		count++;
	return (count);
}

int	read_map_file(char *file, char **content)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error_msg("Error\nCannot open map file"));
	*content = ft_strdup("");
	if (!*content)
		return (close(fd), 0);
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_strjoin(*content, line);
		free(*content);
		free(line);
		if (!temp)
			return (close(fd), 0);
		*content = temp;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	check_rectangular(t_map *map)
{
	int	i;
	int	len;

	if (!map->grid || !map->grid[0])
		return (0);
	len = ft_strlen(map->grid[0]);
	i = 1;
	while (map->grid[i])
	{
		if (ft_strlen(map->grid[i]) != len)
			return (error_msg("Error\nMap is not rectangular"));
		i++;
	}
	map->width = len;
	return (1);
}

static void	free_grid(t_game *game)
{
	free_map(game->map.grid);
	game->map.grid = NULL;
}

int	parse_map(t_game *game, char *file)
{
	char	*content;
	int		i;

	content = NULL;
	if (!read_map_file(file, &content))
		return (0);
	if (!content || !content[0])
		return (free(content), error_msg("Error\nEmpty map file"));
	game->map.height = count_lines(content);
	if (game->map.height < 3)
		return (free(content), error_msg("Error\nMap too small"));
	game->map.grid = ft_split(content, '\n');
	free(content);
	if (!game->map.grid)
		return (error_msg("Error\nFailed to parse map"));
	i = 0;
	while (game->map.grid[i])
		i++;
	game->map.height = i;
	if (!check_rectangular(&game->map))
		return (free_grid(game), 0);
	return (1);
}
