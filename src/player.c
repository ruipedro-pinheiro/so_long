/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/29 10:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	can_move(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return (0);
	if (game->map.grid[y][x] == '1')
		return (0);
	return (1);
}

void	check_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map.grid[y][x];
	if (tile == 'C')
	{
		game->map.collected++;
		game->map.grid[y][x] = '0';
	}
	else if (tile == 'E' && game->map.collected >= game->map.collectibles)
	{
		win_game(game);
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->map.player.x + dx;
	new_y = game->map.player.y + dy;
	if (!can_move(game, new_x, new_y))
		return ;
	game->moves++;
	print_moves(game->moves);
	check_tile(game, new_x, new_y);
	game->map.player.x = new_x;
	game->map.player.y = new_y;
	update_camera(game);
	render_game(game);
}

int	handle_keypress(int keysym, t_game *game)
{
	if (game->game_over)
		return (0);
	if (keysym == XK_Escape)
		close_game(game);
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		move_player(game, 0, -1);
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		move_player(game, 0, 1);
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		move_player(game, -1, 0);
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		move_player(game, 1, 0);
	return (0);
}
