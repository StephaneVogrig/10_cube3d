/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:07:24 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/23 16:32:03 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "draw_wall_utils.h"

void	draw_wall_big_pixel(t_window *win, int x, t_wall_draw *draw)
{
	int		y;
	int		color;
	t_vec2i	img;
	double	img_current_y;

	img.x = (int)draw->img_start.x;
	img.y = (int)draw->img_start.y;
	img_current_y = draw->img_start.y - img.y;
	color = texture_get_color(draw->img, img.x, img.y);
	color = color_darkened(color, draw->dark);
	y = draw->screen_start.y;
	while (y < draw->screen_end.y)
	{
		if (img_current_y >= 1.0)
		{
			img.y++;
			img_current_y -= 1.0;
			color = texture_get_color(draw->img, img.x, img.y);
			color = color_darkened(color, draw->dark);
		}
		window_put_pixel(win, x, y, color);
		img_current_y += draw->img_delta.y;
		y++;
	}
}

void	draw_wall_small_pixel(t_window *win, int x, t_wall_draw *draw)
{
	int		y;
	int		color;
	t_vec2i	img;
	double	img_current_y;

	img.x = (int)draw->img_start.x;
	img_current_y = draw->img_start.y;
	y = draw->screen_start.y;
	while (y < draw->screen_end.y)
	{
		img.y = (int)img_current_y;
		color = texture_get_color(draw->img, img.x, img.y);
		color = color_darkened(color, draw->dark);
		window_put_pixel(win, x, y, color);
		img_current_y += draw->img_delta.y;
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

void	draw_wall(t_window *win, int x, t_wall_draw *draw)
{
	draw->img_start.y = 0;
	draw->screen_start.y = (win->height - draw->img_screen_size.y) / 2;
	draw->screen_end.y = draw->screen_start.y + draw->img_screen_size.y;
	draw->img_delta.y = (double)draw->img->height / draw->img_screen_size.y;
	if (draw->screen_start.y < 0)
	{
		draw->img_start.y += -draw->screen_start.y * draw->img_delta.y;
		draw->screen_start.y = 0;
	}
	if (draw->screen_end.y > win->height)
		draw->screen_end.y = win->height;
	if (draw->img_delta.y < 1)
		draw_wall_big_pixel(win, x, draw);
	else
		draw_wall_small_pixel(win, x, draw);
}
