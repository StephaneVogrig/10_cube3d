/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:20:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/30 16:36:12 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "dda_utils.h"

void	dda_set(t_dda_ *dda, double ray_vec, double box)
{
	dda->unit = fabs(1 / ray_vec);
	if (ray_vec < 0)
	{
		dda->len = box * dda->unit;
		dda->step = -1;
	}
	else
	{
		dda->len = (1 - box) * dda->unit;
		dda->step = 1;
	}
}

void	dda_init(t_dda *dda, t_vec2d *ray_vec, t_position *p, t_map *map)
{
	dda_set(&dda->x, ray_vec->x, p->x.box);
	dda_set(&dda->y, ray_vec->y, p->y.box);
	if (map_get_grid(map, p) == WALL)
		dda->collide = AREA;
	else
		dda->collide = WALL;
}

int	dda_no_need(t_map *map, t_position *start, t_dda dda, int len_max)
{
	if ((start->x.grid < 0 && dda.x.step == -1)
		|| (start->x.grid > map->width && dda.x.step == 1)
		|| (start->y.grid < 0 && dda.y.step == -1)
		|| (start->y.grid > map->height && dda.y.step == 1))
		return (TRUE);
	if (start->x.grid < -len_max
		|| start->x.grid > map->width + len_max
		|| start->y.grid < -len_max
		|| start->y.grid > map->height + len_max)
		return (TRUE);
	return (FALSE);
}

void	dda_ray_set(t_ray *ray, t_dda *dda, t_position *start)
{
	ray->hit_pos.x = start->x;
	fixedpoint_add_double(&ray->hit_pos.x, ray->vdir.x * ray->len);
	ray->hit_pos.y = start->y;
	fixedpoint_add_double(&ray->hit_pos.y, ray->vdir.y * ray->len);
	if (ray->hit_side == 'x')
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

void	dda_loop(t_dda *dda, t_ray *ray, t_map *map, int len_max)
{
	while (TRUE)
	{
		if (dda->x.len < dda->y.len)
		{
			ray->hit_side = 'x';
			ray->len = dda->x.len;
			ray->hit_pos.x.grid += dda->x.step;
			dda->x.len += dda->x.unit;
		}
		else
		{
			ray->hit_side = 'y';
			ray->len = dda->y.len;
			ray->hit_pos.y.grid += dda->y.step;
			dda->y.len += dda->y.unit;
		}
		if (ray->len > len_max || is_collide(map, ray, dda))
			break ;
	}
}
