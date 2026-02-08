/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2026/01/29 10:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	update_anim(t_anim *anim, long current_time)
{
	if (anim->count <= 0)
		return ;
	if (current_time - anim->last_update >= ANIM_SPEED)
	{
		anim->current = (anim->current + 1) % anim->count;
		anim->last_update = current_time;
	}
}

void	update_animations(t_game *game)
{
	long	current_time;

	current_time = get_time_ms();
	game->img.player.current = game->player_dir;
	update_anim(&game->img.enemy, current_time);
}

void	*get_current_frame(t_anim *anim)
{
	if (anim->count <= 0 || anim->current >= anim->count)
		return (NULL);
	return (anim->frames[anim->current]);
}
