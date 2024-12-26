/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:32:37 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/26 13:42:13 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ray.h"

int	ray_setup(t_ray_tab *rays, int nbr)
{
	rays->tab = malloc(nbr * sizeof(*rays->tab));
	if (rays->tab == NULL)
	{
		printf("ray_setup: malloc fail\n");
		return (FAIL);
	}
	rays->nbr = nbr;
	return (SUCCESS);
}

void	ray_destroy(t_ray_tab *rays)
{
	if (rays->tab)
		free(rays->tab);
}

t_vec2d	ray_vec_start(t_vec2d player_dir_vec, double tg_fov_2)
{
	t_vec2d vec;

	vec.x = player_dir_vec.x + (player_dir_vec.y * tg_fov_2);
	vec.y = player_dir_vec.y - (player_dir_vec.x * tg_fov_2);
	return (vec);
}

t_vec2d	ray_vec_step(t_vec2d player_dir_vec, int win_w, double tg_fov_2)
{
	t_vec2d vec;
	double	step;

	step = 2.0 / win_w;
	step *= tg_fov_2;
	vec.x = -player_dir_vec.y * step;
	vec.y = player_dir_vec.x * step;
	return (vec);
}
