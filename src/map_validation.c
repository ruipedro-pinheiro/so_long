/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:03:37 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/13 15:28:17 by rpinheir         ###   ########.ch       */
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
	while ((line = get_next_line(fd)))
	{
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
	int	j;
	int	len;

	len = ft_strlen(map[0]);
	i = 0;
	j = 0;
	if (!map)
		return (0);
	while (map[i][j])
	{
		if (map[i][0] != '1')
			return (0);
		if (map[i][len] != '1')
			return (0);
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
	if (!map)
		return (0);
	while (map[0][j])
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	j = 0;
	if (!vertical_border_check(map))
		return (false);
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

int	map_validator(int fd)
{
	char	**map;
	int		i;

	i = 0;
	map = map_parser(fd);
	if (!map)
		return (0);
	if (!horizontal_border_check(map))
		return (0);
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	return (1);
}
