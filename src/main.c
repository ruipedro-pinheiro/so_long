#include "so_long.h"

static void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map.grid = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.collectibles = 0;
	game->map.collected = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.dir = 0;
	game->player.frame = 0;
	game->moves = 0;
	game->win_state = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./so_long <map.ber>\n", 2);
		return (1);
	}
	init_game(&game);
	if (!parse_map(&game, argv[1]))
		return (1);
	if (!validate_map(&game))
	{
		free_map(&game.map);
		return (1);
	}
	if (!flood_fill_check(&game))
	{
		free_map(&game.map);
		return (1);
	}
	if (!init_graphics(&game))
	{
		free_map(&game.map);
		return (1);
	}
	render(&game);
	mlx_hook(game.win, 2, 1L << 0, (void *)handle_key, &game);
	mlx_hook(game.win, 17, 0, (void *)close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
