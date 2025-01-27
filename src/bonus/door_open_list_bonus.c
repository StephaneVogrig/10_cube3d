/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_open_list_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 21:35:31 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 15:01:40 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_bonus.h"

static inline float	door_time_stage(t_stage stage)
{
	if (stage == DOOR_OPENING)
		return (TIME_OPENING);
	if (stage == DOOR_OPEN)
		return (TIME_OPEN);
	if (stage == DOOR_CLOSING)
		return (TIME_CLOSING);
	return (10.0);
}

static inline void	door_update_state(t_door_open *door, t_time_us dt_us)
{
	double	dt_second;
	double	time_stage;

	dt_second = (double)dt_us / USECOND_PER_SECOND;
	while (dt_second > 0.0)
	{
		time_stage = door_time_stage(door->stage);
		door->stage_rate -= dt_second / time_stage;
		if (door->stage_rate <= 0.0)
		{
			if (door->stage == DOOR_CLOSING)
			{
				door->cell = NULL;
				break ;
			}
			dt_second = -door->stage_rate * time_stage;
			door->stage_rate = 1.0;
			door->stage++;
		}
		else
			dt_second = 0.0;
	}
}

int	door_open_list_update(t_door_open *door_open_list, t_time_us dt)
{
	int	i;
	int	render_needed;

	render_needed = FALSE;
	i = 0;
	while (i++ < DOORS_SIZE)
	{
		if (door_open_list->cell != NULL)
		{
			door_update_state(door_open_list, dt);
			render_needed = TRUE;
		}
		door_open_list++;
	}
	return (render_needed);
}

static inline void	door_open_list_init(t_door_open *door, char *cell)
{
	door->cell = cell;
	door->stage_rate = 1.0;
	door->stage = DOOR_OPENING;
}

t_door_open	*door_open_list_add(char *cell, t_door_open *door_open_list)
{
	int	i;

	i = 0;
	while (i++ < DOORS_SIZE && door_open_list->cell != NULL)
		door_open_list++;
	if (i == DOORS_SIZE)
	{
		printf("not enough place in door_open_list to open to add door!\n");
		return (NULL);
	}
	door_open_list_init(door_open_list, cell);
	return (door_open_list);
}
