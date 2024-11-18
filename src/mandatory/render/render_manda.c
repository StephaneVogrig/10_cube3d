/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:16:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/18 18:09:39 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "floor_ceil_mlx_img.h"
#include "draw_wall.h"

void	render_draw_floor_ceil(t_window *win, t_map *map, t_player *player)
{
	int		dark;

	dark = map_get_grid(map, &player->position) == WALL;
	mlx_clear_window(win->mlx, win->win);
	floor_ceil_put_to_window(win, dark);
}

void	render(t_data *data)
{
	t_ray rays[WIN_W];

	render_draw_floor_ceil(&data->win, &data->map, &data->player);
	raycasting(&data->win, &data->map, &data->player, &rays[0]);
	draw_walls(&data->win, rays, &data->map.textures);
	fps_print(chrono(STOP));
}
