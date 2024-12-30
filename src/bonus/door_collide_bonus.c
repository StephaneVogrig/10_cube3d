/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_collide_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:31:15 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/30 15:49:11 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "door_bonus.h"

static char	door_get_direction(t_map *map, t_position position)
{
	char	cell;

	position.x.grid--;
	cell = map_get_cell(map, &position);
	if (cell_is_wall(cell) || cell_is_door(cell))
		return ('y');
	position.x.grid += 2;
	cell = map_get_cell(map, &position);
	if (cell_is_wall(cell) || cell_is_door(cell))
		return ('y');
	return ('x');
}

static int	is_looking_outside(double dir_axis, float box_axis)
{
	if (dir_axis == 0
		|| (box_axis < 0.5 && dir_axis < 0)
		|| (box_axis > 0.5 && dir_axis > 0))
		return (TRUE);
	return (FALSE);
}

int	is_collide_door(t_ray *ray, t_map *map, t_position *position, t_door *door_open_list)
{
	ray->hit_pos = *position;
	if (door_get_direction(map, *position) == 'x')
	{
		if (is_looking_outside(ray->vdir.x, position->x.box))
			return (FALSE);
		ray->len = (0.5 - position->x.box) / ray->vdir.x;
		ray->hit_pos.y.box += ray->vdir.y * ray->len;
		if (!is_hit_door(ray->hit_pos.y.box, map_get_cell_ptr(map, position), door_open_list))
			return (FALSE);
		ray->hit_pos.x.box = 0.5;
		ray->hit_side = choose_side(ray->vdir.x > 0, 'W', 'E');
	}
	else
	{
		if (is_looking_outside(ray->vdir.y, position->y.box))
			return (FALSE);
		ray->len = (0.5 - position->y.box) / ray->vdir.y;
		ray->hit_pos.x.box += ray->vdir.x * ray->len;
		if (!is_hit_door(ray->hit_pos.x.box, map_get_cell_ptr(map, position), door_open_list))
			return (FALSE);
		ray->hit_pos.y.box = 0.5;
		ray->hit_side = choose_side(ray->vdir.x > 0, 'N', 'S');
	}
	ray->len = fabs(ray->len);
	return (TRUE);
}
