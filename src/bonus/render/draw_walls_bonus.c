/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:07 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 15:11:10 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_walls_bonus.h"

float	hitpos_edge_texture(float hitpos, t_door *door, int texture_width)
{
	float	hitpos_texture;

	hitpos_texture = hitpos - door->pos_side_down;
	hitpos_texture /= door->pos_side_up - door->pos_side_down;
	hitpos_texture *= (texture_width - 1);
	return (hitpos_texture);
}

float	hitpos_side_texture(float hitpos, t_door *door, int texture_width)
{
	float	hitpos_texture;

	if (door->open_type == DOOR_OPEN_TYPE_R)
		hitpos_texture = hitpos - door->pos_edge;
	if (door->open_type == DOOR_OPEN_TYPE_L)
		hitpos_texture = hitpos + 1 - door->pos_edge;
	if (door->open_type == DOOR_OPEN_TYPE_T)
	{
		if (hitpos < 0.5)
			hitpos_texture = hitpos + 0.5 - door->pos_edge;
		else
			hitpos_texture = hitpos - (0.5 - door->pos_edge);
	}
	hitpos_texture *= (texture_width - 1);
	return (hitpos_texture);
}

int	hitpos_door_texture(int texture_width, t_ray *ray,
		t_door_open *door_open_list)
{
	t_door	door;

	door_init(&door, ray->hit_cell, door_open_list);
	if (ray->hit_side == SIDE_EDGE_X)
		return (hitpos_edge_texture(ray->hit_pos.x.box, &door, texture_width));
	if (ray->hit_side == SIDE_EDGE_Y)
		return (hitpos_edge_texture(ray->hit_pos.y.box, &door, texture_width));
	if (ray->hit_side == SIDE_DOOR_X)
		return (hitpos_side_texture(ray->hit_pos.y.box, &door, texture_width));
	if (ray->hit_side == SIDE_DOOR_Y)
		return (hitpos_side_texture(ray->hit_pos.x.box, &door, texture_width));
	return (0.0);
}

double	hitpos_texture(t_ray *ray, t_data *data, int width)
{
	if (cell_is_door(ray->hit_cell))
		return (hitpos_door_texture(width, ray, data->door_open_list));
	return (hitpos_wall_texture(width, ray));
}

void	draw_walls(t_window *win, t_ray *ray, t_data *data)
{
	t_strip	strip;
	double	img_x;
	int		x;

	strip.dark = data->dark;
	x = 0;
	while (x < win->width)
	{
		strip.screen_size = strip_screen_size(data->scale_screen, ray->len);
		if (strip.screen_size > 1)
		{
			strip.img = asset_get_texture_ptr(&data->textures, ray->hit_cell,
					ray->hit_side);
			img_x = hitpos_texture(ray, data, strip.img->width);
			strip.fog = fog_compute(ray->len, data->fog_enable);
			draw_wall(win, x, img_x, &strip);
		}
		ray++;
		x++;
	}
}
