/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/26 13:47:16 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "raycasting_bonus.h"

void	raycasting(t_ray *ray, t_data *data)
{
	t_vec2d	player_dir_vec;
	t_vec2d	camera_step;
	t_vec2d ray_vec;
	int		i;

	player_dir_vec = dir_to_dirvec(data->player.dir);
	camera_step = ray_vec_step(player_dir_vec, data->win.width, data->tg_fov_2);
	ray_vec = ray_vec_start(player_dir_vec, data->tg_fov_2);
	i = 0;
	while (i < data->win.width)
	{
		ray->vdir = ray_vec;
		dda(ray, &data->player.position, data);
		ray_vec = vec2d_plus_vec2d(ray_vec, camera_step);
		ray++;
		i++;
	}
}
