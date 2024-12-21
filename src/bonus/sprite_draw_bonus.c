/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:37:46 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/22 00:06:09 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "sprite_bonus.h"

void	sprite_draw_position(t_window *win, t_vec2i screen_pos, t_vec2i size)
{
	int x;
	int y;

	y = screen_pos.y;
	while (y < screen_pos.y + size.y)
	{
		window_put_pixel(win, screen_pos.x, y, 0xffff0000);
		y++;
	}
	y = WIN_H / 2;
	x = screen_pos.x - size.x / 2;
	while (x < screen_pos.x + size.x / 2)
	{
		window_put_pixel(win, x, y, 0xff00ff00);
		x++;
	}
}

void	sprite_draw_stripe(t_window *win, t_vec2i screen, int wall_h)
{
	int i;

	i = screen.y;
	while (i < screen.y + wall_h)
	{
		window_put_pixel(win, screen.x, i, 0xff0000ff);
		i++;
	}
}

void	sprite_draw(t_texture *img, t_vec2d pos, t_ray *ray_tab, t_window *win)
{
	// printf("sprite_draw\n");
	int state_nb;
	state_nb = img->width / img->height;

	t_vec2i sprite_size;
	sprite_size.x = img->width / state_nb;
	sprite_size.y = img->height;

	t_vec2i sprite_screen_size;
	sprite_screen_size.x = (WIN_W / 2) / pos.y;
	sprite_screen_size.y = WIN_H / pos.y;

	// t_vec2i	sprite_screen_pos;
	// sprite_screen_pos.x = (WIN_W / 2) + pos.x * (WIN_W / 2) / pos.y;
	// sprite_screen_pos.y = (WIN_H - sprite_screen_size.y) / 2;
	// sprite_draw_position(win, sprite_screen_pos, sprite_screen_size);

	t_vec2i start;
	start.x = (WIN_W / 2) + pos.x * sprite_screen_size.x - sprite_screen_size.x / 2;
	start.y = (WIN_H - sprite_screen_size.y) / 2;

	t_vec2i end;
	end.x = start.x + sprite_screen_size.x;
	end.y = start.y + sprite_screen_size.y;

	t_vec2d	pixel;
	t_vec2d	delta_pixel;
	delta_pixel.x = (double)sprite_size.x / sprite_screen_size.x;
	delta_pixel.y = (double)sprite_size.y / sprite_screen_size.y;

	t_rgb color;
	int x;
	int y;
	pixel.x = 0;
	x = start.x;
	while (x < end.x)
	{
		if (x >= 0 && x < WIN_W && ray_tab[x].len > pos.y)
		{
			y = start.y;
			pixel.y = 0;
			while (y < end.y)
			{
				if (y >= 0 && y < WIN_H)
				{
					color = (t_rgb)texture_get_color(img, pixel.x, pixel.y);
					if (color.a)
						window_put_pixel(win, x, y, color.integer);
				}
				pixel.y += delta_pixel.y;
				y++;
			}
		}
		pixel.x += delta_pixel.x;
		x++;
	}
}
