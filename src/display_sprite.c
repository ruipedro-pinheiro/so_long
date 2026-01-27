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
	int	i;

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

int	display_sprite(t_data *data, char **map, int y, int x)
{
	int	i;
	int	j;

	if (x == 0)
		j = 0;
	if (y == 0)
		i = 0;
	else
	{
		i = y / 128;
		j = x / 128;
	}
	if (map[i][j] == '0' || map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ground,
			x, y);
	else if (map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.wall, x,
			y);
	else if (map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.exit, x,
			y);
	else if (map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.collectible, x, y);
	return (0);
}

int	set_wall_img(t_data *data)
{
	int	width;
	int	height;

	width = 128;
	height = 128;
	data->img.wall = mlx_xpm_file_to_image(data->mlx_ptr, "assets/wall.xpm",
			&width, &height);
	if (data->img.wall == NULL)
		return (1);
	data->img.addr = mlx_get_data_addr(data->img.wall, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	return (0);
}
int	set_exit_img(t_data *data)
{
	int	width;
	int	height;

	width = 128;
	height = 128;
	data->img.exit = mlx_xpm_file_to_image(data->mlx_ptr, "assets/exit.xpm",
			&width, &height);
	if (data->img.exit == NULL)
		return (1);
	data->img.addr = mlx_get_data_addr(data->img.exit, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	return (0);
}

int	set_ground_img(t_data *data)
{
	int	width;
	int	height;

	width = 128;
	height = 128;
	data->img.ground = mlx_xpm_file_to_image(data->mlx_ptr, "assets/ground.xpm",
			&width, &height);
	if (data->img.ground == NULL)
		return (1);
	data->img.addr = mlx_get_data_addr(data->img.ground, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	return (0);
}

int	set_collectible_img(t_data *data)
{
	int	width;
	int	height;

	width = 128;
	height = 128;
	data->img.collectible = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/cat.xpm", &width, &height);
	if (data->img.collectible == NULL)
		return (1);
	data->img.addr = mlx_get_data_addr(data->img.collectible, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	return (0);
}

int	set_image(t_data *data)
{
	set_ground_img(data);
	set_wall_img(data);
	set_exit_img(data);
	set_collectible_img(data);
	return (0);
}
