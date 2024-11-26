/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:53:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/26 01:32:40 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda_bonus.h"

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

int	is_collide(t_map *map, t_ray *ray)
{
	char	cell;

	cell = map->grid[ray->hit_pos.y.grid][ray->hit_pos.x.grid];
	if ((cell > '0' && cell <= '9') || cell == 'R' || cell == 'L' || cell == 'T')
	{
		ray->hit_texture = cell;
		return (TRUE);
	}
	return (FALSE);
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
		if (ray->len > len_max || is_collide(map, ray))
			break;
	}
}

void	dda_ray_set(t_ray *ray, t_dda *dda, t_player *player)
{
	ray->hit_pos.x = player->x;
	fixedpoint_add_double(&ray->hit_pos.x, ray->vdir.x * ray->len);
	ray->hit_pos.y = player->y;
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

void	dda(t_ray *ray, t_map *map, t_player *player, int len_max)
{
	t_dda	dda;

	dda.len_max = len_max;
	dda_init(&dda, &ray->vdir, &player->position, map);
	if (dda_no_need(map, player, dda, len_max) == TRUE)
	{
		ray->len = len_max + 1;
		return ;
	}
	ray->hit_pos.x.grid = player->x.grid;
	ray->hit_pos.y.grid = player->y.grid;
	dda_loop(&dda, ray, map, len_max);
	dda_ray_set(ray, &dda, player);
}
