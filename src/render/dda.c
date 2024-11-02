/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:53:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/02 10:57:33 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "dda.h"


static inline int	is_outside_map(t_map *map, t_position *p)
{
	return (p->x.grid < 0
			|| p->y.grid < 0
			|| p->x.grid >= map->width
			|| p->y.grid >= map->height);
}


char map_get_grid(t_map *map, t_position *p)
{
	char	c;
	
	if (is_outside_map(map, p))
			return (AREA);
	c = map->grid[p->y.grid][p->x.grid];
	if (c == ' ')
		c = AREA;
	return (c);
}

/*
	compute basic data need for dda algorythme on one axis
		- unit distance for a step along the axis, set by ptr unit
		- length of ray if this axis is choosen, set by ptr side
		- step on the axis, set by return.
*/
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
		if (ray->len > len_max)
			break ;
		if (map_get_grid(map, &ray->hit_pos) == dda->collide)
			break ;
	}
}

static inline void	grid_box_add_double(t_grid_box	*gb, double d)
{
	int	i;

	d += gb->box;
	i = (int)d;
	gb->grid += i;
	gb->box = d - i;
	if (signbit(d))
		gb->box += 1.0;
}

void	grid_box_add_grid_box(t_grid_box *a, t_grid_box *b)
{
	a->box += b->box;
	if (a->box >= 1.0)
	{
		a->box -= 1.0;
		a->grid += 1;
	}
	else if (a->box < 0.0)
	{
		a->box += 1.0;
		a->grid -= 1;
	}
	a->grid += b->grid;
}

void	dda_ray_set(t_ray *ray, t_dda *dda, t_player *player, t_vec2d *raydir)
{
	if (ray->hit_side == 'x')
	{
		if (dda->x.step == 1)
			ray->hit_side = 'w';
		else
			ray->hit_side = 'e';
		ray->hit_pos.x.grid -= dda->x.step;
		ray->hit_pos.x.box = 0;
		ray->hit_pos.y = player->y;
		grid_box_add_double(&ray->hit_pos.y, raydir->y * ray->len);
	}
	else
	{
		if (dda->y.step == 1)
			ray->hit_side = 'n';
		else
			ray->hit_side = 's';
		ray->hit_pos.x = player->x;
		grid_box_add_double(&ray->hit_pos.x, raydir->x * ray->len);
		ray->hit_pos.y.grid -= dda->y.step;
		ray->hit_pos.y.box = 0;
	}
}

t_ray	dda(t_vec2d *raydir, t_map *map, t_player *player, int len_max)
{
	t_dda	dda;
	t_ray	ray;

	dda.len_max = len_max;
	dda_init(&dda, raydir, &player->position, map);
	if (dda_no_need(map, player, dda, len_max) == TRUE)
	{
		ft_bzero(&ray, sizeof(ray));
		ray.len = len_max + 1;
		return (ray);
	}
	ray.hit_pos.x.grid = player->x.grid;
	ray.hit_pos.y.grid = player->y.grid;
	dda_loop(&dda, &ray, map, len_max);
	dda_ray_set(&ray, &dda, player, raydir);
	return (ray);
}
