/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_collide_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:53:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/26 19:54:29 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "ray.h"

int	is_collide(t_map *map, t_ray *ray, int in_wall)
{
	char	cell;

	cell = map->grid[ray->hit_pos.y.grid][ray->hit_pos.x.grid];
	if (in_wall)
	{
		if (cell == '0')
			return (FALSE);
	}
	else if ((cell < '1' || cell > '9') && cell != 'R' && cell != 'L' && cell != 'T')
		return (FALSE);
	ray->hit_texture = cell;
	return (TRUE);
}

