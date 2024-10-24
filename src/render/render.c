/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:30:04 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/24 17:05:37 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_player(t_minimap *minimap, t_player *player)
{
	t_vec2i	begin;
	t_vec2i	end;

	// printf("draw_player \n");
	begin.x = player->grid.x * minimap->scale + (player->box.x
			* minimap->scale);
	begin.y = player->grid.y * minimap->scale + (player->box.y
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

void	render_minimap(t_minimap *minimap, t_map *map, t_player *player)
{
	// printf("render_minimap\n");
	draw_minimap(map, minimap);
	// draw_line_to_border(minimap, player, 0xFF0000FF);
	draw_player(minimap, player);
}

void	render(t_data *data)
{
	// printf("render\n");
	// render_minimap(&data->minimap, &data->map, &data->player);
	raycasting(&data->win, &data->minimap, &data->map, &data->player);
	// mlx_put_image_to_window(data->mlx, data->minimap.screen.win,
		// data->minimap.screen.img, 0, 0);
	fps_print(chrono(STOP));
}
