/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:32:37 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 15:49:37 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_vec2d	ray_vec_start(t_vec2d player_dirvec, double tg_fov_2)
{
	t_vec2d	vec;

	vec.x = player_dirvec.x + (player_dirvec.y * tg_fov_2);
	vec.y = player_dirvec.y - (player_dirvec.x * tg_fov_2);
	return (vec);
}

t_vec2d	ray_vec_step(t_vec2d player_dirvec, int win_w, double tg_fov_2)
{
	t_vec2d	vec;
	double	step;

	step = 2.0 / win_w;
	step *= tg_fov_2;
	vec.x = -player_dirvec.y * step;
	vec.y = player_dirvec.x * step;
	return (vec);
}
