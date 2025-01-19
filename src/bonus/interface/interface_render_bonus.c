/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_render_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:03:52 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/19 18:41:20 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface_render_bonus.h"

void	draw_player(t_interface *interface, t_player *player)
{
	t_vec2i	start;
	t_vec2i	end;

	printf("interface->scale: %d\n", interface->scale);
	start.x = interface->scale * gridbox_to_double(player->x);
	start.y = interface->scale * gridbox_to_double(player->y);
	end.x = start.x + 2;
	end.y = start.y + 2;
	draw_rectangle(interface, start, end, 0xFFFFFF00);
}

// void	draw_interface(t_interface *interface, t_map *map)
// {
// 	int		x;
// 	int		y;
// 	int		color;
// 	t_vec2i	begin;
// 	t_vec2i	end;

// 	begin.y = 1;
// 	end.y = interface->scale - 1;
// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		begin.x = 1;
// 		end.x = interface->scale - 1;
// 		while (x < map->width)
// 		{
// 			if (map->grid[y][x] != 48)
// 				color = 0xFF0FFFfF;
// 			else
// 				color = 0xFF7F7F7F;
// 			// draw_rectangle(interface, begin, end, color);
// 			// draw_line(interface, vector2i(begin.x - 1, begin.y - 1),
// 				vector2i(begin.x - 1, begin.y - 1 + interface->scale),
// 				0xFF606060);
// 			// draw_line(interface, vector2i(begin.x - 1, begin.y - 1),
// 				vector2i(begin.x - 1 + interface->scale, begin.y - 1),
// 				0xFF606060);
// 			begin.x += interface->scale;
// 			end.x += interface->scale;
// 			x++;
// 		}
// 		begin.y += interface->scale;
// 		end.y += interface->scale;
// 		y++;
// 	}
// }

// void	draw_rays(t_interface *interface, t_player *player, t_ray_tab *rays)
// {
// 	// t_vec2i	start;
// 	// t_vec2i	end;
// 	// t_ray	*ray;
// 	// int		i;

// 	// start.x = interface->scale * gridbox_to_double(player->x);
// 	// start.y = interface->scale * gridbox_to_double(player->y);
// 	// i = 0;
// 	// ray = rays->tab;
// 	// while (i++ < rays->nbr)
// 	// {
// 	// 	end.x = interface->scale * gridbox_to_double(ray->hit_pos.x);
// 	// 	end.y = interface->scale * gridbox_to_double(ray->hit_pos.y);
// 	// 	// draw_line(interface, start, end, 0xFFFF0000);
// 	// 	ray++;
// 	// }
// }

void	render_interface(t_interface *interface, t_data *data)
{
	(void)data;
	mlx_put_image_to_window(interface->mlx, interface->win, interface->img_bg, 0, 0);
	mlx_put_image_to_window(interface->mlx, interface->win, interface->img_map, 72, 96);
	mlx_put_image_to_window(interface->mlx, interface->win, interface->img_fg, 0, 0);
	// draw_interface(interface, &data->map);
	// draw_rays(interface, &data->player, &data->rays);
	printf("player x: %d\n", data->player.x.grid);
	printf("player y: %d\n", data->player.y.grid);
	
	draw_player(interface, &data->player);
}
