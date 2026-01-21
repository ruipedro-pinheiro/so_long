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

char	**map_parser(int fd)
{
	char	**map;
	char	*line;
	char	*tmp;
	char	*big;

	if (fd < 0)
		return (NULL);
	big = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = big;
		big = ft_strjoin(big, line);
		free(tmp);
		free(line);
	}
	map = ft_split(big, '\n');
	free(big);
	return (map);
}

int	vertical_border_check(char **map)
{
	int	i;
	int	len;

	len = ft_strlen(map[0] - 1);
	i = 1;
	if (!map)
		return (0);
	while (map[i][len] || **map)
	{
		if (map[i][0] != '1')
			return (free(map), 0);
		if (map[i][len] != '1')
			return (free(map), 0);
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
			return (free(map), 0);
		j++;
	}
	i = 0;
	j = 0;
	if (!vertical_border_check(map))
		return (free(map), false);
	while (map[i + 2])
		i++;
	while (map[i][j])
	{
		if (map[i + 1][j] != '1')
			return (free(map), 0);
		j++;
	}
	return (1);
}

int	map_validator(char **argv)
{
	char	**map;
	int		i;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	map = map_parser(fd);
	if (!map)
		return (0);
	if (!horizontal_border_check(map))
		return (free(map), 0);
	return (1);
}
