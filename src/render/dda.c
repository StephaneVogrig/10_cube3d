/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:53:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/01 02:07:45 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"

/*
	compute basic data need for dda algorythme on one axis
		- unit distance for a step along the axis, set by ptr unit
		- length of ray if this axis is choosen, set by ptr side
		- step on the axis, set by return.
*/
void	dda_set(t_dda_ *d, double ray_vec, double box)
{
	d->unit = fabs(1 / ray_vec);
	if (ray_vec < 0)
	{
		d->len = box * d->unit;
		d->step = -1;
	}
	else
	{
		d->len = (1 - box) * d->unit;
		d->step = 1;
	}
}

void	dda_init(t_dda *raylen, t_vec2d *ray_vec, t_position *p)
{
	dda_set(&raylen->x, ray_vec->x, p->x.box);
	dda_set(&raylen->y, ray_vec->y, p->y.box);
}

int	dda_no_need(t_map *map, t_player *player, t_dda dda, int len_max)
{
	if ((player->x.grid < 0 && dda.x.step == -1)
		|| (player->x.grid > map->width && dda.x.step == 1)
		|| (player->y.grid < 0 && dda.y.step == -1)
		|| (player->y.grid > map->height && dda.y.step == 1))
		return (TRUE);
	if (player->x.grid < -len_max
		|| player->x.grid > map->width + len_max
		|| player->y.grid < -len_max
		|| player->y.grid > map->height + len_max)
		return (TRUE);
	return (FALSE);
}

void	dda_algo(t_dda *dda, t_ray *ray, t_map *map, int len_max)
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
		if (ray->len > len_max)
			break ;
		if (ray->hit_pos.x.grid < 0
				|| ray->hit_pos.y.grid < 0
				|| ray->hit_pos.x.grid >= map->width
				|| ray->hit_pos.y.grid >= map->height)
			continue ;
		if (map->grid[ray->hit_pos.y.grid][ray->hit_pos.x.grid] == WALL)
			break ;
	}
}

void	dda_ray_set(t_ray *ray, t_dda *dda, t_player *player, t_vec2d *raydir)
{
	double delta;
	
	if (ray->hit_side == 'x')
	{
		if (dda->x.step == 1)
			ray->hit_side = 'w';
		else
			ray->hit_side = 'e';
			
		ray->hit_pos.x.grid = ray->hit_pos.x.grid - dda->x.step;
		ray->hit_pos.x.box = 0;
		
		delta = player->y.box + raydir->y * ray->len;
		ray->hit_pos.y.grid = player->y.grid + (int)delta ;
		ray->hit_pos.y.box = delta - (int)delta;
		if (delta < 0)
			ray->hit_pos.y.box += 1;
	}
	else
	{
		if (dda->y.step == 1)
			ray->hit_side = 'n';
		else
			ray->hit_side = 's';

		delta = player->x.box + raydir->x * ray->len;
		ray->hit_pos.x.grid = player->x.grid + (int)delta;
		ray->hit_pos.x.box = delta - (int)delta;
		if (delta < 0)
			ray->hit_pos.x.box += 1;
		
		ray->hit_pos.y.grid = ray->hit_pos.y.grid - dda->y.step;
		ray->hit_pos.y.box = 0;
	}
}

t_ray	dda(t_vec2d *raydir, t_map *map, t_player *player, int len_max)
{
	t_dda	dda;
	t_ray	ray;

	dda_init(&dda, raydir, &player->position);
	if (dda_no_need(map, player, dda, len_max) == TRUE)
	{
		ft_bzero(&ray, sizeof(ray));
		ray.len = len_max + 1;
		return (ray);
	}
	ray.hit_pos.x.grid = player->x.grid;
	ray.hit_pos.y.grid = player->y.grid;
	dda_algo(&dda, &ray, map, len_max);
	dda_ray_set(&ray, &dda, player, raydir);
	return (ray);
}
