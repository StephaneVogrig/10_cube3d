/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_collide_manda.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:53:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/28 00:14:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "map.h"
#include "ray.h"
#include "dda_utils.h"

int	is_collide(t_map *map, t_ray *ray, t_dda *dda)
{
	int in_wall;

	in_wall = dda->collide == AREA;
	if (in_wall)
		return (map_get_grid(map, &ray->hit_pos) == AREA);
	return (map_get_grid(map, &ray->hit_pos) == WALL);
}

