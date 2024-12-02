/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_collide_manda.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:53:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/01 19:13:38 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "map.h"
#include "ray.h"
#include "dda_utils.h"

int	is_collide(t_map *map, t_ray *ray, t_dda *dda)
{
	int in_wall;

	in_wall = dda->collide != WALL;
	if (in_wall)
		return (map_get_cell(map, &ray->hit_pos) != WALL);
	return (map_get_cell(map, &ray->hit_pos) == WALL);
}

