/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_manda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:14:17 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/08 13:18:25 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "window.h"
#include "strip.h"
#include "vector.h"

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
