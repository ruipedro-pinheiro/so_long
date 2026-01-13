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

bool	map_vertical_validation(int i, int j, char **map, int end)
{
	if (j == 0 && map[i][j] != '1')
		return (false);
	if (j == end && map[i][j] != '1')
		return (false);
	return (true);
}

bool	map_border(char **map, int fd)
{
	int	i;
	int	j;
	int	end;

	end = ft_strlen(get_next_line(fd)) - 1;
	i = 0;
	j = 0;
	while (j <= end && map[i][j])
	{
		if (i == 0)
		{
			while (j <= end)
			{
				if (map[i][j] != '1')
					return (false);
				j++;
			}
		}
		i++;
	}
	return (true);
}

bool	map_validator(int fd)
{
	char	**map;
	int		i;

	map = 0;
	i = 0;
	while (1)
	{
		if (get_next_line(fd) == NULL)
			break ;
		map[i] = get_next_line(fd);
		i++;
	}
	if (!map_border(map, fd))
		return (false);
	return (true);
}
