/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:03:35 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/20 17:40:39 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "dda_bonus.h"
#include "door_bonus.h"

static float	hit_position_on_door(t_gridbox start_axis, t_dda_axis *dda_axis, double len)
{
	gridbox_add_double(&start_axis, len / dda_axis->unit * dda_axis->step);
	return (start_axis.box);
}

static int	ray_hit_wall_before_door(double ray_len, double dda_axis_len)
{
	return (ray_len > dda_axis_len);
}

static char	*check_collide_door(t_dda *dda, char *cell, t_position *start, t_door *door_open_list)
{
	double	ray_len;
	double	hit_pos_on_door;

	ray_len = dda->len;
	if (dda->hit_side == 'x')
	{
		ray_len += dda->x.unit / 2;
		if (ray_hit_wall_before_door(ray_len, dda->y.len))
			return (NULL);
		hit_pos_on_door = hit_position_on_door(start->y, &dda->y, ray_len);
		if (!is_hit_door(hit_pos_on_door, cell, door_open_list))
			return (NULL);
	}
	else
	{
		ray_len += dda->y.unit / 2;
		if (ray_hit_wall_before_door(ray_len, dda->x.len))
			return (NULL);
		hit_pos_on_door = hit_position_on_door(start->x, &dda->x, ray_len);
		if (!is_hit_door(hit_pos_on_door, cell, door_open_list))
			return (NULL);
	}
	dda->len = ray_len;
	return (cell);
}

int	cell_is_wall(char cell)
{
	if (cell > '0' && cell <= '9')
		return (TRUE);
	return (FALSE);
}

static char	door_get_direction(t_map *map, t_position position)
{
	char	cell;

	position.x.grid--;
	cell = map_get_cell(map, &position);
	if (cell_is_wall(cell) || cell_is_door(cell))
		return ('y');
	position.x.grid += 2;
	cell = map_get_cell(map, &position);
	if (cell_is_wall(cell) || cell_is_door(cell))
		return ('y');
	return ('x');
}

static int is_collide_door(t_ray *ray, t_map *map, t_position *position, t_door *door_open_list)
{
	double	delta_axis;

	ray->hit_pos = *position;
	if (door_get_direction(map, *position) == 'x')
	{
		if (ray->vdir.x == 0.0
			|| (position->x.box < 0.5 && ray->vdir.x < 0)
			|| (position->x.box > 0.5 && ray->vdir.x > 0))
			return (FALSE);
		delta_axis = 0.5 - position->y.box;
		ray->hit_pos.y.box += (ray->vdir.y / ray->vdir.x) * delta_axis;
		if (!is_hit_door(ray->hit_pos.y.box, map_get_cell_ptr(map, position),door_open_list))
			return (FALSE);
		ray->hit_pos.x.box = 0.5;
		if (ray->vdir.x > 0)
			ray->hit_side = 'W';
		else
			ray->hit_side = 'E';
		ray->len = fabs(delta_axis / ray->vdir.x);
	}
	else
	{
		if (ray->vdir.y == 0.0
			|| (position->y.box < 0.5 && ray->vdir.y < 0)
			|| (position->y.box > 0.5 && ray->vdir.y > 0))
			return (FALSE);
		delta_axis = 0.5 - position->y.box;
		ray->hit_pos.x.box += (ray->vdir.x / ray->vdir.y) * delta_axis;
		if (!is_hit_door(ray->hit_pos.x.box, map_get_cell_ptr(map, position),door_open_list))
			return (FALSE);
		ray->hit_pos.y.box = 0.5;
		if (ray->vdir.y > 0)
			ray->hit_side = 'N';
		else
			ray->hit_side = 'S';
		ray->len = fabs(delta_axis / ray->vdir.y);
	}
	return (TRUE);
}

char	*check_collision(t_map *map, t_dda *dda, t_position *start, t_door *door_open_list)
{
	t_position	cell_pos;
	char		*cell;
	int			in_wall;

	cell_pos = (t_position){{dda->x.current, 0.0}, {dda->y.current, 0.0}};
	cell = map_get_cell_ptr(map, &cell_pos);
	in_wall = dda->collide != WALL;
	if (in_wall)
	{
		if (cell_is_wall(*cell))
			return (NULL);
		return (cell);
	}
	if (cell_is_wall(*cell))
	{
		return (cell);
	}
	if (cell_is_door(*cell))
		return (check_collide_door(dda, cell, start, door_open_list));
	return (NULL);
}

static char	*dda_loop(t_dda *dda, t_map *map, t_position *start, t_door *door_open_list)
{
	char	*hit;

	hit = NULL;
	while (hit == NULL)
	{
		if (dda->x.len < dda->y.len)
		{
			dda->hit_side = 'x';
			dda->len = dda->x.len;
			dda->x.current += dda->x.step;
			dda->x.len += dda->x.unit;
		}
		else
		{
			dda->hit_side = 'y';
			dda->len = dda->y.len;
			dda->y.current += dda->y.step;
			dda->y.len += dda->y.unit;
		}
		if (dda->len > dda->len_max)
			break ;
		hit = check_collision(map, dda, start, door_open_list);
	}
	return (hit);
}

void	dda(t_ray *ray, t_map *map, t_position *start, t_door *door_open_list)
{
	t_dda	dda;
	char	*cell;

	cell = map_get_cell_ptr(map, start);
	if (cell_is_door(*cell)
		&& (is_collide_door(ray, map, start, door_open_list)))
	{
		ray->hit_cell = cell;
		ray->dark = 0;
		return ;
	}
	dda_init(&dda, &ray->vdir, start, map);
	if (dda_no_need(map, start, &dda) == TRUE)
	{
		ray->len = dda.len_max + 1;
		return ;
	}
	ray->hit_cell = dda_loop(&dda, map, start, door_open_list);
	dda_ray_set(ray, &dda, start);
}
