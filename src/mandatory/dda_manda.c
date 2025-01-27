/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_manda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:18:48 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 15:59:39 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda_manda.h"
#include "window.h"

char	check_collision(t_map *map, t_dda *dda)
{
	int			in_wall;
	t_position	hit_pos;

	hit_pos = position(dda->x.current, 0.0, dda->y.current, 0.0);
	in_wall = dda->collide != WALL;
	if (in_wall)
		return (map_get_cell(map, &hit_pos) != WALL);
	return (map_get_cell(map, &hit_pos) == WALL);
}

static void	dda_loop(t_dda *dda, t_map *map)
{
	while (TRUE)
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
		if (dda->len > dda->len_max || check_collision(map, dda))
			break ;
	}
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
	dda_loop(&dda, &data->map);
	dda_ray_set(ray, &dda, start);
}
