/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_manda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:18:48 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/03 00:28:41 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda_manda.h"

static
char	check_collision(t_map *map, t_dda *dda, int dark)
{
	t_position	cell_hit_pos;

	cell_hit_pos = position(dda->x.current, 0.0, dda->y.current, 0.0);
	if (dark)
		return (map_get_cell(map, &cell_hit_pos) != WALL);
	return (map_get_cell(map, &cell_hit_pos) == WALL);
}

static
void	dda_loop(t_dda *dda, t_map *map, int dark)
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
		if (dda->len > dda->len_max || check_collision(map, dda, dark))
			break ;
	}
}

void	dda(t_ray *ray, t_position *start, t_data *data)
{
	t_dda	dda;

	dda_init(&dda, &ray->dirvec, start, data->scale_screen);
	if (dda_no_need(&data->map, start, &dda))
	{
		ray->len = dda.len_max + 1;
		ray->wall_screen_height = 0;
		return ;
	}
	dda_loop(&dda, &data->map, data->dark);
	dda_ray_set(ray, &dda, start, data->scale_screen);
	dda_ray_set_axis(ray, &dda);
}
