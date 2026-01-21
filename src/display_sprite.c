/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:09:38 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/21 14:25:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_map(t_data *data)
{
	int		i;
	char	**map;

	i = 0;
	map = map_parser(data->fd);
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	display_sprite(t_data data)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	display_map(&data);
	data.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, "assets/ground.xpm",
			&width, &height);
}
