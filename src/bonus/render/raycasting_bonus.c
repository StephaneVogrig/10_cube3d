/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 15:11:12 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

void	raycast(t_ray *ray, t_position *start, t_data *data)
{
	char	*cell;

	cell = map_get_cell_ptr(&data->map, start);
	if (cell_is_door(cell) && (is_collide_door(ray, start, data)))
	{
		if (ray->hit_side == SIDE_DOOR_X || ray->hit_side == SIDE_EDGE_Y)
			ray->hit_axis = 'x';
		else
			ray->hit_axis = 'y';
		ray->hit_cell = cell;
		ray->dark = 0;
	}
	else
		dda(ray, start, data);
}

void	raycasting(t_ray *ray, t_data *data)
{
	t_vec2d	player_dirvec;
	t_vec2d	camera_step;
	t_vec2d	ray_vec;
	int		i;

	player_dirvec = dir_to_dirvec(data->player.dir);
	camera_step = ray_vec_step(player_dirvec, data->win.width, data->tg_fov_2);
	ray_vec = ray_vec_start(player_dirvec, data->tg_fov_2);
	i = 0;
	while (i < data->win.width)
	{
		ray->dirvec = ray_vec;
		raycast(ray, &data->player.position, data);
		ray_vec = vec2d_plus_vec2d(ray_vec, camera_step);
		ray++;
		i++;
	}
}
