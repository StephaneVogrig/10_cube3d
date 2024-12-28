/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_render_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:03:52 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/28 15:45:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minimap_render_bonus.h"

void	draw_player(t_minimap *minimap, t_player *player)
{
	t_vec2i	start;
	t_vec2i	end;

	start.x = minimap->scale * gridbox_to_double(player->x);
	start.y = minimap->scale * gridbox_to_double(player->y);
	end.x = start.x + 2;
	end.y = start.y + 2;
	draw_rectangle(minimap, start, end, 0xFFFFFF00);
}

void	draw_minimap(t_minimap *minimap, t_map *map)
{
	int		x;
	int		y;
	int		color;
	t_vec2i	begin;
	t_vec2i	end;

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

void	draw_rays(t_minimap *minimap, t_player *player, t_ray_tab *rays)
{
	t_vec2i	start;
	t_vec2i	end;
	t_ray	*ray;
	int		i;

	start.x = minimap->scale * gridbox_to_double(player->x);
	start.y = minimap->scale * gridbox_to_double(player->y);
	i = 0;
	ray = rays->tab;
	while (i++ < rays->nbr)
	{
		end.x = minimap->scale * gridbox_to_double(ray->hit_pos.x);
		end.y = minimap->scale * gridbox_to_double(ray->hit_pos.y);
		draw_line(minimap, start, end, 0xFFFF0000);
		ray++;
	}
}

void	render_minimap(t_minimap *minimap, t_data *data)
{
	draw_minimap(minimap, &data->map);
	draw_rays(minimap, &data->player, &data->rays);
	draw_player(minimap, &data->player);
}
