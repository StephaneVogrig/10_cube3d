/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 02:44:03 by aska              #+#    #+#             */
/*   Updated: 2025/01/13 23:14:25 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_img_minimap.h"
#include "tile_rules.h"

static int   get_grid_position(int img_position, int tile_size)
{
	if (img_position <= 0)
		return (0);
	return (img_position / tile_size);
}

static void    draw_tile(t_interface *interface, t_vec2i pos, int *color)
{
	int x;
	int y;

	y = 0;
	while (y < TILES_H)
	{
		x = 0;
		while (x < TILES_W)
		{
			mlx_set_image_pixel(interface->mlx, interface->img_map, pos.x + x, pos.y + y, *color);
			x++;
			color++;
		}
		y++;
	}
}

void    draw_image_minimap(t_interface *interface, t_vec2i start, t_vec2i end, t_map *map)
{
	t_vec2i	cursor;
	t_vec2i	pos;
	t_tile	tile;

	cursor.y = start.y;
	while (cursor.y < end.y)
	{
		cursor.x = start.x;
		while (cursor.x < end.x)
		{
			tile = get_tile(map->grid[cursor.y][cursor.x], &interface->tiles_index);
			printf("cursor.x: %d | cursor.y: %d\n", cursor.x, cursor.y);
			pos.y = cursor.y - start.y;
			pos.x = cursor.x - start.x;
			draw_tile(interface, pos, map);
			cursor.x += TILES_W;
		}
		cursor.y += TILES_H;
	}
}

