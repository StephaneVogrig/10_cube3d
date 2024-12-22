/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_collect_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:18:41 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/22 20:52:56 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "sprite_bonus.h"

void	sprite_collect_check(t_vec2d sprite, t_vec2d player, int *collected)
{
	float	dist;
	t_vec2d	d;
	
	if (*collected)
		return ;
	d.x = sprite.x - player.x;
	d.y = sprite.y - player.y;
	dist = d.x * d.x + d.y * d.y;
	if (dist < DISTANCE_COLLECT)
		*collected = TRUE;
}

void	sprite_collect(t_sprite *sprite, t_player *player)
{
	int	i;
	t_vec2d	player_pos;

	player_pos = position_to_vec2d(player->position);
	i = 0;
	while (i < sprite->nbr)
	{
		sprite_collect_check(sprite->pos[i], player_pos, &sprite->collected[i]);
		i++;
	}
}
