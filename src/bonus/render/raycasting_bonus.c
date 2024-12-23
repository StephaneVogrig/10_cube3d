/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/23 18:42:08 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "raycasting_bonus.h"

void	raycasting(t_map *map, t_player *player, t_ray_tab *rays,
					t_door *door_open_list)
{
	t_vec2d	player_vdir;
	double	camera_step;
	t_vec2d	camera_step_vec;
	t_vec2d ray_vec;
	t_ray	*ray;
	int		screen_x;

	player_vdir = dir_to_dirvec(player->dir);
	camera_step = 2.0 / rays->nbr;
	camera_step_vec.x = -player_vdir.y * camera_step;
	camera_step_vec.y = player_vdir.x * camera_step;
	ray_vec.x = player_vdir.x + player_vdir.y;
	ray_vec.y = player_vdir.y - player_vdir.x;
	screen_x = 0;
	ray = rays->tab;
	while (screen_x < rays->nbr)
	{
		ray->vdir = ray_vec;
		dda(ray, map, &player->position, door_open_list);
		ray_vec = vec2d_plus_vec2d(ray_vec, camera_step_vec);
		ray++;
		screen_x++;
	}
}
