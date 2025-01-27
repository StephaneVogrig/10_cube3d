/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_manda.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:07 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:02:42 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_walls_manda.h"

t_texture	*texture_hit(t_textures *textures, t_ray *ray)
{
	if (ray->hit_axis == 'y')
	{
		if (ray->hit_side == 'N')
			return (&textures->north);
		return (&textures->south);
	}
	if (ray->hit_side == 'E')
		return (&textures->east);
	return (&textures->west);
}

void	draw_walls(t_window *win, t_ray *rays, t_textures *textures,
		double scale)
{
	t_strip	strip;
	double	img_x;
	int		x;

	x = 0;
	while (x < win->width)
	{
		strip.screen_size = strip_screen_size(scale, rays->len);
		if (strip.screen_size > 1)
		{
			strip.img = texture_hit(textures, rays);
			img_x = hitpos_wall_texture(strip.img->width, rays);
			strip.dark = rays->dark;
			draw_wall(win, x, img_x, &strip);
		}
		rays++;
		x++;
	}
}
