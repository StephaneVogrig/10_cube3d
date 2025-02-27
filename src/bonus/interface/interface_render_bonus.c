/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_render_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:03:52 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/05 18:56:37 by ygaiffie         ###   ########.fr       */
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
	draw_rectangle(interface, start, end, 0xBBFF4020);
}

void	render_interface(t_interface *interface, t_data *data)
{
	int	x_minimap;
	int	y_minimap;

	x_minimap = (MINIMAP_W >> 1) - data->player.x.grid * TILES_W;
	y_minimap = (MINIMAP_H >> 1) - data->player.y.grid * TILES_H;
	mlx_clear_window(interface->mlx, interface->win);
	mlx_put_image_to_window(interface->mlx, interface->win, interface->img_bg,
		0, 0);
	draw_image_minimap(interface, &data->player.position, &data->map);
	mlx_put_image_to_window(interface->mlx, interface->win, interface->img_map,
		0, 0);
	mlx_put_image_to_window(interface->mlx, interface->win, interface->img_fg,
		0, 0);
	draw_player(interface);
}
