/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:27:56 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/07 20:45:39 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "player_move_bonus.h"
#include "dda_bonus.h"

double	sign_double(double value)
{
	if (value < 0.0)
		return (-1.0);
	return (1.0);
}

void	player_move_dda(t_ray *ray, t_map *map, t_position *start, t_door *door_open_list)
{
	dda(ray, map, start, door_open_list);
	if (ray->hit_side == 'w' || ray->hit_side == 'e')
		ray->len -= fabs(DIST_BEFORE_COLLIDE / ray->vdir.x);
	else
		ray->len -= fabs(DIST_BEFORE_COLLIDE / ray->vdir.y);
	ray->hit_pos.x = start->x;
	ray->hit_pos.y = start->y;
	gridbox_add_double(&ray->hit_pos.x, ray->vdir.x * ray->len);
	gridbox_add_double(&ray->hit_pos.y, ray->vdir.y * ray->len);
}

void	slide(t_map *map, t_player *player, t_ray *ray, double len_move, t_door *door_open_list)
{
	double	len_axis_remain;

	player->position = ray->hit_pos;
	len_move -= ray->len;
	if (ray->hit_side == 'w' || ray->hit_side == 'e')
	{
		len_axis_remain = fabs(ray->vdir.y) * len_move;
		ray->vdir.x = 0;
		ray->vdir.y = sign_double(ray->vdir.y);
		player_move_dda(ray, map, &player->position, door_open_list);
		if (ray->len > len_axis_remain)
			ray->len = len_axis_remain;
		gridbox_add_double(&player->y, ray->vdir.y * ray->len);
	}
	else
	{
		len_axis_remain = fabs(ray->vdir.x) * len_move;
		ray->vdir.x = sign_double(ray->vdir.x);
		ray->vdir.y = 0;
		player_move_dda(ray, map, &player->position, door_open_list);
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

void open_door_auto_near_player(t_position position, t_map *map, t_door *door_open_list)
{
	open_door_auto(map, position.x.grid, position.y.grid, door_open_list);
	if (position.x.box < 0.6)
		open_door_auto(map, position.x.grid - 1, position.y.grid, door_open_list);
	else
		open_door_auto(map, position.x.grid + 1, position.y.grid, door_open_list);
	if (position.y.box < 0.6)
		open_door_auto(map, position.x.grid, position.y.grid - 1, door_open_list);
	else
		open_door_auto(map, position.x.grid, position.y.grid + 1, door_open_list);
}

void	player_move(t_map *map, t_player *player, t_vec2i move, t_time_us dt, t_door *door_open_list)
{
	t_ray	ray;
	double	len_move;

	// open_door_auto_near_player(player->position, map, door_open_list);
	len_move = (SPEED_MOVE * dt) / USECOND_PER_SECOND;
	ray.vdir = player_dir_move_vec(player, move);
	player_move_dda(&ray, map, &player->position, door_open_list);
	if (ray.len <= len_move)
		slide(map, player, &ray, len_move, door_open_list);
	else
	{
		gridbox_add_double(&player->x, ray.vdir.x * len_move);
		gridbox_add_double(&player->y, ray.vdir.y * len_move);
	}
	open_door_auto_near_player(player->position, map, door_open_list);
}
