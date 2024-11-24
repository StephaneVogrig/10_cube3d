/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_manda.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:07 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 03:35:35 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "draw_walls_manda.h"

t_texture	*texture_hit(t_textures *textures, t_ray *ray)
{
	if (ray->hit_side == 'n')
		return (&textures->north);
	if (ray->hit_side == 's')
		return (&textures->south);
	if (ray->hit_side == 'e')
		return (&textures->east);
	return (&textures->west);
}

void	draw_walls(t_window *win, t_ray *rays, t_textures *textures)
{
	t_texture	*texture;
	int			x;

	x = 0;
	while (x < WIN_W)
	{
		texture = texture_hit(textures, rays);
		draw_wall(win, x, rays, texture);
		rays++;
		x++;
	}
}
