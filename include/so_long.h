/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:28:53 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/09 12:29:13 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_img
{
	void	*ground;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	char	**map;
	int		cur_img;
}			t_data;

int			map_validator(char **argv);
char		**map_parser(int fd);
void		free_map(char **map);
void		display_map(t_data *data, char **map);
int			set_image(t_data *data);

int			display_sprite(t_data *data, char **map, int y, int x);
#endif
