/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:16:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/22 23:26:54 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "floor_ceil_mlx_img.h"
#include "render_manda.h"
#include "draw_walls_manda.h"

void	draw_floor_ceil(t_window *win, t_map *map, t_player *player)
{
	int		dark;

	dark = map_get_cell(map, &player->position) == WALL;
	floor_ceil_put_to_window(win, dark);
}

void	render(t_data *data)
{
	t_ray rays[data->win.width];

	window_clear(&data->win);
	raycasting(&data->map, &data->player, rays);
	draw_floor_ceil(&data->win, &data->map, &data->player);
	draw_walls(&data->win, rays, &data->textures);
}
