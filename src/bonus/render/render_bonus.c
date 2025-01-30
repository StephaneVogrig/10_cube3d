/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:30:04 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/31 12:05:03 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

// int	player_is_inside_door(t_player *player, char *cell)
// {
// 	if (!cell_is_door(cell))
// 		return (FALSE);
// 	if (is_outside_door())
// 	return (TRUE);
// }

void	render(t_data *data)
{
	char *cell;

	cell = map_get_cell_ptr(&data->map, &data->player.position);
	data->in_wall = cell_is_wall(cell);
	// data->in_door = player_is_inside_door(&data->player, cell);
	data->dark = data->in_wall | data->in_door;
	window_clear(&data->win);
	raycasting(data->rays.tab, data);
	draw_floor_ceil(data);
	draw_walls(&data->win, data->rays.tab, data);
	sprite_render(&data->sprite, &data->player, data);
	render_interface(&data->minimap, data);
}
