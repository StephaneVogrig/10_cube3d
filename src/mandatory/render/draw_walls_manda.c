/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_manda.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:07 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/27 02:34:07 by svogrig          ###   ########.fr       */
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

void	draw_walls(t_window *win, t_ray *rays, t_textures *textures, double scale)
{
	t_strip strip;
	double	img_x;
	int		x;

	x = 0;
	while (x < win->width)
	{
		strip.screen_size = strip_screen_size(scale, rays->len);
		if (strip.screen_size > 1)
		{
			strip.img = texture_hit(textures, rays);
			img_x = x_hit_in_texture(strip.img, rays);
			strip.dark = rays->dark;
			draw_wall(win, x, img_x, &strip);
		}
		rays++;
		x++;
	}
}
