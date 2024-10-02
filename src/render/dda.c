/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:53:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/23 19:06:06 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "dda.h"

void	dda_init(t_dda *raylen, t_vec2i *step, t_vec2d *raydir, t_vec2d *box)
{
	raylen->unit.x = fabs(1 / raydir->x);
	raylen->unit.y = fabs(1 / raydir->y);
	if (raydir->x < 0)
	{
		step->x = -1;
		raylen->side.x = box->x * raylen->unit.x;
	}
	else
	{
		step->x = 1;
		raylen->side.x = (1 - box->x) * raylen->unit.x;
	}
	if (raydir->y < 0)
	{
		step->y = -1;
		raylen->side.y = box->y * raylen->unit.y;
	}
	else
	{
		step->y = 1;
		raylen->side.y = (1 - box->y) * raylen->unit.y;
	}
}

t_dda2	dda(t_vec2d *raydir, t_map *map, t_player *player)
{
	t_dda	raylen;
	t_dda2	ray;
	t_vec2i	step;

	dda_init(&raylen, &step, raydir, &player->box);
	ray.hit_pos.grid = player->grid;
	while (TRUE)
	{
		if (raylen.side.x < raylen.side.y)
		{
			ray.hit_side = 'x';
			ray.hit_pos.grid.x += step.x;
			raylen.side.x += raylen.unit.x;
		}
		else
		{
			ray.hit_side = 'y';
			ray.hit_pos.grid.y += step.y;
			raylen.side.y += raylen.unit.y;
		}
		if (ray.hit_pos.grid.x < 0 || ray.hit_pos.grid.y < 0 || ray.hit_pos.grid.x >= map->width || ray.hit_pos.grid.y >= map->height || map->grid[ray.hit_pos.grid.y][ray.hit_pos.grid.x] == '1')
			break;
	}
	// ray_compute(&ray, step, raylen, player, raydir);
	// new part
	double delta;
	if (ray.hit_side == 'x')
	{
		if (step.x == 1)
			ray.hit_side = 'w';
		else
			ray.hit_side = 'e';
		ray.len = raylen.side.x - raylen.unit.x;
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
		ray.len = raylen.side.y - raylen.unit.y;
		ray.hit_pos.grid.y = ray.hit_pos.grid.y - step.y;
		ray.hit_pos.box.y = 0;
		delta = player->box.x + raydir->x * ray.len;
		ray.hit_pos.grid.x = player->grid.x + (int)delta;
		ray.hit_pos.box.x = delta - (int)delta;
		if (delta < 0)
			ray.hit_pos.box.x += 1;
	}
	
	// printf("ray->hit_pos x: %i %f y: %i %f - ", ray.hit_pos.grid.x,	ray.hit_pos.box.x, ray.hit_pos.grid.y, ray.hit_pos.box.y);
	// printf("side: %c delta:%f\n", ray.hit_side, delta);
	
	// if (ray.hit_side == 'x')
	// {
	// 	ray.len = raylen.side.x - raylen.unit.x;
	// 	if (step.x == 1)
	// 		ray.hit_side = 'w';
	// 	else
	// 		ray.hit_side = 'e';
	// }
	// else
	// {
	// 	ray.len = raylen.side.y - raylen.unit.y;
	// 	if (step.y == 1)
	// 		ray.hit_side = 'n';
	// 	else
	// 		ray.hit_side = 's';
	// }
	// t_vec2d	intersect;
	
	// intersect.x = player->grid.x + player->box.x + raydir->x * ray.len ;
	// intersect.y = player->grid.y + player->box.y + raydir->y * ray.len;
	// ray.hit_pos.grid.x = (int)intersect.x;
	// ray.hit_pos.grid.y = (int)intersect.y;
	// ray.hit_pos.box.x = intersect.x - ray.hit_pos.grid.x;
	// ray.hit_pos.box.y = intersect.y - ray.hit_pos.grid.y;
	
	// printf("ray->hit_pos x: %i %f y: %i %f\n", ray.hit_pos.grid.x,	ray.hit_pos.box.x, ray.hit_pos.grid.y, ray.hit_pos.box.y);

	
	return (ray);
}
