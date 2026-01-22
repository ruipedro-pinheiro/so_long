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

int	map_validator(char **argv)
{
	char	**map;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	map = map_parser(fd);
	close(fd);
	if (!map)
		return (0);
	if (!horizontal_border_check(map))
		return (free_map(map), 0);
	free_map(map);
	return (1);
}
