/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 02:44:03 by aska              #+#    #+#             */
/*   Updated: 2025/01/19 20:55:31 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_img_minimap.h"
#include "tile_rules.h"

static int   get_grid_position(int img_position, int tile_size)
{
	if (img_position <= 0 || tile_size <= 0)
		return (0);
	return (img_position / tile_size);
}

static void    draw_tile(t_interface *interface, t_vec2i pos, t_tile *tile)
{
	int x;
	int y;

	y = 0;
	while (y != TILES_H)
	{
		x = 0;
		while (x != TILES_W)
		{
			mlx_set_image_pixel(interface->mlx, interface->img_map, pos.x + x, pos.y + y, *tile->tile_ptr);
			x++;
			tile->tile_ptr++;
		}
		y++;
	}
	
}


void    draw_image_minimap(t_interface *interface, t_vec2i start, t_vec2i end, t_map *map)
{
	t_vec2i	cursor;
	t_vec2i	map_xy;
	t_tile	tile;

	cursor.y = start.y;
	while (cursor.y < end.y)
	{
		cursor.x = start.x;
		while (cursor.x < end.x)
		{
			map_xy.x = get_grid_position(cursor.x, TILES_W);
			map_xy.y = get_grid_position(cursor.y, TILES_H);
			tile = get_tile(map->grid[map_xy.y][map_xy.x], map_xy, interface);
			draw_tile(interface, tile.pos, &tile);
			cursor.x += TILES_W;
		}
		cursor.y += TILES_H;
	}
}

