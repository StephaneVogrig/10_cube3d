/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:30:04 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/23 19:32:30 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "render_bonus.h"
#include "draw_utils_bonus.h"
#include "draw_line_bonus.h"
#include "draw_walls_bonus.h"
#include "sprite_bonus.h"
#include "pointer_table_bonus.h"
#include "option_bonus.h"

void	draw_player(t_player *player)
{
	t_vec2i	begin;
	t_vec2i	end;
	t_minimap	*minimap;

	minimap = minimap_get_ptr();
	begin.x = player->x.grid * minimap->scale + (player->x.box
			* minimap->scale);
	begin.y = player->y.grid * minimap->scale + (player->y.box
			* minimap->scale);
	end.x = begin.x + 2;
	end.y = begin.y + 2;
	draw_rectangle(minimap, begin, end, 0xFFFFFF00);
}

void	draw_minimap(t_map *map)
{
	int		x;
	int		y;
	int		color;
	t_vec2i	begin;
	t_vec2i	end;
	t_minimap	*minimap;

	minimap = minimap_get_ptr();
	begin.y = 1;
	end.y = minimap->scale - 1;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		begin.x = 1;
		end.x = minimap->scale - 1;
		while (x < map->width)
		{
			if (map->grid[y][x] == WALL)
				color = 0xFF0FFFfF;
			else
				color = 0xFF7F7F7F;
			draw_rectangle(minimap, begin, end, color);
			draw_line(minimap, vector2i(begin.x - 1, begin.y - 1),
				vector2i(begin.x - 1, begin.y - 1 + minimap->scale),
				0xFF606060);
			draw_line(minimap, vector2i(begin.x - 1, begin.y - 1),
				vector2i(begin.x - 1 + minimap->scale, begin.y - 1),
				0xFF606060);
			begin.x += minimap->scale;
			end.x += minimap->scale;
			x++;
		}
		begin.y += minimap->scale;
		end.y += minimap->scale;
		y++;
	}
}

void	draw_rays(t_player *player, t_ray *rays)
{
	int	i;
	t_vec2i	start;
	t_vec2i	end;
	t_vec2d	play;
	t_vec2d	hit;
	t_minimap	*minimap;

	minimap = minimap_get_ptr();
	play.x = player->x.grid + player->x.box;
	play.y = player->y.grid + player->y.box;
	start.x = minimap->scale * play.x;
	start.y = minimap->scale * play.y;
	i = 0;
	while (i < WIN_W)
	{
		hit.x = rays->hit_pos.x.grid + rays->hit_pos.x.box;
		hit.y = rays->hit_pos.y.grid + rays->hit_pos.y.box;
		end.x = minimap->scale * hit.x;
		end.y = minimap->scale * hit.y;
		draw_line(minimap, start, end, 0xFFFF0000);
		i++;
		rays++;
	}
}

void	render_minimap(t_map *map, t_player *player, t_ray *rays)
{
	draw_minimap(map);
	draw_rays(player, rays);
	draw_player(player);
}

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
		double winh_2i = (double)winh_2 / (i + 1);
		x = 0;
		while (x < data->win.width)
		{
			wall_h = data->win.height / rays[x].len;
			wall_h /= 2;
			if (i >= wall_h)
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
				(void)dark;
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

void	render(t_data *data)
{
	int		dark;

	window_clear(&data->win);
	raycasting(&data->map, &data->player, &data->rays, data->door_open_list);
	dark = map_get_cell(&data->map, &data->player.position) == WALL;
	draw_floor_ceil(data, data->rays.tab, dark);
	draw_walls(&data->win, data->rays.tab, &data->textures, data->door_open_list);
	sprite_render(&data->sprite, &data->player, data->rays.tab, &data->win);
	if (option->minimap == TRUE)
		render_minimap(&data->map, &data->player, data->rays.tab);
}
