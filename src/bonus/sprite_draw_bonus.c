/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:37:46 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/22 23:22:55 by svogrig          ###   ########.fr       */
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
	sprite_screen_size.x = (win->width / 2) / sprite->transform[i].y;
	sprite_screen_size.y = win->height / sprite->transform[i].y;



	t_vec2i screen_start;
	screen_start.x = (win->width / 2) + sprite->transform[i].x * sprite_screen_size.x - sprite_screen_size.x / 2;
	if (screen_start.x >= win->width)
		return ;
	screen_start.y = (win->height - sprite_screen_size.y) / 2;

	t_vec2i screen_end;
	screen_end.x = screen_start.x + sprite_screen_size.x;
	screen_end.y = screen_start.y + sprite_screen_size.y;
	if (screen_end.x > win->width)
		screen_end.x = win->width;
	if (screen_end.y > win->height)
		screen_end.y = win->height;


	t_vec2d	img_delta;
	img_delta.x = (double)sprite_size.x / sprite_screen_size.x;
	img_delta.y = (double)sprite_size.y / sprite_screen_size.y;

	t_vec2d img_start;
	img_start.x = (int)sprite->state[i] * sprite_size.x;
	img_start.y = 0;
	if (screen_start.x < 0)
	{
		img_start.x += -screen_start.x * img_delta.x;
		screen_start.x = 0;
	}
	if (screen_start.y < 0)
	{
		img_start.y += -screen_start.y * img_delta.y;
		screen_start.y = 0;
	}

	t_vec2d	img;
	img.x = img_start.x;

	t_rgb color;
	int x;
	int y;

	x = screen_start.x;
	while (x < screen_end.x)
	{
		if (ray_tab[x].len > sprite->transform[i].y)
		{
			y = screen_start.y;
			img.y = img_start.y;
			while (y < screen_end.y)
			{
				if (y >= 0 && y < win->height)
				{
					color = (t_rgb)texture_get_color(sprite->image[i], img.x, img.y);
					if (color.a == (char)255)
						window_put_pixel(win, x, y, color.integer);
				}
				img.y += img_delta.y;
				y++;
			}
		}
		img.x += img_delta.x;
		x++;
	}
}
