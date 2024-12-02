/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:27:56 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/01 17:49:23 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "player_move_bonus.h"
#include "dda.h"
#include "window.h"

double	sign_double(double value)
{
	if (value < 0.0)
		return (-1.0);
	return (1.0);
}

void	player_move_dda(t_ray *ray, t_map *map, t_position *start, int len_max)
{
	dda(ray, map, start, len_max);
	if (ray->hit_side == 'w' || ray->hit_side == 'e')
		ray->len -= fabs(DIST_BEFORE_COLLIDE / ray->vdir.x);
	else
		ray->len -= fabs(DIST_BEFORE_COLLIDE / ray->vdir.y);
	ray->hit_pos.x = start->x;
	ray->hit_pos.y = start->y;
	fixedpoint_add_double(&ray->hit_pos.x, ray->vdir.x * ray->len);
	fixedpoint_add_double(&ray->hit_pos.y, ray->vdir.y * ray->len);
}

t_vec2d	player_move_vec(t_player *player, t_vec2i move)
{
	double	cos_d;
	double	sin_d;
	t_vec2d	vec;

	cos_d = cos(player->dir);
	sin_d = sin(player->dir);
	vec.x = move.x * cos_d - move.y * sin_d;
	vec.y = move.x * sin_d + move.y * cos_d;
	return (vec);
}

void	collision_perform(t_map *map, t_player *player, t_ray *ray, double len_move)
{
	double	len_axis_remain;

	player->position = ray->hit_pos;
	len_move -= ray->len;
	if (ray->hit_side == 'w' || ray->hit_side == 'e')
	{
		len_axis_remain = fabs(ray->vdir.y) * len_move;
		ray->vdir.x = 0;
		ray->vdir.y = sign_double(ray->vdir.y);
		player_move_dda(ray, map, &player->position, WIN_H);
		if (ray->len > len_axis_remain)
			ray->len = len_axis_remain;
		fixedpoint_add_double(&player->y, ray->vdir.y * ray->len);
	}
	else
	{
		len_axis_remain = fabs(ray->vdir.x) * len_move;
		ray->vdir.x = sign_double(ray->vdir.x);
		ray->vdir.y = 0;
		player_move_dda(ray, map, &player->position, WIN_H);
		if (ray->len > len_axis_remain)
			ray->len = len_axis_remain;
		fixedpoint_add_double(&player->x, ray->vdir.x * ray->len);
	}
}

void	player_move(t_map *map, t_player *player, t_vec2i move, t_gtime delta_time)
{
	t_ray	ray;
	double	len_move;

	len_move = (SPEED_MOVE * delta_time) / 10000; //delta_time en us, speed_move en case par 10ms
	ray.vdir = player_move_vec(player, move);
	player_move_dda(&ray, map, &player->position, WIN_H);

	if (ray.len <= len_move)
		collision_perform(map, player, &ray, len_move);
	else
	{
		fixedpoint_add_double(&player->x, ray.vdir.x * len_move);
		fixedpoint_add_double(&player->y, ray.vdir.y * len_move);
	}

}
