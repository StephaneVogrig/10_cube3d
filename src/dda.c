/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:53:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/17 18:14:06 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"

void	dda_init(t_dda *raylen, t_vec2i *step, t_vec2d *raydir, t_vec2d *box)
{
	raylen->unit.x = fabs(1 / raydir->x);
	raylen->unit.y = fabs(1 / raydir->y);
	if (raydir->x < 0)
	{
		step->x = -1;
		raylen->side.x = box->x * raylen->unit.x;
	}
	else
	{
		step->x = 1;
		raylen->side.x = (1 - box->x) * raylen->unit.x;
	}
	if (raydir->y < 0)
	{
		step->y = -1;
		raylen->side.y = box->y * raylen->unit.y;
	}
	else
	{
		step->y = 1;
		raylen->side.y = (1 - box->y) * raylen->unit.y;
	}
}

double	dda(t_vec2d *raydir, t_map *map, t_player *player)
{
	t_dda	raylen;
	t_vec2i	step;
	t_vec2i	mapcheck;

	dda_init(&raylen, &step, raydir, &player->box);
	mapcheck = player->grid;
	while (TRUE)
	{
		if (raylen.side.x < raylen.side.y)
		{		
			raylen.current = raylen.side.x;
			mapcheck.x += step.x;
			raylen.side.x += raylen.unit.x;
		}
		else
		{
			raylen.current = -raylen.side.y;
			mapcheck.y += step.y;
			raylen.side.y += raylen.unit.y;
		}
		if (mapcheck.x < 0 ||mapcheck.y < 0 || mapcheck.x >= map->width || mapcheck.y >= map->height || map->grid[mapcheck.y][mapcheck.x] == '1')
			break;
	}
	return (raylen.current);
}
