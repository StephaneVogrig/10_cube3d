/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:30:04 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/13 23:51:34 by svogrig          ###   ########.fr       */
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

void	draw_minimap(t_data *data)
{
	printf("draw_minimap\n");
	t_vec2i	player;
	int x;
	int y;
	int color;

	y = 0;
	while (y <= MINIMAP_H)
	{
		draw_line(&data->minimap, vector2i(0, y), vector2i(MINIMAP_W, y), 0xFF000000);
		y++;
	}
	x = data->player.pos.x;
	y = data->player.pos.y;
	color = 0xFFFFFF00;
	mlx_set_image_pixel(data->mlx, data->minimap.img, x - 1, y - 1, color);
	mlx_set_image_pixel(data->mlx, data->minimap.img, x, y - 1, color);
	mlx_set_image_pixel(data->mlx, data->minimap.img, x + 1, y - 1, color);
	mlx_set_image_pixel(data->mlx, data->minimap.img, x - 1, y, color);
	mlx_set_image_pixel(data->mlx, data->minimap.img, x, y, color);
	mlx_set_image_pixel(data->mlx, data->minimap.img, x + 1, y, color);
	mlx_set_image_pixel(data->mlx, data->minimap.img, x - 1, y + 1, color);
	mlx_set_image_pixel(data->mlx, data->minimap.img, x, y + 1, color);
	mlx_set_image_pixel(data->mlx, data->minimap.img, x + 1, y + 1, color);
	
	x += sin(data->player.dir) * 50;
	y -= cos(data->player.dir) * 50;
	player.x = (int)data->player.pos.x;
	player.y = (int)data->player.pos.y;
	draw_line(&data->minimap, player, vector2i(x, y), 0xFFFF0000);

}

void	render(t_data *data)
{
	// printf("render\n");

	// printf("player x: %f y: %f dir: %f ", data->player.pos.x, data->player.pos.y, data->player.dir);
	// printf("cos: %f sin: %f key w: %d\n", cos(data->player.dir), sin(data->player.dir), data->key.w);
	draw_cub3d(data);
	draw_minimap(data);
    mlx_put_image_to_window(data->mlx, data->cub.win, data->cub.img, 0, 0);
    mlx_put_image_to_window(data->mlx, data->minimap.win, data->minimap.img, 0, 0);

}
