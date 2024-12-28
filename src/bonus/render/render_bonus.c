/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:30:04 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/28 15:07:27 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "render_bonus.h"

void	render(t_data *data)
{
	int		dark;

	window_clear(&data->win);
	raycasting(data->rays.tab, data);
	dark = map_get_cell(&data->map, &data->player.position) == WALL;
	draw_floor_ceil(data, data->rays.tab, dark);
	draw_walls(&data->win, data->rays.tab, data);
	sprite_render(&data->sprite, &data->player, &data->win, data);
	render_minimap(&data->minimap, data);
}
