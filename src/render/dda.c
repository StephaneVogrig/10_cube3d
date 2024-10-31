/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:53:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/31 16:40:55 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"

/*
	compute basic data need for dda algorythme on one axis
		- unit distance for a step, set by ptr unit
		- length between player and box border, set by ptr side
		- step value, set by return.
*/
int	dda_set(double *unit, double *side, double ray_vec, double box)
{
	*unit = fabs(1 / ray_vec);
	if (ray_vec < 0)
	{
		*side = box * *unit;
		return (-1);
	}	
	*side = (1 - box) * *unit;
	return (1);
}

void	dda_init(t_dda *raylen, t_vec2i *step, t_vec2d *ray_vec, t_vec2d *box)
{
	step->x = dda_set(&raylen->unit.x, &raylen->side.x, ray_vec->x, box->x);
	step->y = dda_set(&raylen->unit.y, &raylen->side.y, ray_vec->y, box->y);
		printf("ray_vec:%f unit: %f\n", ray_vec->x, raylen->unit.x);

}

t_ray	dda(t_vec2d *raydir, t_map *map, t_player *player, int len_max)
{
	t_dda	raylen;
	t_ray	ray;
	t_vec2i	step;

	dda_init(&raylen, &step, raydir, &player->box);
	ray.hit_pos.grid = player->grid;
	while (TRUE)
	{
		if (raylen.side.x < raylen.side.y)
		{
			ray.hit_side = 'x';
			ray.len = raylen.side.x;
			ray.hit_pos.grid.x += step.x;
			raylen.side.x += raylen.unit.x;
		}
		else
		{
			ray.hit_side = 'y';
			ray.len = raylen.side.y;
			ray.hit_pos.grid.y += step.y;
			raylen.side.y += raylen.unit.y;
		}
		if (ray.len > len_max)
			break ;
		if (ray.hit_pos.grid.x < 0 \
				|| ray.hit_pos.grid.y < 0 \
				|| ray.hit_pos.grid.x >= map->width \
				|| ray.hit_pos.grid.y >= map->height)
			continue ;
		if (map->grid[ray.hit_pos.grid.y][ray.hit_pos.grid.x] == WALL)
			break ;
	}

	double delta;
	if (ray.hit_side == 'x')
	{
		if (step.x == 1)
			ray.hit_side = 'w';
		else
			ray.hit_side = 'e';
			
		ray.hit_pos.grid.x = ray.hit_pos.grid.x - step.x;
		ray.hit_pos.box.x = 0;
		
		delta = player->box.y + raydir->y * ray.len;
		ray.hit_pos.grid.y = player->grid.y + (int)delta ;
		ray.hit_pos.box.y = delta - (int)delta;
		if (delta < 0)
			ray.hit_pos.box.y += 1;
	}
	else
	{
		if (step.y == 1)
			ray.hit_side = 'n';
		else
			ray.hit_side = 's';
			
		delta = player->box.x + raydir->x * ray.len;
		ray.hit_pos.grid.x = player->grid.x + (int)delta;
		ray.hit_pos.box.x = delta - (int)delta;
		if (delta < 0)
			ray.hit_pos.box.x += 1;
		
		ray.hit_pos.grid.y = ray.hit_pos.grid.y - step.y;
		ray.hit_pos.box.y = 0;
	}
	return (ray);
}
