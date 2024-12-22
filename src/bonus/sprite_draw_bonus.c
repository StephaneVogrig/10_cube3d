/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:37:46 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/22 21:02:55 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "sprite_bonus.h"

void	sprite_draw(t_sprite *sprite, int i, t_window *win, t_ray *ray_tab)
{
	// printf("sprite_draw\n");
	if (sprite->collected[i])
		return ;
	t_vec2i sprite_size;
	sprite_size.x = sprite->image[i]->width / sprite->nbr_state[i];
	sprite_size.y = sprite->image[i]->height;

	t_vec2i sprite_screen_size;
	sprite_screen_size.x = (WIN_W / 2) / sprite->transform[i].y;
	sprite_screen_size.y = WIN_H / sprite->transform[i].y;

	t_vec2i start;
	start.x = (WIN_W / 2) + sprite->transform[i].x * sprite_screen_size.x - sprite_screen_size.x / 2;
	if (start.x >= WIN_W)
		return ;
	start.y = (WIN_H - sprite_screen_size.y) / 2;

	t_vec2i end;
	end.x = start.x + sprite_screen_size.x;
	end.y = start.y + sprite_screen_size.y;
	if (end.x > WIN_W)
		end.x = WIN_W;
	if (end.y > WIN_H)
		end.y = WIN_H;

	t_vec2d	pixel;
	t_vec2d	delta_pixel;
	delta_pixel.x = (double)sprite_size.x / sprite_screen_size.x;
	delta_pixel.y = (double)sprite_size.y / sprite_screen_size.y;

	t_rgb color;
	int x;
	int y;
	pixel.x = (int)sprite->state[i] * sprite_size.x;
	x = start.x;

	if (x < 0)
	{
		pixel.x += -x * delta_pixel.x;
		x = 0;
	}
	double start_img_y;
	start_img_y = 0;
	if (start.y < 0)
	{
		start_img_y += -start.y * delta_pixel.y;
		start.y = 0;
	}

	while (x < end.x)
	{
		if (ray_tab[x].len > sprite->transform[i].y)
		{
			y = start.y;
			pixel.y = start_img_y;
			while (y < end.y)
			{
				if (y >= 0 && y < WIN_H)
				{
					color = (t_rgb)texture_get_color(sprite->image[i], pixel.x, pixel.y);
					if (color.a == (char)255)
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
