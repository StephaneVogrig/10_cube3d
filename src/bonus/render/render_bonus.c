/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:30:04 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/01 13:20:03 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

static
int	player_inside_door(t_position *position, char *cell, t_data *data)
{
	t_door	door;
	t_axis	x;
	t_axis	y;

	if (!cell_is_door(cell))
		return (FALSE);
	door_init(&door, cell, data->door_open_list);
	x = door_get_direction(&data->map, *position);
	y = y_with_x(x);
	if (is_outside_door(position->axis[x].box, position->axis[y].box, &door))
		return (FALSE);
	return (TRUE);
}

void	render(t_data *data)
{
	char	*cell;

	cell = map_get_cell_ptr(&data->map, &data->player.position);
	data->in_wall = cell_is_wall(cell);
	if (data->in_wall)
		data->in_door = FALSE;
	else
		data->in_door = player_inside_door(&data->player.position, cell, data);
	data->dark = data->in_wall | data->in_door;
	window_clear(&data->win);
	raycasting(data->rays.tab, data);
	draw_floor_ceil(data);
	draw_walls(&data->win, data->rays.tab, data);
	sprite_render(&data->sprite, &data->player, data);
	render_interface(&data->minimap, data);
}
