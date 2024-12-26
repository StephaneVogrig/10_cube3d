/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:30:04 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/26 13:49:04 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "render_bonus.h"

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

void	draw_rays(t_player *player, t_ray_tab *rays)
{
	int	i;
	t_vec2i	start;
	t_vec2i	end;
	t_vec2d	play;
	t_vec2d	hit;
	t_minimap	*minimap;
	t_ray	*ray;

	minimap = minimap_get_ptr();
	play.x = player->x.grid + player->x.box;
	play.y = player->y.grid + player->y.box;
	start.x = minimap->scale * play.x;
	start.y = minimap->scale * play.y;
	i = 0;
	ray = rays->tab;
	while (i < rays->nbr)
	{
		hit.x = ray->hit_pos.x.grid + ray->hit_pos.x.box;
		hit.y = ray->hit_pos.y.grid + ray->hit_pos.y.box;
		end.x = minimap->scale * hit.x;
		end.y = minimap->scale * hit.y;
		draw_line(minimap, start, end, 0xFFFF0000);
		i++;
		ray++;
	}
}

void	render_minimap(t_map *map, t_player *player, t_ray_tab *rays)
{
	draw_minimap(map);
	draw_rays(player, rays);
	draw_player(player);
}

void	render(t_data *data)
{
	int		dark;

	window_clear(&data->win);
	raycasting(data->rays.tab, data);
	dark = map_get_cell(&data->map, &data->player.position) == WALL;
	draw_floor_ceil(data, data->rays.tab, dark);
	draw_walls(&data->win, data->rays.tab, &data->textures, data->door_open_list);
	sprite_render(&data->sprite, &data->player, data->rays.tab, &data->win);
	render_minimap(&data->map, &data->player, &data->rays);
}
