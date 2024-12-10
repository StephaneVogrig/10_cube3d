/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:50:06 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/10 10:50:43 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_bonus.h"

int is_hit_door(float pos_in_side, char *cell, t_door *door_open_list)
{
	float	closing_rate;

	if (pos_in_side < 0.0 || pos_in_side > 1.0) //todo: check why these situations come
		return (FALSE);
	closing_rate = door_get_closing_rate(cell, door_open_list);
	if (*cell == 'L' && pos_in_side > closing_rate)
		return (FALSE);
	if (*cell == 'R' && pos_in_side < 1 - closing_rate)
		return (FALSE);
	if (*cell == 'T'
		&& pos_in_side > closing_rate / 2
		&& pos_in_side < 1 - (closing_rate / 2))
		return (FALSE);
	return (TRUE);
}

int	cell_is_door(char cell)
{
	if (cell == 'R' || cell == 'L' || cell == 'T')
		return (TRUE);
	return (FALSE);
}

t_door	*door_find(char *cell, t_door *door_open_list)
{
	int	i;

	i = 0;
	while (i++ < DOORS_SIZE)
	{
		if (door_open_list->ptr_map == cell)
			return (door_open_list);
		door_open_list++;
	}
	return (NULL);
}

float	door_get_closing_rate(char *cell, t_door *door_open_list)
{
	t_door	*door;
	door = door_find(cell, door_open_list);
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

void	door_open(char *cell, t_door *door_open_list)
{
	t_door	*door;

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
