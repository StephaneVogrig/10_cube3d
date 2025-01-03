/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceil_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:54:46 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/31 15:04:28 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "draw_floor_ceil_bonus.h"

static inline void	floorceil_draw_pixel(int x, t_element *elem,\
											t_context *context)
{
	int		color;
	t_vec2i	pixel;

	pixel.x = elem->tex->width * context->box.x;
	pixel.y = elem->tex->height * context->box.y;
	color = texture_get_color(elem->tex, pixel.x, pixel.y);
	color = color_darkened(color, context->dark);
	window_put_pixel(context->win, x, elem->y, color);
}

static inline void	floorceil_draw(int y, t_data *data, t_floorceil_draw *draw,\
									t_ray *rays)
{
	t_vec2d	player_position;
	double	len;
	int		x;

	player_position = position_to_vec2d(data->player.position);
	draw->ceil.y = (data->win.height / 2) - 1 - y;
	draw->floor.y = draw->ceil.y + (y * 2);
	len = (data->scale_screen / 2) / (y + 1);
	x = 0;
	while (x < data->win.width)
	{
		if (y >= (data->scale_screen / rays[x].len) / 2)
		{
			draw->context.box.x = player_position.x + rays[x].dirvec.x * len;
			draw->context.box.y = player_position.y + rays[x].dirvec.y * len;
			draw->context.box.x -= (long)draw->context.box.x;
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
	int					winh_2;
	int					y;

	winh_2 = data->win.height / 2;
	draw.context.dark = dark;
	draw.context.win = &data->win;
	draw.ceil.tex = asset_get_texture_ptr(&data->textures, "C", 'n');
	draw.floor.tex = asset_get_texture_ptr(&data->textures, "F", 'n');
	y = 0;
	while (y < winh_2)
	{
		floorceil_draw(y, data, &draw, rays);
		y++;
	}
}
