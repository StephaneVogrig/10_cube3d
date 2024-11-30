/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:18:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/30 16:33:33 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "dda.h"

void	dda(t_ray *ray, t_map *map, t_position *start, int len_max)
{
	t_dda	dda;

	dda.len_max = len_max;
	dda_init(&dda, &ray->vdir, start, map);
	if (dda_no_need(map, start, dda, len_max) == TRUE)
	{
		ray->len = len_max + 1;
		return ;
	}
	ray->hit_pos.x.grid = start->x.grid;
	ray->hit_pos.y.grid = start->y.grid;
	dda_loop(&dda, ray, map, len_max);
	dda_ray_set(ray, &dda, start);
}
