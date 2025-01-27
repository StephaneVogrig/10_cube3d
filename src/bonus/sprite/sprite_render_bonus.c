/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_render_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:31:34 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 18:10:50 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite_render_bonus.h"

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
	t_vec2d	dirvec;

	dirvec = dir_to_dirvec(dir);
	new_coord.x = -(point.x * dirvec.x + point.y * dirvec.y);
	new_coord.y = -point.x * dirvec.y + point.y * dirvec.x;
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

void	sprite_sort(t_sprite *sprite)
{
	int		i;
	int		j;
	int		sorting;
	t_vec2d	*transform;

	transform = sprite->transform;
	i = 1;
	while (i < sprite->nbr)
	{
		sorting = sprite->order[i];
		j = i;
		while (j > 0
			&& transform[sorting].y > transform[sprite->order[j - 1]].y)
		{
			sprite->order[j] = sprite->order[j - 1];
			j--;
		}
		sprite->order[j] = sorting;
		i++;
	}
}

void	sprite_render(t_sprite *sprite, t_player *player, t_data *data)
{
	int	i;
	int	j;

	sprite_transform_coordonate(sprite, player);
	sprite_sort(sprite);
	sprite_collect(sprite, player);
	i = 0;
	while (i < sprite->nbr)
	{
		j = sprite->order[i];
		if (sprite->transform[j].y < 0)
			break ;
		if (sprite->collected[j] == FALSE)
			sprite_draw(sprite, j, data);
		i++;
	}
}
