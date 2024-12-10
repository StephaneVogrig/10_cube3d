/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:07 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/10 19:03:06 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_walls_bonus.h"
#include "map.h"

int	x_hit_on_texture_door(t_texture *texture, t_ray *ray, t_door *door_open_list)
{
	float	hit_on_texture;
	float	opening_rate;

	if (ray->hit_side == 'n' || ray->hit_side == 's')
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
	if (ray->hit_side == 'n')
		return ((1 - ray->hit_pos.x.box) * (texture->width - 1));
	if (ray->hit_side == 's')
		return (ray->hit_pos.x.box * (texture->width - 1));
	if (ray->hit_side == 'e')
		return ((1 - ray->hit_pos.y.box) * (texture->width - 1));
	return (ray->hit_pos.y.box * (texture->width - 1));
}

void	draw_walls(t_window *win, t_ray *rays, t_asset *textures, t_door *door_open_list)
{
	t_wall	wall;
	int		x;

	x = 0;
	while (x < WIN_W)
	{
		wall.height = wall_height(rays->len);
		if (wall.height > 0)
		{
			wall.texture = asset_get_texture(textures, rays->hit_cell);
			wall.x_in_texture = x_hit_in_texture(wall.texture, rays, door_open_list);
			wall.texture_dy = (double)wall.texture->height / wall.height;
			draw_wall(win, x, &wall, rays->dark);
		}
		rays++;
		x++;
	}
}
