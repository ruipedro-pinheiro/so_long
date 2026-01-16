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
	int		i;

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
	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	return (map);
}
bool	map_validator(int fd)
{
	map_parser(fd);
	return (true);
}
