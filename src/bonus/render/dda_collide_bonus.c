/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_collide_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:53:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/28 00:14:14 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "map.h"
#include "ray.h"
#include "dda_utils.h"

int	check_collide_door(t_ray *ray, t_dda *dda, char cell)
{
	double ray_len;

	ray_len = ray->len;
	if (ray->hit_side == 'x')
	{
		ray_len += dda->x.unit / 2;
		if (ray_len > dda->y.len)
			return (FALSE);
	}
	else
	{
		ray_len += dda->y.unit / 2;
		if (ray_len > dda->x.len)
			return (FALSE);
	}
	ray->len = ray_len;
	ray->hit_texture = cell;
	return (TRUE);
}

int	cell_is_wall(char cell)
{
	if (cell > '0' && cell <= '9')
		return (TRUE);
	return (FALSE);
}

int	cell_is_door(char cell)
{
	if (cell == 'R' || cell == 'L' || cell == 'T')
		return (TRUE);
	return (FALSE);
}

int	is_collide(t_map *map, t_ray *ray, t_dda *dda)
{
	char	cell;
	int		in_wall;

	in_wall = dda->collide == AREA;
	cell = map->grid[ray->hit_pos.y.grid][ray->hit_pos.x.grid];
	if (in_wall)
	{
		if (cell_is_wall(cell))
			return (FALSE);
		ray->hit_texture = cell;
		return (TRUE);
	}
	if (cell_is_wall(cell))
	{
		ray->hit_texture = cell;
		return (TRUE);
	}
	if (cell_is_door(cell))
		return (check_collide_door(ray, dda, cell));
	return (FALSE);
}
