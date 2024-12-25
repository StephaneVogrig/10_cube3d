/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/24 20:42:53 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "raycasting_bonus.h"

void	raycasting(t_ray_tab *rays, t_data *data)
{
	t_vec2d	player_dir_vec;
	double	camera_step;
	t_vec2d	camera_step_vec;
	t_vec2d ray_vec;
	t_ray	*ray;
	int		screen_x;

	player_dir_vec = dir_to_dirvec(data->player.dir);
	camera_step = 2.0 / rays->nbr;
	camera_step_vec.x = -player_dir_vec.y * camera_step;
	camera_step_vec.y = player_dir_vec.x * camera_step;
	ray_vec.x = player_dir_vec.x + player_dir_vec.y;
	ray_vec.y = player_dir_vec.y - player_dir_vec.x;
	screen_x = 0;
	ray = rays->tab;
	while (screen_x < rays->nbr)
	{
		ray->vdir = ray_vec;
		dda(ray, &data->player.position, data);
		ray_vec = vec2d_plus_vec2d(ray_vec, camera_step_vec);
		ray++;
		screen_x++;
	}
}
