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
	char	*one_line_map;

	one_line_map = ft_strdup("");
	while ((line = get_next_line(fd)))
	{
		tmp = one_line_map;
		one_line_map = ft_strjoin(one_line_map, line);
		free(tmp);
		free(line);
	}
	map = ft_split(one_line_map, '\n');
	free(one_line_map);
	return (map);
}

void	display_map(int fd)
{
	char	**map;
	int		i;

	i = 0;
	map = map_parser(fd);
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

bool	map_validator(int fd)
{
	display_map(fd);
	return (true);
}
