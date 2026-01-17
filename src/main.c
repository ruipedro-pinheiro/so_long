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
void	display_sprite(t_data *data, int y, int x)
{
	// char	**map;
	// map = ft_split(map_parser(fd), '\n');
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, x,
		y);
}

int	render(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (data->win_ptr == NULL)
		return (1);
	while (1)
	{
		display_sprite(data, y, x);
		x = x + 128;
		if (x >= 1920)
		{
			x = 0;
			y = y + 128;
		}
		if (y >= 1280)
			break ;
	}
	return (0);
}

int	graphic_management(void)
{
	t_data	data;
	int		height;
	int		width;

	height = 32;
	width = 32;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1280,
			"So_long: Stardew Valley");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (1);
	}
	data.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, "assets/ground.xpm",
			&width, &height);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, 0, &close_window, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	map_validator(fd);
	if (argc <= 1)
	{
		write(2, "Map unavailable \n", 30);
		return (0);
	}
	ft_printf("%s \n", *argv);
	graphic_management();
}
