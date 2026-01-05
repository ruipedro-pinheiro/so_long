#include "so_long.h"

static int	check_rectangular(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (game->map.grid[i])
	{
		len = ft_strlen(game->map.grid[i]);
		if (len != game->map.width)
			return (0);
		i++;
	}
	return (1);
}

static int	check_walls(t_game *game)
{
	int	i;
	int	w;
	int	h;

	w = game->map.width;
	h = game->map.height;
	i = 0;
	while (i < w)
	{
		if (game->map.grid[0][i] != '1')
			return (0);
		if (game->map.grid[h - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < h)
	{
		if (game->map.grid[i][0] != '1')
			return (0);
		if (game->map.grid[i][w - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_chars(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			c = game->map.grid[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				return (0);
		}
	}
	return (1);
}

static int	count_elements(t_game *game)
{
	int	i;
	int	j;
	int	p;
	int	e;

	p = 0;
	e = 0;
	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (game->map.grid[i][j] == 'P' && ++p)
			{
				game->player.x = j;
				game->player.y = i;
			}
			else if (game->map.grid[i][j] == 'E' && ++e)
			{
				game->map.exit_x = j;
				game->map.exit_y = i;
			}
			else if (game->map.grid[i][j] == 'C')
				game->map.collectibles++;
		}
	}
	return (p == 1 && e == 1 && game->map.collectibles > 0);
}

int	validate_map(t_game *game)
{
	if (!check_rectangular(game))
	{
		ft_putstr_fd("Error\nMap is not rectangular\n", 2);
		return (0);
	}
	if (!check_walls(game))
	{
		ft_putstr_fd("Error\nMap is not surrounded by walls\n", 2);
		return (0);
	}
	if (!check_chars(game))
	{
		ft_putstr_fd("Error\nInvalid character in map\n", 2);
		return (0);
	}
	if (!count_elements(game))
	{
		ft_putstr_fd("Error\nInvalid elements (need 1 P, 1 E, >= 1 C)\n", 2);
		return (0);
	}
	return (1);
}
