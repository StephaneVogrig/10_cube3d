/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/18 23:50:36 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "raycasting_bonus.h"

void	raycasting(t_map *map, t_player *player, t_ray *rays,
					t_door *door_open_list)
{
	t_vec2d	player_vdir;
	double	camera_step;
	t_vec2d	camera_step_vec;
	t_vec2d ray_vec;
	int		screen_x;

	player_vdir = dir_to_dirvec(player->dir);
	camera_step = 2.0 / WIN_W;
	camera_step_vec.x = -player_vdir.y * camera_step;
	camera_step_vec.y = player_vdir.x * camera_step;
	ray_vec.x = player_vdir.x + player_vdir.y;
	ray_vec.y = player_vdir.y - player_vdir.x;
	screen_x = 0;
	while (screen_x < WIN_W)
	{
		rays->vdir = ray_vec;
		dda(rays, map, &player->position, door_open_list);
		ray_vec = vec2d_plus_vec2d(ray_vec, camera_step_vec);
		rays++;
		screen_x++;
	}
}
