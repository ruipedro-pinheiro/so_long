/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2026/02/17 13:39:45 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	setup_window(t_game *game)
{
	int	map_pw;
	int	map_ph;

	map_pw = game->map.width * 128;
	map_ph = game->map.height * 128;
	if (map_pw > 1280)
		game->win_w = 1280;
	else
		game->win_w = map_pw;
	if (map_ph > 720)
		game->win_h = 720;
	else
		game->win_h = map_ph;
	game->cam.w = game->win_w / 128 + 2;
	game->cam.h = game->win_h / 128 + 2;
	game->cam.x = 0;
	game->cam.y = 0;
	game->win = mlx_new_window(game->mlx, game->win_w, game->win_h, "so_long");
	if (!game->win)
		return (0);
	return (1);
}

static void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, (void *)handle_keypress, game);
	mlx_hook(game->win, DestroyNotify, 0, (void *)close_game, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (error_msg("Usage: ./so_long <map.ber>"));
	if (!check_extension(argv[1], ".ber"))
		return (error_msg("Error\nInvalid file extension (need .ber)"));
	if (!init_game(&game, argv[1]))
		return (cleanup_game(&game), 1);
	if (!setup_window(&game))
		return (error_exit(&game, "Error\nFailed to create window"));
	if (!load_sprites(&game))
		return (error_exit(&game, "Error\nFailed to load sprites"));
	setup_hooks(&game);
	update_camera(&game);
	render_game(&game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}
