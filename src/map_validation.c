/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:03:37 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/21 11:46:48 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**map_parser(int fd, t_data *data)
{
	char	**map;
	char	*line;
	char	*big;
	int		map_height;

	map_height = 0;
	if (fd < 0)
		return (NULL);
	big = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->map_width = ft_strlen(line) - 1;
		big = ft_strjoin(big, line);
		free(line);
		map_height++;
	}
	map = ft_split(big, '\n');
	free(big);
	data->map_height = map_height - 1;
	return (map);
}

int	vertical_border_check(char **map)
{
	int	i;
	int	len;

	if (!map)
		return (0);
	len = ft_strlen(map[0]) - 1;
	i = 1;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (0);
		if (map[i][len] != '1')
			return (0);
		if (!map[i + 1])
			return (1);
		i++;
	}
	return (1);
}

int	horizontal_border_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	j = 0;
	if (!vertical_border_check(map))
		return (0);
	while (map[i + 2])
		i++;
	while (map[i][j])
	{
		if (map[i + 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	map_validator(t_data *data)
{
	int	fd;

	fd = open("maps/map.ber", O_RDONLY);
	data->fd = fd;
	data->map = map_parser(data->fd, data);
	close(fd);
	if (!data->map)
		return (0);
	if (!horizontal_border_check(data->map))
		return (free_map(data->map), 0);
	free_map(data->map);
	return (1);
}
