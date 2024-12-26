/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:07:24 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/26 22:53:59 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "draw_wall_utils.h"

void	draw_wall_big_pixel(t_window *win, int x, double img_x, t_strip *draw)
{
	int		y;
	int		color;
	t_vec2i	img_pxel;
	double	img_pos_y;

	img_pxel.x = (int)img_x;
	img_pxel.y = (int)draw->img_start;
	img_pos_y = draw->img_start - img_pxel.y;
	color = texture_get_color(draw->img, img_pxel.x, img_pxel.y);
	color = color_darkened(color, draw->dark);
	y = draw->screen_start;
	while (y < draw->screen_end)
	{
		window_put_pixel(win, x, y, color);
		img_pos_y += draw->img_delta;
		if (img_pos_y >= 1.0)
		{
			img_pxel.y++;
			img_pos_y -= 1.0;
			color = texture_get_color(draw->img, img_pxel.x, img_pxel.y);
			color = color_darkened(color, draw->dark);
		}
		y++;
	}
}

void	draw_wall_small_pixel(t_window *win, int x, double img_x, t_strip *draw)
{
	int		y;
	int		color;
	t_vec2i	img_pxel;
	double	img_pos_y;

	img_pxel.x = (int)img_x;
	img_pos_y = draw->img_start;
	y = draw->screen_start;
	while (y < draw->screen_end)
	{
		img_pxel.y = (int)img_pos_y;
		color = texture_get_color(draw->img, img_pxel.x, img_pxel.y);
		color = color_darkened(color, draw->dark);
		window_put_pixel(win, x, y, color);
		img_pos_y += draw->img_delta;
		y++;
	}
}

void	draw_wall(t_window *win, int x, double img_x, t_strip *strip)
{
	strip_setup(strip, win->height);
	if (strip->img_delta < 1)
		draw_wall_big_pixel(win, x, img_x, strip);
	else
		draw_wall_small_pixel(win, x, img_x, strip);
}
