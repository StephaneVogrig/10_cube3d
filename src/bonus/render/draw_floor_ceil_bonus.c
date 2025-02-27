/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceil_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:32:54 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/03 21:38:01 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_floor_ceil_bonus.h"

static
void	elem_draw_pixel(int x, t_element *elem, t_context *context)
{
	t_rgb	color;
	t_vec2i	pixel;

	pixel.x = elem->tex->width * context->box.x;
	pixel.y = elem->tex->height * context->box.y;
	texture_get_color(&color, elem->tex, pixel.x, pixel.y);
	color_darkened(&color, context->dark);
	if (context->fog_enable)
		fog_color_with_tab(&color, context->fog_tab);
	window_put_pixel(context->win, x, elem->y, color.integer);
}

static
void	floorceil_draw_line_init(t_vec2d *map_step, t_vec2d *map_pos,
		t_floorceil_draw *draw, t_data *data)
{
	t_vec2d	player_dirvec;

	player_dirvec = dir_to_dirvec(data->player.dir);
	*map_step = ray_vec_step(player_dirvec, data->win.width, data->tg_fov_2);
	map_step->x *= draw->len;
	map_step->y *= draw->len;
	*map_pos = ray_vec_start(player_dirvec, data->tg_fov_2);
	map_pos->x *= draw->len;
	map_pos->y *= draw->len;
	map_pos->x += draw->player_pos.x;
	map_pos->y += draw->player_pos.y;
}

static
void	floorceil_draw_line(int y, t_data *data, t_floorceil_draw *draw)
{
	t_vec2d	map_step;
	t_vec2d	map_pos;
	int		x;

	floorceil_draw_line_init(&map_step, &map_pos, draw, data);
	x = 0;
	while (x < data->win.width)
	{
		if (y >= data->rays.tab[x].wall_screen_height / 2)
		{
			draw->context.box.x = map_pos.x - (long)map_pos.x;
			if (draw->context.box.x < 0.0)
				draw->context.box.x += 1.0;
			draw->context.box.y = map_pos.y - (long)map_pos.y;
			if (draw->context.box.y < 0.0)
				draw->context.box.y += 1.0;
			elem_draw_pixel(x, &draw->ceil, &draw->context);
			elem_draw_pixel(x, &draw->floor, &draw->context);
		}
		map_pos.x += map_step.x;
		map_pos.y += map_step.y;
		x++;
	}
}

void	draw_floor_ceil(t_data *data)
{
	t_floorceil_draw	draw;
	int					y;

	draw.winh_2 = data->win.height / 2;
	draw.scalescreen_2 = data->scale_screen / 2;
	draw.player_pos = position_to_vec2d(data->player.position);
	draw.ceil.tex = data->textures.floor_ceil.ceil;
	draw.floor.tex = data->textures.floor_ceil.floor;
	draw.context.win = &data->win;
	draw.context.dark = data->dark;
	draw.context.fog_enable = data->fog_enable;
	y = 0;
	while (y < draw.winh_2)
	{
		draw.ceil.y = draw.winh_2 - y - 1;
		draw.floor.y = draw.winh_2 + y;
		draw.len = draw.scalescreen_2 / (y + 1);
		if (data->fog_enable)
			fog_tab_fill(draw.context.fog_tab, fog_exponential(draw.len));
		floorceil_draw_line(y, data, &draw);
		y++;
	}
}
