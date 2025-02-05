/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 02:44:03 by aska              #+#    #+#             */
/*   Updated: 2025/02/05 18:55:32 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_img_minimap.h"

static
void	draw_empty(t_interface *interface, t_vec2i pos_in_map)
{
	int	x;
	int	y;

	y = 0;
	while (y != TILES_H)
	{
		x = 0;
		while (x != TILES_W)
		{
			mlx_set_image_pixel(interface->mlx, interface->img_map, pos_in_map.x
				+ x, pos_in_map.y + y, 0x00000000);
			x++;
		}
		y++;
	}
}

static
void	draw_tile(t_interface *interface, t_vec2i pos_in_map, int *tile_ptr)
{
	int	x;
	int	y;

	y = 0;
	while (y != TILES_H)
	{
		x = 0;
		while (x != TILES_W)
		{
			mlx_set_image_pixel(interface->mlx, interface->img_map, pos_in_map.x
				+ x, pos_in_map.y + y, *tile_ptr);
			x++;
			tile_ptr++;
		}
		y++;
	}
}

static
void	draw_loop(t_interface *interface, t_vec2i start, t_vec2i end,
		t_map *map)
{
	t_vec2i		cursor;
	int			*tile;
	t_position	cell_pos;
	t_vec2i		pixel_pos_in_minimap;

	cursor.y = start.y;
	while (cursor.y < end.y)
	{
		cursor.x = start.x;
		while (cursor.x < end.x)
		{
			cell_pos = position(cursor.x, 0.0, cursor.y, 0.0);
			pixel_pos_in_minimap = vector2i((cursor.x - start.x) * TILES_W,
					(cursor.y - start.y) * TILES_H);
			tile = get_tile(map_get_cell(map, &cell_pos), interface);
			if (tile == NULL)
				draw_empty(interface, pixel_pos_in_minimap);
			else
				draw_tile(interface, pixel_pos_in_minimap, tile);
			cursor.x++;
		}
		cursor.y++;
	}
}

void	draw_image_minimap(t_interface *interface, t_position *player_pos,
		t_map *map)
{
	t_vec2i	end;
	t_vec2i	start;

	start.x = player_pos->x.grid - ((MINIMAP_W / TILES_W) / 2);
	start.y = player_pos->y.grid - ((MINIMAP_H / TILES_H) / 2);
	end.x = start.x + (MINIMAP_W / TILES_W);
	end.y = start.y + (MINIMAP_H / TILES_H);
	draw_loop(interface, start, end, map);
}
