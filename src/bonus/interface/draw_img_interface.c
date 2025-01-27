/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_interface.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:40:43 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 13:24:58 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_img_interface.h"

void	draw_image_bg(t_interface *interface, t_vec2i start, t_vec2i end)
{
	int				x;
	int				y;
	unsigned int	color;
	t_vec2i			pos;

	y = start.y;
	while (y < end.y)
	{
		x = start.x;
		while (x < end.x)
		{
			pos.x = x - start.x;
			pos.y = y - start.y;
			color = texture_get_color(&interface->bg, pos.x, pos.y);
			if (color != 0xFF000000)
				mlx_set_image_pixel(interface->mlx, interface->img_bg, x, y,
					color);
			x++;
		}
		y++;
	}
}

void	draw_image_fg(t_interface *interface, t_vec2i start, t_vec2i end)
{
	int				x;
	int				y;
	unsigned int	color;
	t_vec2i			pos;

	y = start.y;
	while (y < end.y)
	{
		x = start.x;
		while (x < end.x)
		{
			pos.x = x - start.x;
			pos.y = y - start.y;
			color = texture_get_color(&interface->fg, pos.x, pos.y);
			if (color != 0xFF000000)
				mlx_set_image_pixel(interface->mlx, interface->img_fg, x, y,
					color);
			x++;
		}
		y++;
	}
}

int	draw_images(t_interface *interface, t_map *map)
{
	t_vec2i	start;
	t_vec2i	end;

	start = vector2i(0, 0);
	end = vector2i(MINIMAP_W, MINIMAP_H);
	interface->img_bg = mlx_new_image(interface->mlx, MINIMAP_W, MINIMAP_H);
	if (interface->img_bg == NULL)
		return (FAIL);
	draw_image_bg(interface, start, end);
	interface->img_fg = mlx_new_image(interface->mlx, MINIMAP_W, MINIMAP_H);
	if (interface->img_fg == NULL)
		return (FAIL);
	draw_image_fg(interface, start, end);
	interface->img_map = mlx_new_image(interface->mlx, map->width * TILES_W,
			map->height * TILES_H);
	if (interface->img_map == NULL)
		return (FAIL);
	draw_image_minimap(interface, start, vector2i(map->width * TILES_W,
			map->height * TILES_H), map);
	return (SUCCESS);
}
