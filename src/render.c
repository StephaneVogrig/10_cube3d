/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:30:04 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/15 18:25:50 by svogrig          ###   ########.fr       */
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


void	draw_player(t_screen *screen, t_player player)
{
	printf("draw_player \n");
	t_vec2i begin;
	t_vec2i end;
	
	begin.x = (int)player.pos.x - 1;
	begin.y = (int)player.pos.y - 1;
	end.x = begin.x + 2;
	end.y = begin.y + 2;
	draw_rectangle(screen, begin, end, 0xFFFFFF00);
}

int	scale_compute(t_map map, t_screen minimap)
{
	t_vec2i	scale;

	scale.x = minimap.width / map.width;
	scale.y = minimap.height / map.height;
	if (scale.y < scale.x)
		return (scale.y);
	return (scale.x);
}

void	draw_minimap(t_map map, t_screen minimap)
{
	printf("draw_minimap\n");
	int x;
	int y;
	int color;
	int scale;
	t_vec2i	begin;
	t_vec2i end;
	
	scale = scale_compute(map, minimap);
	begin.y = 1;
	end.y = scale - 1;
	y = 0;
	while (y < map.height)
	{
		// printf("y: %i\n", y);
		x = 0;
		begin.x = 1;
		end.x = scale - 1;
		while (x < map.width)
		{
			// printf("x: %i\n", x);
			if (map.grid[y][x] == '1')
				color = 0xFF0FFFfF;
			else
				color = 0xFF7F7F7F;
			draw_rectangle(&minimap, begin, end, color);
			draw_line(&minimap, vector2i(begin.x - 1, begin.y - 1), vector2i(begin.x - 1, begin.y - 1 + scale), 0xFF606060);
			draw_line(&minimap, vector2i(begin.x - 1, begin.y - 1), vector2i(begin.x - 1 + scale, begin.y - 1), 0xFF606060);
			begin.x += scale;
			end.x += scale;
			x++;
		}
		begin.y += scale;
		end.y += scale;
		y++;
	}
	// t_vec2i	player;
	// int x;
	// player.x = (int)data->player.pos.x;
	// player.y = (int)data->player.pos.y;
	// x = player.x + sin(data->player.dir) * 50;
	// y = player.y - cos(data->player.dir) * 50;
	// draw_line(&data->minimap, player, vector2i(x, y), 0xFFFF0000);

}
void	render_minimap(t_data *data)
{
	printf("\nrender_minimap\n");
	
	// draw_rectangle(&data->minimap, vector2i(0, 0), vector2i(MINIMAP_W - 1, MINIMAP_H - 1), 0xFF000000);

	draw_minimap(data->map, data->minimap);
	// draw_line(&data->minimap, vector2i(0,0), vector2i(data->minimap.width, data->minimap.height), 0xFFFFFFFF);
	draw_line_to_border(&data->minimap, data->player, 0xFF0000FF);
	draw_player(&data->minimap, data->player);
}

void	render(t_data *data)
{
	printf("render\n");

	// draw_cub3d(data);
	render_minimap(data);
    // mlx_put_image_to_window(data->mlx, data->cub.win, data->cub.img, 0, 0);
    mlx_put_image_to_window(data->mlx, data->minimap.win, data->minimap.img, 0, 0);
}
