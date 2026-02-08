/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/29 10:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	init_enemies(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'X' && game->enemy_count < MAX_ENEMIES)
			{
				game->enemies[game->enemy_count].pos.x = x;
				game->enemies[game->enemy_count].pos.y = y;
				game->enemies[game->enemy_count].dir = 1;
				game->enemies[game->enemy_count].active = 1;
				game->enemy_count++;
			}
			x++;
		}
		y++;
	}
	game->last_enemy_move = get_time_ms();
}

static void	move_enemy(t_game *game, t_enemy *enemy)
{
	int		new_x;
	char	next_tile;

	new_x = enemy->pos.x + enemy->dir;
	if (new_x < 0 || new_x >= game->map.width)
	{
		enemy->dir *= -1;
		return ;
	}
	next_tile = game->map.grid[enemy->pos.y][new_x];
	if (next_tile == '1' || next_tile == 'E' || next_tile == 'C')
	{
		enemy->dir *= -1;
		return ;
	}
	enemy->pos.x = new_x;
}

void	update_enemies(t_game *game)
{
	long	current_time;
	int		i;

	current_time = get_time_ms();
	if (current_time - game->last_enemy_move < ENEMY_SPEED)
		return ;
	game->last_enemy_move = current_time;
	i = 0;
	while (i < game->enemy_count)
	{
		if (game->enemies[i].active)
			move_enemy(game, &game->enemies[i]);
		i++;
	}
}

void	render_enemies(t_game *game)
{
	void	*frame;
	int		i;

	frame = get_current_frame(&game->img.enemy);
	if (!frame)
		return ;
	i = 0;
	while (i < game->enemy_count)
	{
		if (game->enemies[i].active)
			put_img_cam(game, frame, game->enemies[i].pos.x,
				game->enemies[i].pos.y);
		i++;
	}
}

int	check_enemy_collision(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		if (game->enemies[i].active
			&& game->enemies[i].pos.x == game->map.player.x
			&& game->enemies[i].pos.y == game->map.player.y)
		{
			lose_game(game);
			return (1);
		}
		i++;
	}
	return (0);
}
