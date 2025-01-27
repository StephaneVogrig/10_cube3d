/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:16:27 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:02:45 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_walls_manda.h"
#include "floor_ceil_mlx_img.h"
#include "render_manda.h"

void	draw_floor_ceil(t_window *win, t_map *map, t_player *player)
{
	int	dark;

	dark = map_get_cell(map, &player->position) == WALL;
	floor_ceil_put_to_window(win, dark);
}

void	render(t_data *data)
{
	window_clear(&data->win);
	raycasting(data->rays.tab, data);
	draw_floor_ceil(&data->win, &data->map, &data->player);
	draw_walls(&data->win, data->rays.tab, &data->textures, data->scale_screen);
}
