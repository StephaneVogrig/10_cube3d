/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:27:56 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 15:03:06 by aska             ###   ########.fr       */
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

void	open_door_auto(t_map *map, int x, int y, t_door_open *door_open_list)
{
	char		*cell;
	t_position	pos;

	pos = position(x, 0.0, y, 0.0);
	cell = map_get_cell_ptr(map, &pos);
	if (cell && *cell == 'T')
		door_open(cell, door_open_list);
}

void	open_door_auto_near_player(t_data *data, t_map *map,
		t_door_open *door_open_list)
{
	int	x;
	int	y;

	x = data->player.x.grid;
	y = data->player.y.grid;
	open_door_auto(map, x, y, door_open_list);
	open_door_auto(map, x - 1, y, door_open_list);
	open_door_auto(map, x + 1, y, door_open_list);
	open_door_auto(map, x, y - 1, door_open_list);
	open_door_auto(map, x, y + 1, door_open_list);
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
