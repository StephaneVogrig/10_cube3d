/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw_compute_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 04:40:42 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/23 18:04:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "sprite_bonus.h"

void	screen_end_compute(t_sprite_draw *draw, t_window *win)
{
	draw->screen_end.x = draw->screen_start.x + draw->sprite_screen_size.x;
	draw->screen_end.y = draw->screen_start.y + draw->sprite_screen_size.y;
	if (draw->screen_end.x > win->width)
		draw->screen_end.x = win->width;
	if (draw->screen_end.y > win->height)
		draw->screen_end.y = win->height;
}

void	img_start_compute(t_sprite_draw *strip, int sprite_state, int sprite_size)
{
	strip->img_start.x = sprite_state * sprite_size;
	strip->img_start.y = 0;
	if (strip->screen_start.x < 0)
	{
		strip->img_start.x += -strip->screen_start.x * strip->img_delta.x;
		strip->screen_start.x = 0;
	}
	if (strip->screen_start.y < 0)
	{
		strip->img_start.y += -strip->screen_start.y * strip->img_delta.y;
		strip->screen_start.y = 0;
	}
}

void	screen_start_compute(t_sprite_draw *draw, double screen_x, t_window *win)
{
	draw->screen_start.x = (win->width / 2) + screen_x * draw->sprite_screen_size.x - draw->sprite_screen_size.x / 2;
	if (draw->screen_start.x >= win->width)
		return ;
	draw->screen_start.y = (win->height - draw->sprite_screen_size.y) / 2;
}

void	sprite_screen_size_compute(t_sprite_draw *draw, t_window *win)
{
	if (draw->distance == 0)
	{
		draw->sprite_screen_size.x = INT_MAX;
		draw->sprite_screen_size.y = INT_MAX;
	}
	else
	{
		draw->sprite_screen_size.x = (win->width / 2) / draw->distance;
		draw->sprite_screen_size.y = win->height / draw->distance;
	}
}

void	img_delta_compute(t_sprite_draw *draw, int sprite_size)
{
	if (draw->sprite_screen_size.x == 0.0)
		draw->img_delta.x = INT_MAX;
	else
		draw->img_delta.x = (double)sprite_size / draw->sprite_screen_size.x;
	if (draw->sprite_screen_size.y == 0.0)
		draw->img_delta.y = INT_MAX;
	else
		draw->img_delta.y = (double)sprite_size / draw->sprite_screen_size.y;
}
