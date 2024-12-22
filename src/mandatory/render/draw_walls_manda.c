/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_manda.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:07 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/22 23:45:10 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "draw_walls_manda.h"

int	x_hit_in_texture(t_texture *texture, t_ray *ray)
{
	if (ray->hit_side == 'N')
		return ((1 - ray->hit_pos.x.box) * (texture->width - 1));
	if (ray->hit_side == 'S')
		return (ray->hit_pos.x.box * (texture->width - 1));
	if (ray->hit_side == 'E')
		return ((1 - ray->hit_pos.y.box) * (texture->width - 1));
	return (ray->hit_pos.y.box * (texture->width - 1));
}

t_texture	*texture_hit(t_textures *textures, t_ray *ray)
{
	if (ray->hit_side == 'N')
		return (&textures->north);
	if (ray->hit_side == 'S')
		return (&textures->south);
	if (ray->hit_side == 'E')
		return (&textures->east);
	return (&textures->west);
}

void	draw_walls(t_window *win, t_ray *rays, t_textures *textures)
{
	t_wall	wall;
	int		x;

	x = 0;
	while (x < win->width)
	{
		wall.height = wall_height(win, rays->len);
		if (wall.height > 0)
		{
			wall.texture = texture_hit(textures, rays);
			wall.x_in_texture = x_hit_in_texture(wall.texture, rays);
			wall.texture_dy = (double)wall.texture->height / wall.height;
			draw_wall(win, x, &wall, rays->dark);
		}
		rays++;
		x++;
	}
}
