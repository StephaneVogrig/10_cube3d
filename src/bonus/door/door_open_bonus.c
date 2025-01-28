/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_open_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 01:13:38 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/28 01:14:17 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_open_bonus.h"

void	open_door_auto(t_map *map, int x, int y, t_door_open *door_open_list)
{
	char		*cell;
	t_position	pos;

	pos = position(x, 0.0, y, 0.0);
	cell = map_get_cell_ptr(map, &pos);
	if (cell && *cell == 'T')
		door_open(cell, door_open_list);
}

void	open_door_auto_near_player(t_data *data, t_map *map,
		t_door_open *door_open_list)
{
	int	x;
	int	y;

	x = data->player.x.grid;
	y = data->player.y.grid;
	open_door_auto(map, x, y, door_open_list);
	open_door_auto(map, x - 1, y, door_open_list);
	open_door_auto(map, x + 1, y, door_open_list);
	open_door_auto(map, x, y - 1, door_open_list);
	open_door_auto(map, x, y + 1, door_open_list);
}
