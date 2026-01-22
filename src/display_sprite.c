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

void	display_map(t_data *data, char **map)
{
	int		i;

	(void)data;
	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	display_sprite(t_data *data, char **map, int y, int x)
{
	(void)map;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, x, y);
}
