/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:07:24 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/26 02:34:48 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_wall.h"

void	draw_wall_init_loop(int *y, int *y_max, double *texture_y, t_wall *wall)
{
	if (wall->height < WIN_H && wall->height > 0.0)
	{
		*y = (WIN_H - wall->height) / 2;
		*y_max = *y + wall->height;
		*texture_y = 0.0;
	}
	else
	{
		*y = 0;
		*y_max = WIN_H;
		*texture_y = (wall->texture->height - wall->texture_dy * WIN_H) / 2;
	}
}

void	draw_wall_big_pixel(t_window *win, int x, t_wall *wall, int dark)
{
	int		color;
	int		y;
	int		y_max;
	double	texture_y;
	t_vec2i	texture_pixel;

	draw_wall_init_loop(&y, &y_max, &texture_y, wall);
	texture_pixel.x = wall->x_in_texture;
	texture_pixel.y = (int)texture_y;
	texture_y -= texture_pixel.y;
	color = asset_get_color(wall->texture, texture_pixel.x, texture_pixel.y);
	color = color_darkened(color, dark);
	while (y < y_max)
	{
		if (texture_y >= 1.0)
		{
			texture_pixel.y++;
			texture_y -= 1.0;
			color = asset_get_color(wall->texture, texture_pixel.x, texture_pixel.y);
		color = color_darkened(color, dark);
		}
		window_put_pixel(win, x, y, color);
		texture_y += wall->texture_dy;
		y++;
	}
}

void	draw_wall_small_pixel(t_window *win, int x, t_wall *wall, int dark)
{
	int		color;
	int		y;
	int		y_max;
	double	texture_y;
	t_vec2i	texture_pixel;

	draw_wall_init_loop(&y, &y_max, &texture_y, wall);
	texture_pixel.x = wall->x_in_texture;
	while (y < y_max)
	{
		texture_pixel.y = (int)texture_y;
		color = asset_get_color(wall->texture, texture_pixel.x, texture_pixel.y);
		color = color_darkened(color, dark);
		window_put_pixel(win, x, y, color);
		texture_y += wall->texture_dy;
		y++;
	}
}

int	x_hit_in_texture(t_texture *texture, t_ray *ray)
{
	if (ray->hit_side == 'n')
		return ((1 - ray->hit_pos.x.box) * texture->width);
	if (ray->hit_side == 's')
		return (ray->hit_pos.x.box * texture->width);
	if (ray->hit_side == 'e')
		return ((1 - ray->hit_pos.y.box) * texture->width);
	return (ray->hit_pos.y.box * texture->width);
}

void	draw_wall(t_window *win, int x, t_ray *ray, t_texture *texture)
{
	t_wall wall;
	double	wall_h;

	wall_h = WIN_H / ray->len;
	if (wall_h < 1.0)
		return ;
	if (wall_h > INT_MAX)
		wall.height = INT_MAX;
	else
		wall.height = (int)wall_h;
	wall.texture = texture;
	wall.x_in_texture = x_hit_in_texture(wall.texture, ray);
	wall.texture_dy = (double)wall.texture->height / wall.height;
	if (wall.texture_dy < 1)
		draw_wall_big_pixel(win, x, &wall, ray->dark);
	else
		draw_wall_small_pixel(win, x, &wall, ray->dark);
}
