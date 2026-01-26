/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.json                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:28:33 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/09 12:29:29 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}
// TODO = CALCULATE MAP SIZE X 128 AUTOMATICALLY ! IT IS STILL HARDCODED
int	render(t_data *data)
{
	int	y;
	int	x;
	int	res;

	res = 128;
	y = 0;
	x = 0;
	if (data->win_ptr == NULL)
		return (1);
	while (1)
	{
		display_sprite(data, data->map, y, x);
		if (x > 1792)
		{
			x = 0;
			y = y + res;
		}
		if (y > 6)
			break ;
		x = x + res;
	}
	return (0);
}

int	graphic_management(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1280,
			"So_long: Stardew Valley");
	if (data->win_ptr == NULL)
		return (1);
	set_image(data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, &close_window, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.ground);
	mlx_destroy_image(data->mlx_ptr, data->img.wall);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long maps/map.ber\n", 27);
		return (1);
	}
	if (!map_validator(argv))
	{
		write(2, "Invalid Map\n", 12);
		return (1);
	}
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd < 0)
	{
		write(2, "Error opening map\n", 18);
		return (1);
	}
	data.map = map_parser(data.fd);
	close(data.fd);
	if (!data.map)
	{
		write(2, "Error parsing map\n", 18);
		return (1);
	}
	graphic_management(&data);
	display_map(&data, data.map);
	free_map(data.map);
	return (0);
}
