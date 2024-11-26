/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:18:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/26 17:01:06 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"

void	dda(t_ray *ray, t_map *map, t_player *player, int len_max)
{
	t_dda	dda;

	dda.len_max = len_max;
	dda_init(&dda, &ray->vdir, &player->position, map);
	if (dda_no_need(map, player, dda, len_max) == TRUE)
	{
		ray->len = len_max + 1;
		return ;
	}
	ray->hit_pos.x.grid = player->x.grid;
	ray->hit_pos.y.grid = player->y.grid;
	dda_loop(&dda, ray, map, len_max);
	dda_ray_set(ray, &dda, player);
}
