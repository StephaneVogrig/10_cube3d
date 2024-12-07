/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:20:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/07 20:47:13 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "dda_utils.h"
#include "window.h"

void	dda_init_axis(t_dda_axis *dda_axis, double ray_axis, t_gridbox start_axis)
{
	dda_axis->unit = fabs(1 / ray_axis);
	if (ray_axis < 0)
	{
		dda_axis->len = start_axis.box * dda_axis->unit;
		dda_axis->step = -1;
	}
	else
	{
		dda_axis->len = (1 - start_axis.box) * dda_axis->unit;
		dda_axis->step = 1;
	}
	dda_axis->current = start_axis.grid;
}

void	dda_init(t_dda *dda, t_vec2d *ray_vec, t_position *start, t_map *map)
{
	dda_init_axis(&dda->x, ray_vec->x, start->x);
	dda_init_axis(&dda->y, ray_vec->y, start->y);
	if (map_get_cell(map, start) == WALL)
		dda->collide = AREA;
	else
		dda->collide = WALL;
	dda->len_max = WIN_H;
}

int	dda_no_need(t_map *map, t_position *start, t_dda *dda)
{
	if ((start->x.grid < 0 && dda->x.step == -1)
		|| (start->x.grid > map->width && dda->x.step == 1)
		|| (start->y.grid < 0 && dda->y.step == -1)
		|| (start->y.grid > map->height && dda->y.step == 1))
		return (TRUE);
	if (start->x.grid < -dda->len_max
		|| start->x.grid > map->width + dda->len_max
		|| start->y.grid < -dda->len_max
		|| start->y.grid > map->height + dda->len_max)
		return (TRUE);
	return (FALSE);
}

void	dda_ray_set(t_ray *ray, t_dda *dda, t_position *start)
{
	ray->len = dda->len;
	ray->hit_pos = *start;
	gridbox_add_double(&ray->hit_pos.x, ray->vdir.x * ray->len);
	gridbox_add_double(&ray->hit_pos.y, ray->vdir.y * ray->len);
	if (dda->hit_side == 'x')
	{
		if (dda->x.step == 1)
			ray->hit_side = 'w';
		else
			ray->hit_side = 'e';
	}
	else
	{
		if (dda->y.step == 1)
			ray->hit_side = 'n';
		else
			ray->hit_side = 's';
	}
	ray->dark = dda->collide == AREA;
}

