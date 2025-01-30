/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_manda.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:07 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/30 19:12:29 by svogrig          ###   ########.fr       */
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

void	draw_walls(t_window *win, t_ray *rays, t_data *data)
{
	t_strip	strip;
	double	img_x;
	int		x;

	strip.dark = data->dark;
	x = 0;
	while (x < win->width)
	{
		strip.screen_size = strip_screen_size(data->scale_screen, rays->len);
		if (strip.screen_size > 1)
		{
			strip.img = texture_hit(&data->textures, rays);
			img_x = hitpos_wall_texture(strip.img->width, rays);
			draw_wall(win, x, img_x, &strip);
		}
		rays++;
		x++;
	}
}
