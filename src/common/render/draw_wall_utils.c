/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:07:24 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/22 23:45:58 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "draw_wall_utils.h"

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
	color = texture_get_color(wall->texture, texture_pixel.x, texture_pixel.y);
	color = color_darkened(color, dark);
	while (y < y_max)
	{
		if (texture_y >= 1.0)
		{
			texture_pixel.y++;
			texture_y -= 1.0;
			color = texture_get_color(wall->texture, texture_pixel.x, texture_pixel.y);
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
		color = texture_get_color(wall->texture, texture_pixel.x, texture_pixel.y);
		color = color_darkened(color, dark);
		window_put_pixel(win, x, y, color);
		texture_y += wall->texture_dy;
		y++;
	}
}

int	wall_height(t_window *win, double ray_len)
{
	double	wall_h;

	wall_h = win->height / ray_len;
	if (wall_h > INT_MAX)
		return (INT_MAX);
	return ((int)wall_h);
}

void	draw_wall(t_window *win, int x, t_wall *wall, int dark)
{
	if (wall->texture_dy < 1)
		draw_wall_big_pixel(win, x, wall, dark);
	else
		draw_wall_small_pixel(win, x, wall, dark);
}
