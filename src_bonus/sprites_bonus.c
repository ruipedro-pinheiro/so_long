/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/29 10:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	load_sprite(t_game *game, void **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!*img)
		return (0);
	return (1);
}

int	load_anim(t_game *game, t_anim *anim, char *base, int count)
{
	char	path[256];
	char	*num;
	int		i;

	i = 0;
	while (i < count && i < 4)
	{
		num = ft_itoa(i + 1);
		if (!num)
			return (0);
		ft_strlcpy(path, base, 200);
		ft_strlcat(path, num, 250);
		ft_strlcat(path, ".xpm", 255);
		free(num);
		if (!load_sprite(game, &anim->frames[i], path))
			return (0);
		i++;
	}
	anim->count = count;
	anim->current = 0;
	anim->last_update = 0;
	return (1);
}

void	destroy_sprites(t_game *game)
{
	int	i;

	if (game->img.ground)
		mlx_destroy_image(game->mlx, game->img.ground);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.collect)
		mlx_destroy_image(game->mlx, game->img.collect);
	if (game->img.exit_open)
		mlx_destroy_image(game->mlx, game->img.exit_open);
	if (game->img.exit_closed)
		mlx_destroy_image(game->mlx, game->img.exit_closed);
	i = 0;
	while (i < 4)
	{
		if (game->img.player.frames[i])
			mlx_destroy_image(game->mlx, game->img.player.frames[i]);
		if (game->img.enemy.frames[i])
			mlx_destroy_image(game->mlx, game->img.enemy.frames[i]);
		i++;
	}
}

static int	load_player_dir(t_game *game)
{
	t_anim	*p;

	p = &game->img.player;
	if (!load_sprite(game, &p->frames[0], "assets/player_down1.xpm"))
		return (0);
	if (!load_sprite(game, &p->frames[1], "assets/player_up1.xpm"))
		return (0);
	if (!load_sprite(game, &p->frames[2], "assets/player_left1.xpm"))
		return (0);
	if (!load_sprite(game, &p->frames[3], "assets/player_right1.xpm"))
		return (0);
	p->count = 4;
	p->current = DIR_DOWN;
	return (1);
}

int	load_sprites(t_game *game)
{
	if (!load_sprite(game, &game->img.ground, "assets/ground.xpm"))
		return (0);
	if (!load_sprite(game, &game->img.wall, "assets/wall.xpm"))
		return (0);
	if (!load_sprite(game, &game->img.collect, "assets/collect.xpm"))
		return (0);
	if (!load_sprite(game, &game->img.exit_closed, "assets/exit_closed.xpm"))
		return (0);
	if (!load_sprite(game, &game->img.exit_open, "assets/exit_open.xpm"))
		return (0);
	if (!load_player_dir(game))
		return (0);
	if (!load_anim(game, &game->img.enemy, "assets/enemy", 4))
		return (0);
	return (1);
}
