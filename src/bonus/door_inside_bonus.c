/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_inside_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:40:41 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/03 11:50:41 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "door_bonus.h"

float	position_edge(int y, t_ray *ray, t_position *start, t_door *door)
{
	float	pos_edge;

	pos_edge = door->pos_edge;
	if (door->open_type == DOOR_OPEN_TYPE_T && start->axis[y].box > pos_edge)
		pos_edge = 1.0 - pos_edge;
	if (ray->dirvec.axis[y] > 0 && start->axis[y].box > pos_edge)
		pos_edge = 1.0;
	if (ray->dirvec.axis[y] < 0 && start->axis[y].box < pos_edge)
		pos_edge = 0.0;
	return (pos_edge);
}

float	position_side(int x, t_ray *ray, t_position *start, t_door *door)
{
	float	pos_side;

	if (ray->dirvec.axis[x] > 0)
	{
		if (start->axis[x].box < door->pos_side_down)
			pos_side = door->pos_side_down;
		else
			pos_side = door->pos_side_up;
	}
	else
	{
		if (start->axis[x].box > door->pos_side_up)
			pos_side = door->pos_side_up;
		else
			pos_side = door->pos_side_down;
	}
	return (pos_side);
}

t_lenpos	collide_side(int x, t_ray *ray, t_position *start, t_door *door)
{
	t_lenpos	side;

	if (ray->dirvec.axis[x] == 0)
		side.len = INT_MAX;
	else
	{
		side.pos = position_side(x, ray, start, door);
		side.len = (side.pos - start->axis[x].box) / ray->dirvec.axis[x];
	}
	return (side);
}

t_lenpos	collide_edge(int y, t_ray *ray, t_position *start, t_door *door)
{
	t_lenpos	edge;

	if (ray->dirvec.axis[y] == 0)
		edge.len = INT_MAX;
	else
	{
		edge.pos = position_edge(y, ray, start, door);
		edge.len = (edge.pos - start->axis[y].box) / ray->dirvec.axis[y];
	}
	return (edge);
}

int	is_inside_door(t_axis x, t_ray *ray, t_position *start, t_door *door)
{
	t_lenpos	side;
	t_lenpos	edge;
	t_axis		y;

	y = y_with_x(x);
	if (is_outside_door(start->axis[x].box, start->axis[y].box, door))
		return (FALSE);
	side = collide_side(x, ray, start, door);
	edge = collide_edge(y, ray, start, door);
	ray->hit_pos = *start;
	if (side.len <= edge.len)
	{
		ray->hit_side = x;
		ray->hit_pos.axis[x].box = side.pos;
		ray->hit_pos.axis[y].box += ray->dirvec.axis[y] * side.len;
		ray->len = fabs(side.len);
	}
	else
	{
		ray->hit_side = x + 2;
		ray->hit_pos.axis[x].box += ray->dirvec.axis[x] * edge.len;
		ray->hit_pos.axis[y].box = edge.pos;
		ray->len = fabs(edge.len);
	}
	return (TRUE);
}
