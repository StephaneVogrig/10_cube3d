/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:27:56 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/24 20:43:19 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "player_move_bonus.h"

double	sign_double(double value)
{
	if (value < 0.0)
		return (-1.0);
	return (1.0);
}

void	dda_before_collide(t_ray *ray, t_position *start, t_data *data)
{
	dda(ray, start, data);
	if (ray->hit_side == 'W' || ray->hit_side == 'E')
		ray->len -= fabs(DIST_BEFORE_COLLIDE / ray->vdir.x);
	else
		ray->len -= fabs(DIST_BEFORE_COLLIDE / ray->vdir.y);
	ray->hit_pos = *start;
	gridbox_add_double(&ray->hit_pos.x, ray->vdir.x * ray->len);
	gridbox_add_double(&ray->hit_pos.y, ray->vdir.y * ray->len);
}

void	slide(t_player *player, t_ray *ray, double len_move, t_data *data)
{
(void)data;
	double	len_axis_remain;

	player->position = ray->hit_pos;
	len_move -= ray->len;
	if (ray->hit_side == 'W' || ray->hit_side == 'E')
	{
		len_axis_remain = fabs(ray->vdir.y) * len_move;
		ray->vdir.x = 0;
		ray->vdir.y = sign_double(ray->vdir.y);
		dda_before_collide(ray, &player->position, data);
		if (ray->len > len_axis_remain)
			ray->len = len_axis_remain;
		gridbox_add_double(&player->y, ray->vdir.y * ray->len);
	}
	else
	{
		len_axis_remain = fabs(ray->vdir.x) * len_move;
		ray->vdir.x = sign_double(ray->vdir.x);
		ray->vdir.y = 0;
		dda_before_collide(ray, &player->position, data);
		if (ray->len > len_axis_remain)
			ray->len = len_axis_remain;
		gridbox_add_double(&player->x, ray->vdir.x * ray->len);
	}
}

void	open_door_auto(t_map *map, int x, int y, t_door *door_open_list)
{
	char *cell;

	cell = map_get_cell_ptr(map, &(t_position){{x, 0.0}, {y, 0.0}});
	if (cell && *cell == 'T')
		door_open(cell, door_open_list);
}

void open_door_auto_near_player(t_data *data, t_map *map, t_door *door_open_list)
{
	int	x;
	int y;

	x = data->player.x.grid;
	y = data->player.y.grid;
	open_door_auto(map, x, y, door_open_list);
	open_door_auto(map, x - 1, y, door_open_list);
	open_door_auto(map, x + 1, y, door_open_list);
	open_door_auto(map, x, y - 1, door_open_list);
	open_door_auto(map, x, y + 1, door_open_list);
}

void	player_move(t_player *player, t_vec2i move, double move_len, t_data *data)
{
	t_ray	ray;

	ray.vdir = player_dir_move_vec(player, move);
	open_door_auto_near_player(data, &data->map, data->door_open_list);
	dda_before_collide(&ray, &player->position, data);
	if (ray.len <= move_len)
		slide(player, &ray, move_len, data);
	else
	{
		gridbox_add_double(&player->x, ray.vdir.x * move_len);
		gridbox_add_double(&player->y, ray.vdir.y * move_len);
	}
}
