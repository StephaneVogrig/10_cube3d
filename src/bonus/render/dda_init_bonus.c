/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:21:36 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/01 19:13:38 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

# include "dda_utils.h"

void	dda_init(t_dda *dda, t_vec2d *ray_vec, t_position *p, t_map *map)
{
	dda_set(&dda->x, ray_vec->x, p->x.box);
	dda_set(&dda->y, ray_vec->y, p->y.box);
	if (map_get_cell(map, p) == WALL)
		dda->collide = AREA;
	else
		dda->collide = WALL;
}
