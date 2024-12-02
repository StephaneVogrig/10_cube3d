/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:03:35 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/02 22:35:09 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "dda.h"
#include "door_bonus.h"

static char	door_axis(t_map *map, t_position position)
{
	char	cell;

	position.x.grid--;
	cell = map_get_cell(map, &position);
	if (cell_is_wall(cell) || cell_is_door(cell))
		return ('x');
	position.x.grid += 2;
	cell = map_get_cell(map, &position);
	if (cell_is_wall(cell) || cell_is_door(cell))
		return ('x');
	return ('y');
}

static int check_collide_door(t_ray *ray, t_map *map, t_position *position)
{
	double	delta;

	ray->hit_pos = *position;
	if (door_axis(map, *position) == 'x')
	{
		if (ray->vdir.y == 0.0
			|| (position->y.box < 0.5 && ray->vdir.y < 0)
			|| (position->y.box > 0.5 && ray->vdir.y > 0))
			return (FALSE);
		delta = 0.5 - position->y.box;
		ray->hit_pos.x.box += (ray->vdir.x / ray->vdir.y) * delta;
		if (ray->hit_pos.x.box < 0.0 || ray->hit_pos.x.box > 1.0 )
			return (FALSE);
		ray->hit_pos.y.box = 0.5;
		if (ray->vdir.y > 0)
			ray->hit_side = 'n';
		else
			ray->hit_side = 's';
		ray->len = fabs(delta / ray->vdir.y);
	}
	else
	{
		if (ray->vdir.x == 0.0
			|| (position->x.box < 0.5 && ray->vdir.x < 0)
			|| (position->x.box > 0.5 && ray->vdir.x > 0))
			return (FALSE);
		delta = 0.5 - position->y.box;
		ray->hit_pos.y.box += (ray->vdir.y / ray->vdir.x) * delta;
		if (ray->hit_pos.y.box < 0.0 || ray->hit_pos.y.box > 1.0 )
			return (FALSE);
		ray->hit_pos.x.box = 0.5;
		if (ray->vdir.x > 0)
			ray->hit_side = 'w';
		else
			ray->hit_side = 'e';
		ray->len = fabs(delta / ray->vdir.x);
	}
	return (TRUE);
}

void	dda(t_ray *ray, t_map *map, t_position *start, int len_max)
{
	t_dda	dda;

	if (cell_is_door(map_get_cell(map, start))
		&& (check_collide_door(ray, map, start)))
	{
		ray->hit_texture = map_get_cell(map, start);
		ray->dark = 0;
		return ;
	}
	dda.len_max = len_max;
	dda_init(&dda, &ray->vdir, start, map);
	if (dda_no_need(map, start, dda, len_max) == TRUE)
	{
		ray->len = len_max + 1;
		return ;
	}
	ray->hit_pos.x.grid = start->x.grid;
	ray->hit_pos.y.grid = start->y.grid;
	dda_loop(&dda, ray, map, len_max);
	dda_ray_set(ray, &dda, start);
}
