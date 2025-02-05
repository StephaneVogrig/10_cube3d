/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_render_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:03:52 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/05 13:03:15 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface_render_bonus.h"

void	draw_player(t_interface *interface)
{
	t_vec2i	start;
	t_vec2i	end;

	start.x = MINIMAP_W >> 1;
	start.y = MINIMAP_H >> 1;
	end.x = start.x + TILES_H - 1;
	end.y = start.y + TILES_W - 1;
	draw_rectangle(interface, start, end, 0xAAFFFF00);
}

void	render_interface(t_interface *interface, t_data *data)
{
	int	x_minimap;
	int	y_minimap;

	x_minimap = (MINIMAP_W >> 1) - data->player.x.grid * TILES_W;
	y_minimap = (MINIMAP_H >> 1) - data->player.y.grid * TILES_H;
	mlx_put_image_to_window(interface->mlx, interface->win, interface->img_bg,
		0, 0);
	mlx_put_image_to_window(interface->mlx, interface->win, interface->img_map,
		x_minimap, y_minimap);
	mlx_put_image_to_window(interface->mlx, interface->win, interface->img_fg,
		0, 0);
	draw_player(interface);
}
