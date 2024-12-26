/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:07 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/26 10:55:41 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "draw_walls_bonus.h"
#include "map.h"

int	x_hit_on_texture_door(t_texture *texture, t_ray *ray, t_door *door_open_list)
{
	float	hit_on_texture;
	float	opening_rate;

	if (ray->hit_side == 'N' || ray->hit_side == 'S')
		hit_on_texture = ray->hit_pos.x.box;
	else
		hit_on_texture = ray->hit_pos.y.box;
	opening_rate = 1 - door_get_closing_rate(ray->hit_cell, door_open_list);
	if (*(ray->hit_cell) == 'R')
		hit_on_texture -= opening_rate;
	else if (*(ray->hit_cell) == 'L')
		hit_on_texture += opening_rate;
	else
	{
		if (hit_on_texture < 0.5)
			hit_on_texture += opening_rate / 2;
		else
			hit_on_texture -= opening_rate / 2;
	}
	return (hit_on_texture * (texture->width - 1));
}

int	x_hit_in_texture(t_texture *texture, t_ray *ray, t_door *door_open_list)
{
	if (cell_is_door(*(ray->hit_cell)))
		return (x_hit_on_texture_door (texture, ray, door_open_list));
	if (ray->hit_side == 'N')
		return ((1 - ray->hit_pos.x.box) * (texture->width - 1));
	if (ray->hit_side == 'S')
		return (ray->hit_pos.x.box * (texture->width - 1));
	if (ray->hit_side == 'E')
		return ((1 - ray->hit_pos.y.box) * (texture->width - 1));
	return (ray->hit_pos.y.box * (texture->width - 1));
}

void	draw_walls(t_window *win, t_ray *rays, t_asset *textures, t_door *door_open_list)
{
	t_wall_draw draw;
	int		x;

	x = 0;
	while (x < win->width)
	{
		draw.img_screen_size.y = wall_height(win, rays->len);
		if (draw.img_screen_size.y > 1)
		{
			draw.img = asset_get_texture_ptr(textures, rays->hit_cell, rays->hit_side);
			draw.img_start.x = x_hit_in_texture(draw.img, rays, door_open_list);
			draw.dark = rays->dark;
			draw_wall(win, x, &draw);
		}
		rays++;
		x++;
	}
}
