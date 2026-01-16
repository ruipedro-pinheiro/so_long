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
	int		i;

	i = 0;
	map = NULL;
	if (fd == 0)
		return (NULL);
	while (i++)
	{
		ft_strjoin(*map, get_next_line(fd));
		if (map[i][0] == '\0')
			break ;
	}
	return (map);
}
bool	map_validator(int fd)
{
	char	**map;

	map = map_parser(fd);
	ft_printf("Map: %s \n", map);
	return (true);
}
