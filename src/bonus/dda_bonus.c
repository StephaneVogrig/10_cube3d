/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:03:35 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/30 21:22:04 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "dda_bonus.h"

static int	dda_is_collide_door(t_dda *dda, t_map *map, t_position *start, t_door *door_open_list, t_ray *ray)
{
	t_ray		ray_temp;
	t_position	pos_temp;

	ray_temp.vdir = ray->vdir;
	pos_temp = *start;
	if (dda->hit_side == 'x')
	{
		pos_temp.x.grid = dda->x.current;
		pos_temp.x.box = choose_float(dda->x.step == -1, 1.0, 0.0);
		gridbox_add_double(&pos_temp.y, ray->vdir.y * dda->len);
	}
	else
	{
		gridbox_add_double(&pos_temp.x, ray->vdir.x * dda->len);
		pos_temp.y.grid = dda->y.current;
		pos_temp.y.box = choose_float(dda->y.step == -1, 1.0, 0.0);
	}
	if (!is_collide_door(&ray_temp, map, &pos_temp, door_open_list))
			return (FALSE);
	dda->len += ray_temp.len;
	if (ray_temp.hit_side == 'N' || ray_temp.hit_side == 'S')
		dda->hit_side = 'y';
	else
		dda->hit_side = 'x';
	return (TRUE);
}

char	*check_collision(t_dda *dda, t_map *map, t_position *start, t_door *door_open_list, t_ray *ray)
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
		if (dda_is_collide_door(dda, map, start, door_open_list, ray))
			return (cell);
	return (NULL);
}

static char	*dda_loop(t_dda *dda, t_map *map, t_position *start, t_door *door_open_list, t_ray *ray)
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
		hit = check_collision(dda, map, start, door_open_list, ray);
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
	ray->hit_cell = dda_loop(&dda, &data->map, start, data->door_open_list, ray);
	dda_ray_set(ray, &dda, start);
}
