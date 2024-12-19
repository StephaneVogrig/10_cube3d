/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:37:46 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/19 22:44:28 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "sprite_bonus.h"

static void	sprite_draw_stripe(t_window *win, t_vec2i screen, int wall_h)
{
	int i;

	i = screen.y;
	while (i < screen.y + wall_h)
	{
		window_put_pixel(win, screen.x, i, 0xffff0000);
		i++;
	}
}

void	sprite_draw(t_texture *texture, t_vec2d pos, t_ray *ray_tab, t_window *win)
{
	t_vec2i	screen;
	(void)texture;
	(void)ray_tab;
	int wall_h;

	if (pos.y < 0)
		return;

	// printf("sprite_draw transform x: %f, transform y: %f\n", pos.x, pos.y); //debug

	screen.x = (WIN_W / 2) * (1 + (pos.x / pos.y));
	if (screen.x >=0 && screen.x < WIN_W && ray_tab[screen.x].len < pos.y)
		return ;
	wall_h = WIN_H / pos.y;
	screen.y = (WIN_H - wall_h) / 2;

	// printf("sprite_draw screen x: %i y: %i wall_h: %i\n", screen.x, screen.y, wall_h); //debug
	sprite_draw_stripe(win, screen, wall_h);
}
