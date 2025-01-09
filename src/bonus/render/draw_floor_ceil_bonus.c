/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceil_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/09 17:54:03 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/



#include "draw_floor_ceil_bonus.h"

void	floorceil_draw_pixel(int x, t_element *elem, t_context *context)
{
	t_rgb	color;
	t_vec2i	pixel;

	pixel.x = elem->tex->width * context->box.x;
	pixel.y = elem->tex->height * context->box.y;
	color.integer = texture_get_color(elem->tex, pixel.x, pixel.y);
	color.integer = color_darkened(color.integer, context->dark);
	fog_color_with_tab(&color, context->fog_tab);
	window_put_pixel(context->win, x, elem->y, color.integer);
}

void	floorceil_draw_line(int y, t_data *data, t_floorceil_draw *draw,\
									t_ray *rays)
{
	double	len;
	int		x;

	draw->ceil.y = draw->winh_2 - y - 1;
	draw->floor.y = draw->winh_2 + y;
	y++;
	len = draw->scalescreen_2 / y;
	fog_tab_fill(draw->context.fog_tab, fog_exponential(len));
	x = 0;
	while (x < data->win.width)
	{
		if (y >= draw->scalescreen_2 / rays[x].len)
		{
			draw->context.box.x = draw->player_pos.x + rays[x].dirvec.x * len;
			draw->context.box.x -= (long)draw->context.box.x;
			draw->context.box.y = draw->player_pos.y + rays[x].dirvec.y * len;
			draw->context.box.y -= (long)draw->context.box.y;
			floorceil_draw_pixel(x, &draw->ceil, &draw->context);
			floorceil_draw_pixel(x, &draw->floor, &draw->context);
		}
		x++;
	}
}

void	draw_floor_ceil(t_data *data, t_ray *rays, int dark)
{
	t_floorceil_draw	draw;
	int					y;

	draw.winh_2 = data->win.height / 2;
	draw.scalescreen_2 = data->scale_screen / 2;
	draw.player_pos = position_to_vec2d(data->player.position);
	draw.context.dark = dark;
	draw.context.win = &data->win;
	draw.ceil.tex = data->textures.floor_ceil.ceil;
	draw.floor.tex = data->textures.floor_ceil.floor;
	y = 0;
	while (y < draw.winh_2)
	{
		floorceil_draw_line(y, data, &draw, rays);
		y++;
	}
}
