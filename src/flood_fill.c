#include "so_long.h"

static char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map.height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		copy[i] = ft_strdup(game->map.grid[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	free_copy(char **copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}

static void	flood(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood(map, x + 1, y, game);
	flood(map, x - 1, y, game);
	flood(map, x, y + 1, game);
	flood(map, x, y - 1, game);
}

static int	check_reachable(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	flood_fill_check(t_game *game)
{
	char	**copy;
	int		result;

	copy = copy_map(game);
	if (!copy)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		return (0);
	}
	flood(copy, game->player.x, game->player.y, game);
	result = check_reachable(copy, game);
	free_copy(copy, game->map.height);
	if (!result)
	{
		ft_putstr_fd("Error\nNo valid path to all collectibles/exit\n", 2);
		return (0);
	}
	return (1);
}
