/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_collide_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:31:15 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/01 12:28:09 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_collide_bonus.h"

static inline
int	is_looking_outside(t_door *door, double dir, float pos)
{
	if (dir <= 0 && pos < door->pos_side_down)
		return (TRUE);
	if (dir >= 0 && pos > door->pos_side_up)
		return (TRUE);
	return (FALSE);
}

static inline
int	is_hit_walledge(t_axis x, t_ray *ray, t_position *start, t_door *door)
{
	t_axis	y;

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

/*
start is the position of entrance of the ray on the border of the cell
or the position of the player in the cell.
So all is compute with value beetwen 0.0 and 1.0
*/
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
