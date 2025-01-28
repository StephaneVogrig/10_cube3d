/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:27:56 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/28 01:19:50 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_move_bonus.h"

double	sign_double(double value)
{
	if (value < 0.0)
		return (-1.0);
	return (1.0);
}

void	dda_before_collide(t_ray *ray, t_position *start, t_data *data)
{
	raycast(ray, start, data);
	if (ray->hit_axis == 'x')
		ray->len -= fabs(DIST_BEFORE_COLLIDE / ray->dirvec.x);
	else
		ray->len -= fabs(DIST_BEFORE_COLLIDE / ray->dirvec.y);
	ray->hit_pos = *start;
	gridbox_add_double(&ray->hit_pos.x, ray->dirvec.x * ray->len);
	gridbox_add_double(&ray->hit_pos.y, ray->dirvec.y * ray->len);
}

void	slide(t_player *player, t_ray *ray, double len_move, t_data *data)
{
	double	len_axis_remain;

	player->position = ray->hit_pos;
	len_move -= ray->len;
	if (ray->hit_axis == 'x')
	{
		len_axis_remain = fabs(ray->dirvec.y) * len_move;
		ray->dirvec.x = 0;
		ray->dirvec.y = sign_double(ray->dirvec.y);
		dda_before_collide(ray, &player->position, data);
		if (ray->len > len_axis_remain)
			ray->len = len_axis_remain;
		gridbox_add_double(&player->y, ray->dirvec.y * ray->len);
	}
	else
	{
		len_axis_remain = fabs(ray->dirvec.x) * len_move;
		ray->dirvec.x = sign_double(ray->dirvec.x);
		ray->dirvec.y = 0;
		dda_before_collide(ray, &player->position, data);
		if (ray->len > len_axis_remain)
			ray->len = len_axis_remain;
		gridbox_add_double(&player->x, ray->dirvec.x * ray->len);
	}
}

void	player_move(t_player *player, t_vec2i move, double move_len,
		t_data *data)
{
	t_ray	ray;

	ray.dirvec = player_dir_move_vec(player, move);
	open_door_auto_near_player(data, &data->map, data->door_open_list);
	dda_before_collide(&ray, &player->position, data);
	if (ray.len <= move_len)
		slide(player, &ray, move_len, data);
	else
	{
		gridbox_add_double(&player->x, ray.dirvec.x * move_len);
		gridbox_add_double(&player->y, ray.dirvec.y * move_len);
	}
}
