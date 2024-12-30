/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:03:35 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/30 15:42:20 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "dda_bonus.h"

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

void	dda(t_ray *ray, t_position *start, t_data *data)
{
	t_dda	dda;
	char	*cell;

	cell = map_get_cell_ptr(&data->map, start);
	if (cell_is_door(*cell)
		&& (is_collide_door(ray, &data->map, start, data->door_open_list)))
	{
		ray->hit_cell = cell;
		ray->dark = 0;
		return ;
	}
	dda_init(&dda, &ray->vdir, start, &data->map);
	dda.len_max = data->win.height;
	if (dda_no_need(&data->map, start, &dda) == TRUE)
	{
		ray->len = dda.len_max + 1;
		return ;
	}
	ray->hit_cell = dda_loop(&dda, &data->map, start, data->door_open_list);
	dda_ray_set(ray, &dda, start);
}
