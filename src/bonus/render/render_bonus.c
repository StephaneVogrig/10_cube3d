/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:30:04 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/18 20:07:51 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "draw_utils_bonus.h"
#include "draw_line_bonus.h"
#include "draw_wall.h"

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

void	draw_floor_ceil_color(t_window *win, t_textures *textures, t_ray *rays, int dark)
{
	int color_ceil;
	int color_floor;
	int x;
	int	y_ceil;
	int	y_floor;
	int	wallh_2;
	int winh_2;

	winh_2 = WIN_H / 2;
	color_ceil = color_darkened(textures->ceil_rgb.integer, dark);
	color_floor = color_darkened(textures->floor_rgb.integer, dark);
	x = 0;
	while (x < WIN_W)
	{
		if (rays->len < WIN_H)
		{
			wallh_2 = winh_2 / rays->len;
			y_ceil = 0;
			y_floor = winh_2 + wallh_2;
			while (y_floor < WIN_H)
			{
				mlx_pixel_put(win->mlx, win->win, x, y_ceil, color_ceil);
				mlx_pixel_put(win->mlx, win->win, x, y_floor, color_floor);
				y_ceil++;
				y_floor++;
			}
		}
		rays++;
		x++;
	}
}

void	draw_floor_ceil_texture(t_window *win, t_texture *texture, t_ray *rays, int dark, t_player *player)
{
	int	x;
	int	i;
	int	winh_2;
	t_vec2d	player_position;

	player_position.x = player->x.grid + player->x.box;
	player_position.y = player->y.grid + player->y.box;
	winh_2 = WIN_H / 2;
	i = 0;
	while (i < winh_2)
	{
		int y_floor = winh_2 + i;
		int y_ceil = winh_2 - 1 - i;
		double winh_2i = (double)winh_2 / (i + 1);
		x = 0;
		while (x < WIN_W)
		{
			if (i > winh_2 / rays[x].len)
			{
				t_vec2d	world;
				t_vec2d len;
				len.x = rays[x].vdir.x * winh_2i;
				len.y = rays[x].vdir.y * winh_2i;
				world.x = player_position.x + len.x;
				world.y = player_position.y + len.y;
				int tx = (world.x - (int)world.x) * texture->width;
				int ty = (world.y - (int)world.y) * texture->height;

				int color;
				// ceil
				color = texture_get_color(texture, tx, ty);
				color = color_darkened(color, dark);
				// color = color_darkened(0xFF0000FF, dark);
				mlx_pixel_put(win->mlx, win->win, x, y_ceil, color);

				// floor
				color = texture_get_color(texture, tx, ty);
				color = color_darkened(color, dark);
				// color = color_darkened(0xFF00FF00, dark);
				mlx_pixel_put(win->mlx, win->win, x, y_floor, color);
			}
			x++;
		}
		i++;
	}
}

void	render(t_data *data)
{
	t_ray	rays[WIN_W];
	int		dark;

	mlx_clear_window(data->win.mlx, data->win.win);
	dark = map_get_grid(&data->map, &data->player.position) == WALL;
	raycasting(&data->win, &data->map, &data->player, rays);
	draw_floor_ceil_texture(&data->win, &data->map.textures.north, rays, dark, &data->player);
	// draw_floor_ceil_color(&data->win, &data->map.textures, rays, dark);
	draw_walls(&data->win, rays, &data->map.textures);
	render_minimap(&data->map, &data->player, rays);
	fps_print(chrono(STOP));
}
