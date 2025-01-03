/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:50:06 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/02 16:57:04 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "door_bonus.h"

t_door_open	*door_find(char *cell, t_door_open *door_open_list)
{
	int	i;

	i = 0;
	while (i++ < DOORS_SIZE)
	{
		if (door_open_list->cell == cell)
			return (door_open_list);
		door_open_list++;
	}
	return (NULL);
}

float	door_get_closing_rate(t_door_open *door)
{
	if (!door)
		return (1.0);
	if (door->stage == DOOR_OPEN)
		return (0.0);
	if (door->stage == DOOR_OPENING)
		return (door->stage_rate);
	if (door->stage == DOOR_CLOSING)
		return (1 - door->stage_rate);
	return (1.0);
}

void	door_open(char *cell, t_door_open *door_open_list)
{
	t_door_open	*door;

	door = door_find(cell, door_open_list);
	if (door == NULL)
		door = door_open_list_add(cell, door_open_list);
	else if (door->stage == DOOR_OPEN)
		door->stage_rate = 1.0;
	else if  (door->stage == DOOR_CLOSING)
	{
		door->stage_rate = 1.0 - door->stage_rate ;
		door->stage = DOOR_OPENING;
	}
}

void	door_fill(t_door *door, char cell, float closing_rate)
{
	if (cell == 'L')
	{
		door->open_type = DOOR_OPEN_TYPE_L;
		door->thick = DOOR_THICK_L;
		door->pos_edge = closing_rate;
		door->pos_edge_closed = 1.0;
	}
	if (cell == 'R')
	{
		door->open_type = DOOR_OPEN_TYPE_R;
		door->thick = DOOR_THICK_R;
		door->pos_edge = 1 - closing_rate;
		door->pos_edge_closed = 0.0;
	}
	if (cell == 'T')
	{
		door->open_type = DOOR_OPEN_TYPE_T;
		door->thick = DOOR_THICK_T;
		door->pos_edge = closing_rate / 2;
		door->pos_edge_closed = 0.5;
	}
	door->pos_side_down = 0.5 - door->thick / 2;
	door->pos_side_up = 0.5 + door->thick / 2;
}

void	door_init(t_door *door, char *cell, t_door_open *door_open_list)
{
	t_door_open	*door_ptr;
	float		closing_rate;

	door_ptr = door_find(cell, door_open_list);
	closing_rate = door_get_closing_rate(door_ptr);
	door_fill(door, *cell, closing_rate);
}
