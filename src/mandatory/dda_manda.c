/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_manda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:18:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/25 00:26:11 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "dda_manda.h"

char	check_collision(t_map *map, t_dda *dda)
{
	int in_wall;
	t_position	hit_pos;

	hit_pos = (t_position){{dda->x.current, 0.0}, {dda->y.current, 0.0}};
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

#include "window.h"

void	dda(t_ray *ray, t_position *start, t_data *data)
{
	t_dda	dda;

	dda_init(&dda, &ray->vdir, start, &data->map);
	dda.len_max = data->win.height;
	if (dda_no_need(&data->map, start, &dda) == TRUE)
	{
		ray->len = dda.len_max + 1;
		return ;
	}
	dda_loop(&dda, &data->map);
	dda_ray_set(ray, &dda, start);
}
