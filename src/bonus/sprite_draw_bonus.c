/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:37:46 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/23 17:11:06 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "sprite_bonus.h"

void	stripe_draw(t_window *win, t_sprite_draw *stripe, int x, t_vec2d img)
{
	int y;
	t_rgb color;

	y = stripe->screen_start.y;
	img.y = stripe->img_start.y;
	while (y < stripe->screen_end.y)
	{
		color = (t_rgb)texture_get_color(stripe->img, img.x, img.y);
		if (color.a == (char)255)
			window_put_pixel(win, x, y, color.integer);
		img.y += stripe->img_delta.y;
		y++;
	}
}

void	sprite_draw(t_sprite *sprite, int i, t_window *win, t_ray *ray_tab)
{
	t_sprite_draw	draw;
	t_vec2d			img;
	int				sprite_size;
	int				x;

	if (sprite->collected[i])
		return ;
	draw.img = sprite->image[i];
	draw.distance = sprite->transform[i].y;
	sprite_size = sprite->image[i]->height;
	sprite_screen_size_compute(&draw, win);
	screen_start_compute(&draw, sprite->transform[i].x, win);
	screen_end_compute(&draw, win);
	img_delta_compute(&draw, sprite_size);
	img_start_compute(&draw, (int)sprite->state[i], sprite_size);
	img.x = draw.img_start.x;
	x = draw.screen_start.x;
	while (x < draw.screen_end.x)
	{
		if (draw.distance < ray_tab[x].len)
			stripe_draw(win, &draw, x, img);
		img.x += draw.img_delta.x;
		x++;
	}
}
