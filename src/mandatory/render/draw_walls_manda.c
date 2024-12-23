/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_manda.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:07 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/23 16:32:31 by svogrig          ###   ########.fr       */
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
	t_wall_draw draw;
	int		x;

	x = 0;
	while (x < win->width)
	{
		draw.img_screen_size.y = wall_height(win, rays->len);
		if (draw.img_screen_size.y > 1)
		{
			draw.img = texture_hit(textures, rays);
			draw.img_start.x = x_hit_in_texture(draw.img, rays);
			draw.dark = rays->dark;
			draw_wall(win, x, &draw);
		}
		rays++;
		x++;
	}
}
