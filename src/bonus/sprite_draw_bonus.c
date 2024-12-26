/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:37:46 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/26 22:50:11 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "sprite_bonus.h"

void	strip_draw(t_window *win, int x, double img_x, t_strip *strip)
{
	double	img_y;
	t_rgb	color;
	int		y;

	y = strip->screen_start;
	img_y = strip->img_start;
	while (y < strip->screen_end)
	{
		color = (t_rgb)texture_get_color(strip->img, img_x, img_y);
		if (color.a == (char)255)
			window_put_pixel(win, x, y, color.integer);
		img_y += strip->img_delta;
		y++;
	}
}

static inline int is_outside_screen(t_strip *strip, int max)
{
	return (strip->screen_start >= max || strip->screen_end < 0);
}

void	sprite_draw(t_sprite *sprite, int i, t_window *win, t_ray *ray_tab)
{
	t_strip	strip_y;
	t_strip	sprite_x;
	double	distance;
	int		x;

	distance = sprite->transform[i].y;
	sprite_x.img = sprite->image[i];
	sprite_x.screen_size = strip_screen_size(win->width / 2, distance);
	sprite_x.screen_start = (win->width - sprite_x.screen_size) / 2;;
	sprite_x.screen_start += sprite->transform[i].x * sprite_x.screen_size;
	sprite_x.img_start = (int)sprite->state[i] * sprite_x.img->height;
	strip_add_limit(&sprite_x, win->width);
	if (sprite_x.screen_size < 1 || is_outside_screen(&sprite_x, win->width))
		return ;
	strip_y.img = sprite_x.img;
	strip_y.screen_size = strip_screen_size(win->height, distance);
	strip_setup(&strip_y, win->height);
	x = sprite_x.screen_start;
	while (x < sprite_x.screen_end)
	{
		if (distance < ray_tab[x].len)
			strip_draw(win, x, sprite_x.img_start, &strip_y);
		sprite_x.img_start += sprite_x.img_delta;
		x++;
	}
}
