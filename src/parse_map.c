#include "so_long.h"

static int	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5)
		return (0);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

static int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static char	*clean_line(char *line)
{
	int		len;
	char	*clean;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	clean = ft_strdup(line);
	free(line);
	return (clean);
}

static int	read_map(t_game *game, char *file)
{
	int		fd;
	int		i;
	char	*line;

	game->map.height = count_lines(file);
	if (game->map.height == 0)
		return (0);
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->map.grid[i] = clean_line(line);
		if (!game->map.grid[i])
			return (close(fd), 0);
		i++;
		line = get_next_line(fd);
	}
	game->map.grid[i] = NULL;
	close(fd);
	return (1);
}

int	parse_map(t_game *game, char *file)
{
	if (!check_extension(file))
	{
		ft_putstr_fd("Error\nInvalid file extension (need .ber)\n", 2);
		return (0);
	}
	if (!read_map(game, file))
	{
		ft_putstr_fd("Error\nCannot read map file\n", 2);
		return (0);
	}
	if (game->map.grid[0])
		game->map.width = ft_strlen(game->map.grid[0]);
	return (1);
}
