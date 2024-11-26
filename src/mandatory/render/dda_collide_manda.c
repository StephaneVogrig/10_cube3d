/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils_manda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:53:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/26 19:25:06 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "ray.h"

int	is_collide(t_map *map, t_ray *ray, int in_wall)
{
	if (in_wall)
		return (map_get_grid(map, &ray->hit_pos) == AREA);
	return (map_get_grid(map, &ray->hit_pos) == WALL);
}

