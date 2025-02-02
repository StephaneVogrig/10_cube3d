/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:22:02 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/02 13:49:39 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_bonus.h"

t_axis	door_get_direction(const t_map *map, t_position position)
{
	char	*cell_1;
	char	*cell_2;

	position.x.grid--;
	cell_1 = map_get_cell_ptr(map, &position);
	position.x.grid += 2;
	cell_2 = map_get_cell_ptr(map, &position);
	if (cell_is_wall_or_door(cell_1) && cell_is_wall_or_door(cell_2))
		return (AXIS_Y);
	position.x.grid--;
	position.y.grid--;
	cell_1 = map_get_cell_ptr(map, &position);
	position.y.grid += 2;
	cell_2 = map_get_cell_ptr(map, &position);
	if (cell_is_wall_or_door(cell_1) || cell_is_wall_or_door(cell_2))
		return (AXIS_X);
	return (AXIS_Y);
}

bool	is_in_closepart(float start_y, t_door *door)
{
	if (door->open_type == DOOR_OPEN_TYPE_L && (start_y < door->pos_edge))
		return (true);
	if (door->open_type == DOOR_OPEN_TYPE_R && (start_y > door->pos_edge))
		return (true);
	if (door->open_type == DOOR_OPEN_TYPE_T
		&& ((start_y < door->pos_edge) || (start_y > (1.0 - door->pos_edge))))
		return (true);
	return (false);
}

inline
bool	is_between_doorside(float start_x, t_door *door)
{
	if (start_x <= door->pos_side_down || start_x >= door->pos_side_up)
		return (false);
	return (true);
}

inline
bool	is_outside_door(float start_x, float start_y, t_door *door)
{
	if (start_y == 0.0 || start_y == 1.0)
		return (true);
	if (is_between_doorside(start_x, door) && is_in_closepart(start_y, door))
		return (false);
	return (true);
}
