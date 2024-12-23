/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_manda.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/23 14:07:10 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "raycasting_manda.h"


t_vec2d	camera_step_vec(t_vec2d	player_dir_vec, t_ray_tab *rays)
{
	t_vec2d vec;
	double	step;

	step = 2.0 / rays->nbr;
	vec.x = -player_dir_vec.y * step;
	vec.y = player_dir_vec.x * step;
	return (vec);
}

void	raycasting(t_map *map, t_player *player, t_ray_tab *rays)
{
	t_vec2d	player_dir_vec;
	t_vec2d	camera_step;
	t_vec2d ray_vec;
	t_ray	*ray;
	int		i;

	player_dir_vec = dir_to_dirvec(player->dir);
	camera_step = camera_step_vec(player_dir_vec, rays);
	ray_vec.x = player_dir_vec.x + player_dir_vec.y;
	ray_vec.y = player_dir_vec.y - player_dir_vec.x;
	ray = rays->tab;
	i = 0;
	while (i < rays->nbr)
	{
		ray->vdir = ray_vec;
		dda(ray, map, &player->position);
		ray_vec = vec2d_plus_vec2d(ray_vec, camera_step);
		ray++;
		i++;
	}
}
