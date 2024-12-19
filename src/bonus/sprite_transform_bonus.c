/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_transform_coordonate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:31:34 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/19 22:33:49 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "sprite_bonus.h"

static t_vec2d	coord_transform_translate(t_vec2d point, t_vec2d new_origin)
{
	t_vec2d	new_coord;

	new_coord.x = point.x - new_origin.x;
	new_coord.y = point.y - new_origin.y;
	return (new_coord);
}

static t_vec2d	coord_transform_rotate(t_vec2d point, double dir)
{
	t_vec2d	new_coord;
	t_vec2d	dir_vec;

	dir_vec = dir_to_dirvec(dir);
	new_coord.x = -(point.x * dir_vec.x + point.y * dir_vec.y);
	new_coord.y = -point.x * dir_vec.y + point.y * dir_vec.x;
	return (new_coord);
}

void	sprite_transform_coordonate(t_sprite *sprite, t_player *player)
{
	t_vec2d	player_pos;
	t_vec2d	*sprite_pos;
	t_vec2d	*transform;
	double	dir_rot;
	int		i;

	player_pos.x = player->x.grid + player->x.box;
	player_pos.y = player->y.grid + player->y.box;
	sprite_pos = sprite->pos;
	transform = sprite->transform;
	dir_rot = player->dir - M_PI_2;
	i = 0;
	while (i < sprite->nbr)
	{
		*transform = coord_transform_translate(*sprite_pos, player_pos);
		*transform = coord_transform_rotate(*transform, dir_rot);
		sprite_pos++;
		transform++;
		i++;
	}
}
