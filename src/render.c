/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:30:04 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/15 22:28:11 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_cub3d(t_data *data)
{
	printf("draw_cub3d\n");
	t_vec2i	start;
	t_vec2i	end;
	
	start = vector2i(0, 0);
	end = vector2i(0,MINIMAP_W);
	int	y;
	int	mid;
	
	y = -1;
	mid = MINIMAP_H / 2;
	
	while (y < mid)
	{
		draw_line(&data->cub, vector2i(0, y), vector2i(MINIMAP_W, y), 0xFF0000FF);
		y++;
	}
	while (y < MINIMAP_H)
	{
		draw_line(&data->cub, vector2i(0, y), vector2i(MINIMAP_W, y), 0xFF00FF00);
		y++;
	}
}


void	draw_player(t_minimap *minimap, t_player *player)
{
	printf("draw_player \n");
	t_vec2i begin;
	t_vec2i end;
	
	begin = player_get_pos_minimap(player, minimap);
	end.x = begin.x + 2;
	end.y = begin.y + 2;
	draw_rectangle(&minimap->screen, begin, end, 0xFFFFFF00);
}

void	draw_minimap(t_map *map, t_minimap *minimap)
{
	printf("draw_minimap\n");
	int x;
	int y;
	int color;
	t_vec2i	begin;
	t_vec2i end;
	
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
			if (map->grid[y][x] == '1')
				color = 0xFF0FFFfF;
			else
				color = 0xFF7F7F7F;
			draw_rectangle(&minimap->screen, begin, end, color);
			draw_line(&minimap->screen, vector2i(begin.x - 1, begin.y - 1), vector2i(begin.x - 1, begin.y - 1 + minimap->scale), 0xFF606060);
			draw_line(&minimap->screen, vector2i(begin.x - 1, begin.y - 1), vector2i(begin.x - 1 + minimap->scale, begin.y - 1), 0xFF606060);
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
	printf("\nrender_minimap\n");
	
	// draw_rectangle(&data->minimap, vector2i(0, 0), vector2i(MINIMAP_W - 1, MINIMAP_H - 1), 0xFF000000);

	draw_minimap(map, minimap);
	draw_line_to_border(minimap, player, 0xFF0000FF);
	draw_player(minimap, player);
}

void	render(t_data *data)
{
	printf("render\n");

	// draw_cub3d(data);
	render_minimap(&data->minimap, &data->map, &data->player);
    // mlx_put_image_to_window(data->mlx, data->cub.win, data->cub.img, 0, 0);
    mlx_put_image_to_window(data->mlx, data->minimap.screen.win, data->minimap.screen.img, 0, 0);
}
