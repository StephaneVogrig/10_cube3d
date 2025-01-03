/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_collide_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:31:15 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/03 11:38:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "door_collide_bonus.h"

t_axis	door_get_direction(t_map *map, t_position position)
{
	char	*cell_1;
	char	*cell_2;

	position.x.grid--;
	cell_1 = map_get_cell_ptr(map, &position);
	position.x.grid += 2;
	cell_2 = map_get_cell_ptr(map, &position);
	if (cell_is_wall_or_door(cell_1) && cell_is_wall_or_door(cell_2))
		return (AXIS_Y);
	position.x.grid--;
	position.y.grid--;
	cell_1 = map_get_cell_ptr(map, &position);
	position.y.grid += 2;
	cell_2 = map_get_cell_ptr(map, &position);
	if (cell_is_wall_or_door(cell_1) || cell_is_wall_or_door(cell_2))
		return (AXIS_X);
	return (AXIS_Y);
}

static int	is_looking_outside(t_door *door, double dir, float pos)
{
	if (dir <= 0 && pos < door->pos_side_down)
		return (TRUE);
	if (dir >= 0 && pos > door->pos_side_up)
		return (TRUE);
	return (FALSE);
}

int	is_hit_walledge(t_axis x, t_ray *ray, t_position *start, t_door *door)
{
	t_axis		y;

	y = (x == AXIS_X);
	if (start->axis[y].box != 0.0 && start->axis[y].box != 1.0)
		return (FALSE);
	if (start->axis[y].box == door->pos_edge_closed)
		return (FALSE);
	if (start->axis[x].box < door->pos_side_down
	|| start->axis[x].box > door->pos_side_up)
		return (FALSE);
	ray->hit_pos = *start;
	ray->hit_side = x + 2;
	ray->len = 0;
	return (TRUE);
}

int	is_outside_door(float start_x, float start_y, t_door *door)
{
	if (start_x <= door->pos_side_down
	|| start_x >= door->pos_side_up)
		return (TRUE);
	if 	(start_y == 0.0 || start_y == 1.0)
		return (TRUE);
	if (door->open_type == DOOR_OPEN_TYPE_L
	&& (start_y >= door->pos_edge))
		return (TRUE);
	if (door->open_type == DOOR_OPEN_TYPE_R
	&& (start_y <= door->pos_edge))
		return (TRUE);
	if (door->open_type == DOOR_OPEN_TYPE_T
	&& (start_y >= door->pos_edge)
	&& (start_y <= (1.0 - door->pos_edge)))
		return (TRUE);
	return (FALSE);
}

int is_collide_door_axis(t_axis x, t_ray *ray, t_position *start, t_door *door)
{
	if (is_looking_outside(door, ray->dirvec.axis[x], start->axis[x].box))
		return (FALSE);
	if (is_hit_walledge(x, ray, start, door))
		return (TRUE);
	if (is_hit_doorside(x, ray, start, door))
		return (TRUE);
	if (is_hit_dooredge(x, ray, start, door))
		return (TRUE);
	return (FALSE);
}

// start is the position of entrance of the ray on the border of the cell
// or the position of the player in the cell.
// So all is compute with value beetwen 0.0 and 1.0
int	is_collide_door(t_ray *ray, t_position *start, t_data *data)
{
	t_door	door;
	char	*cell;
	t_axis	x;

	cell = map_get_cell_ptr(&data->map, start);
	door_init(&door, cell, data->door_open_list);
	x = door_get_direction(&data->map, *start);
	if (is_inside_door(x, ray, start, &door))
		return (TRUE);
	if (is_looking_outside(&door, ray->dirvec.axis[x], start->axis[x].box))
		return (FALSE);
	if (is_hit_walledge(x, ray, start, &door))
		return (TRUE);
	if (is_hit_doorside(x, ray, start, &door))
		return (TRUE);
	if (is_hit_dooredge(x, ray, start, &door))
		return (TRUE);
	return (FALSE);
}
