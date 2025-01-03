/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_hit_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:50:59 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/03 11:49:21 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "door_collide_bonus.h"

int is_hit_door(float hit_pos, t_door *door)
{
	if (hit_pos < 0.0 || hit_pos > 1.0)
		return (FALSE);
	if (door->open_type == DOOR_OPEN_TYPE_L && hit_pos > door->pos_edge)
		return (FALSE);
	if (door->open_type == DOOR_OPEN_TYPE_R && hit_pos < door->pos_edge)
		return (FALSE);
	if (door->open_type == DOOR_OPEN_TYPE_T
		&& hit_pos > door->pos_edge
		&& hit_pos < 1 - door->pos_edge)
		return (FALSE);
	return (TRUE);
}

int	is_hit_doorside(t_axis x, t_ray *ray, t_position *start, t_door *door)
{
	float	pos_door;
	float	hit_pos;
	t_axis	y;

	y = (x == AXIS_X);
	if (ray->dirvec.axis[x] == 0)
		return (FALSE);
	if (start->axis[x].box > door->pos_side_down
	&& start->axis[x].box < door->pos_side_up)
		return (FALSE);
	if (ray->dirvec.axis[x] < 0)
		pos_door = door->pos_side_up;
	else
		pos_door = door->pos_side_down;
	ray->len = (pos_door - start->axis[x].box) / ray->dirvec.axis[x];
	hit_pos = start->axis[y].box + ray->dirvec.axis[y] * ray->len;
	if (!is_hit_door(hit_pos, door))
		return (FALSE);
	ray->hit_pos = *start;
	ray->hit_pos.axis[x].box = pos_door;
	ray->hit_pos.axis[y].box = hit_pos;
	ray->hit_side = x;
	ray->len = fabs(ray->len);
	return (TRUE);
}

int	is_looking_edge(float pos_start, float pos_edge, double dir, t_door *door)
{
	if (dir == 0)
		return (FALSE);
	if (door->open_type == DOOR_OPEN_TYPE_L
	&& (pos_start < pos_edge || dir > 0))
		return (FALSE);
	if (door->open_type == DOOR_OPEN_TYPE_R
	&& (pos_start > pos_edge || dir < 0))
		return (FALSE);
	return (TRUE);
}

int	is_hit_edge(float hit_pos, t_door *door)
{
	if ((hit_pos < door->pos_side_down
	||  hit_pos > door->pos_side_up))
		return (FALSE);
	return (TRUE);
}

int	is_hit_dooredge(t_axis x, t_ray *ray, t_position *start, t_door *door)
{
	float	pos_edge;
	float	hit_pos;
	t_axis	y;

	y = y_with_x(x);
	if (ray->dirvec.axis[y] == 0)
		return (FALSE);
	pos_edge = door->pos_edge;
	if (door->open_type == DOOR_OPEN_TYPE_T && ray->dirvec.axis[y] > 0)
		pos_edge = 1.0 - pos_edge;
	if (!is_looking_edge(start->axis[y].box, pos_edge, ray->dirvec.axis[y], door))
		return (FALSE);
	ray->len = (pos_edge - start->axis[y].box) / ray->dirvec.axis[y];
	hit_pos = start->axis[x].box + ray->dirvec.axis[x] * ray->len;
	if (!is_hit_edge(hit_pos, door))
		return (FALSE);
	ray->hit_pos = *start;
	ray->hit_pos.axis[x].box = hit_pos;
	ray->hit_pos.axis[y].box = pos_edge;
	ray->hit_side = x + 2;
	ray->len = fabs(ray->len);
	return (TRUE);
}
