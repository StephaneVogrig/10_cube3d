/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:03:35 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/30 19:35:02 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda_bonus.h"

static int	dda_is_collide_door(t_dda *dda, t_position *start, t_ray *ray,
		t_data *data)
{
	t_ray		ray_temp;
	t_position	pos_temp;

	ray_temp.dirvec = ray->dirvec;
	pos_temp = *start;
	if (dda->hit_side == 'x')
	{
		pos_temp.x.grid = dda->x.current;
		pos_temp.x.box = choose_float(dda->x.step == -1, 1.0, 0.0);
		gridbox_add_double(&pos_temp.y, ray->dirvec.y * dda->len);
	}
	else
	{
		gridbox_add_double(&pos_temp.x, ray->dirvec.x * dda->len);
		pos_temp.y.grid = dda->y.current;
		pos_temp.y.box = choose_float(dda->y.step == -1, 1.0, 0.0);
	}
	if (!is_collide_door(&ray_temp, &pos_temp, data))
		return (FALSE);
	dda->hit_side = ray_temp.hit_side;
	dda->len += ray_temp.len;
	return (TRUE);
}

char	*check_collision(t_dda *dda, t_position *start, t_ray *ray,
		t_data *data)
{
	t_position	cell_pos;
	char		*cell;
	int			in_wall;

	cell_pos = position(dda->x.current, 0.0, dda->y.current, 0.0);
	cell = map_get_cell_ptr(&data->map, &cell_pos);
	in_wall = dda->collide != WALL;
	if (in_wall)
	{
		if (cell_is_wall(cell))
			return (NULL);
		return (cell);
	}
	if (cell_is_wall(cell))
	{
		return (cell);
	}
	if (cell_is_door(cell))
		if (dda_is_collide_door(dda, start, ray, data))
			return (cell);
	return (NULL);
}

static char	*dda_loop(t_dda *dda, t_position *start, t_ray *ray, t_data *data)
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
		hit = check_collision(dda, start, ray, data);
	}
	return (hit);
}

void	dda(t_ray *ray, t_position *start, t_data *data)
{
	t_dda	dda;

	dda_init(&dda, &ray->dirvec, start, &data->map);
	dda.len_max = data->win.height;
	if (dda_no_need(&data->map, start, &dda) == TRUE)
	{
		ray->len = dda.len_max + 1;
		return ;
	}
	ray->hit_cell = dda_loop(&dda, start, ray, data);
	if (dda.hit_side == 'x' || dda.hit_side == 'y')
		dda_ray_set(ray, &dda, start);
	else
	{
		ray->len = dda.len;
		ray->hit_pos = *start;
		gridbox_add_double(&ray->hit_pos.x, ray->dirvec.x * ray->len);
		gridbox_add_double(&ray->hit_pos.y, ray->dirvec.y * ray->len);
		ray->hit_side = dda.hit_side;
		if (ray->hit_side == SIDE_DOOR_X || ray->hit_side == SIDE_EDGE_Y)
			ray->hit_axis = 'x';
		else
			ray->hit_axis = 'y';
	}
}
