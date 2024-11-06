/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:30:04 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/06 20:22:01 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "render.h"

void	draw_player(t_minimap *minimap, t_player *player)
{
	t_vec2i	begin;
	t_vec2i	end;

	// printf("draw_player \n");
	begin.x = player->x.grid * minimap->scale + (player->x.box
			* minimap->scale);
	begin.y = player->y.grid * minimap->scale + (player->y.box
			* minimap->scale);
	end.x = begin.x + 2;
	end.y = begin.y + 2;
	draw_rectangle(&minimap->screen, begin, end, 0xFFFFFF00);
}

void	draw_minimap(t_map *map, t_minimap *minimap)
{
	int		x;
	int		y;
	int		color;
	t_vec2i	begin;
	t_vec2i	end;

	// printf("draw_minimap\n");
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
			draw_rectangle(&minimap->screen, begin, end, color);
			draw_line(&minimap->screen, vector2i(begin.x - 1, begin.y - 1),
				vector2i(begin.x - 1, begin.y - 1 + minimap->scale),
				0xFF606060);
			draw_line(&minimap->screen, vector2i(begin.x - 1, begin.y - 1),
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

void	draw_rays(t_minimap *minimap, t_player *player, t_ray *rays)
{
	int	i;
	t_vec2i	start;
	t_vec2i	end;
	t_vec2d	play;
	t_vec2d	hit;

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
		draw_line(&minimap->screen, start, end, 0xFFFF0000);
		i++;
		rays++;
	}
}

void	render_minimap(t_minimap *minimap, t_map *map, t_player *player, t_ray *rays)
{
	// printf("render_minimap\n");
	draw_minimap(map, minimap);
	draw_rays(minimap, player, rays);
	draw_player(minimap, player);
}

void	render_draw_floor_ceil(t_window *win, t_textures *textures, t_ray *rays, int dark)
{
	int color_ceil;
	int color_floor;
	int x;
	int	y_ceil;
	int	y_floor;
	int	wall_h;

	color_ceil = color_darkened(textures->ceil_rgb.integer, dark);
	color_floor = color_darkened(textures->floor_rgb.integer, dark);
	x = 0;
	while (x < WIN_W)
	{
		if (rays->len < win->height)
		{
			wall_h = win->height / rays->len;
			y_ceil = 0;
			y_floor = wall_h + (win->height - wall_h) / 2;
			while (y_floor < win->height)
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

void	render(t_data *data)
{
	// printf("render\n");
	t_ray	rays[WIN_W];
	int		dark;

	dark = map_get_grid(&data->map, &data->player.position) == WALL;
	raycasting(&data->win, &data->map, &data->player, &rays[0]);
	render_minimap(&data->minimap, &data->map, &data->player, &rays[0]);
	render_draw_floor_ceil(&data->win, &data->map.textures, &rays[0], dark);
	fps_print(chrono(STOP));
}
