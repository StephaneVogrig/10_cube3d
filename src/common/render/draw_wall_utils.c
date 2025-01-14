/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils .c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:07:24 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/08 13:14:36 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "draw_wall_utils.h"

int	hitpos_wall_texture(int texture_width, t_ray *ray)
{
	if (ray->hit_axis == 'y')
	{
		if (ray->hit_side == 'N')
			return ((1 - ray->hit_pos.x.box) * (texture_width - 1));
		return (ray->hit_pos.x.box * (texture_width - 1));
	}
	if (ray->hit_side == 'E')
		return ((1 - ray->hit_pos.y.box) * (texture_width - 1));
	return (ray->hit_pos.y.box * (texture_width - 1));
}
