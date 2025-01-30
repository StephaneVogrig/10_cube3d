/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:16:27 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/30 19:12:37 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_walls_manda.h"
#include "floor_ceil_mlx_img.h"
#include "render_manda.h"

void	render(t_data *data)
{
	data->dark = map_get_cell(&data->map, &data->player.position) == WALL;
	window_clear(&data->win);
	raycasting(data->rays.tab, data);
	floor_ceil_put_to_window(&data->win, data->dark);
	draw_walls(&data->win, data->rays.tab, data);
}
