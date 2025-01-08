/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:07:24 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/08 20:08:18 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "draw_walls_bonus.h"

static inline int	draw_wall_color(t_strip *strip, t_vec2i img_pxel)
{
	int		color;

	color = texture_get_color(strip->img, img_pxel.x, img_pxel.y);
	color = color_darkened(color, strip->dark);
	color = fog_color(color, strip->fog);
	return (color);
}

void	draw_wall_big_pixel(t_window *win, int x, double img_x, t_strip *strip)
{
	int		y;
	int		color;
	t_vec2i	img_pxel;
	double	img_pos_y;

	img_pxel.x = (int)img_x;
	img_pxel.y = (int)strip->img_start;
	img_pos_y = strip->img_start - img_pxel.y;
	color = draw_wall_color(strip, img_pxel);
	y = strip->screen_start;
	while (y < strip->screen_end)
	{
		window_put_pixel(win, x, y, color);
		img_pos_y += strip->img_delta;
		if (img_pos_y >= 1.0)
		{
			img_pxel.y++;
			img_pos_y -= 1.0;
			color = draw_wall_color(strip, img_pxel);
		}
		y++;
	}
}

void	draw_wall_small_pixel(t_window *win, int x, double img_x, t_strip *strip)
{
	int		y;
	int		color;
	t_vec2i	img_pxel;
	double	img_pos_y;

	img_pxel.x = (int)img_x;
	img_pos_y = strip->img_start;
	y = strip->screen_start;
	while (y < strip->screen_end)
	{
		img_pxel.y = (int)img_pos_y;
		color = draw_wall_color(strip, img_pxel);
		window_put_pixel(win, x, y, color);
		img_pos_y += strip->img_delta;
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
