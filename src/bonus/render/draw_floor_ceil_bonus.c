/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceil_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:54:46 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/27 03:40:12 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "draw_floor_ceil_bonus.h"

void	draw_floor_ceil(t_data *data, t_ray *rays, int dark)
{
	int	x;
	int	i;
	int	wall_h;
	int	winh_2;
	t_vec2d	player_position;

	player_position.x = data->player.x.grid + data->player.x.box;
	player_position.y = data->player.y.grid + data->player.y.box;
	winh_2 = data->win.height / 2;
	i = 0;
	while (i < winh_2)
	{
		int y_floor = winh_2 + i;
		int y_ceil = winh_2 - 1 - i;
		double winh_2i = (double)(data->scale_screen / 2) / (i + 1);

		x = 0;
		while (x < data->win.width)
		{
			wall_h = data->scale_screen / rays[x].len;
			if (i >= wall_h / 2)
			{
				t_vec2d	world;
				t_vec2d len;
				len.x = rays[x].vdir.x * winh_2i;
				len.y = rays[x].vdir.y * winh_2i;
				world.x = player_position.x + len.x;
				world.y = player_position.y + len.y;

				t_vec2d	box;
				box.x = world.x - (int)world.x;
				box.y = world.y - (int)world.y;

				t_vec2i	t;

				int color;
				t_texture	*tex_ceil = asset_get_texture_ptr(&data->textures, "C", rays->hit_side);
				t_texture	*tex_floor = asset_get_texture_ptr(&data->textures, "F", rays->hit_side);
				// ceil
				t.x = tex_ceil->width * box.x;
				t.y = tex_ceil->height * box.y;
				color = texture_get_color(tex_ceil, t.x, t.y);
				color = color_darkened(color, dark);
				window_put_pixel(&data->win, x, y_ceil, color);

				// floor
				t.x = tex_floor->width * box.x;
				t.y = tex_floor->height * box.y;
				color = texture_get_color(tex_floor, t.x, t.y);
				color = color_darkened(color, dark);
				window_put_pixel(&data->win, x, y_floor, color);
			}
			x++;
		}
		i++;
	}
}
