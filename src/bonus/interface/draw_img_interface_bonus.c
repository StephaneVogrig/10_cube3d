/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_interface_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:40:43 by aska              #+#    #+#             */
/*   Updated: 2025/02/05 22:21:44 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_img_interface_bonus.h"

void	draw_image_bg(t_interface *interface, t_vec2i start, t_vec2i end)
{
	int		x;
	int		y;
	t_rgb	color;
	t_vec2i	pos;

	y = start.y;
	while (y < end.y)
	{
		x = start.x;
		while (x < end.x)
		{
			pos.x = x - start.x;
			pos.y = y - start.y;
			texture_get_color(&color, &interface->bg, pos.x, pos.y);
			if (color.integer != 0xFF000000)
				mlx_set_image_pixel(interface->mlx, interface->img_bg, x, y,
					color.integer);
			x++;
		}
		y++;
	}
}

void	draw_image_fg(t_interface *interface, t_vec2i start, t_vec2i end)
{
	int		x;
	int		y;
	t_rgb	color;
	t_vec2i	pos;

	y = start.y;
	while (y < end.y)
	{
		x = start.x;
		while (x < end.x)
		{
			pos.x = x - start.x;
			pos.y = y - start.y;
			texture_get_color(&color, &interface->fg, pos.x, pos.y);
			if (color.integer != 0xFF000000)
				mlx_set_image_pixel(interface->mlx, interface->img_fg, x, y,
					color.integer);
			x++;
		}
		y++;
	}
}

int	draw_images(t_interface *interface)
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
	interface->img_map = mlx_new_image(interface->mlx, MINIMAP_W, MINIMAP_H);
	if (interface->img_map == NULL)
		return (FAIL);
	return (SUCCESS);
}
