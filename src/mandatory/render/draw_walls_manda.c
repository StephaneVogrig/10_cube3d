/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_manda.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:07 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/26 20:57:47 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_walls_manda.h"

t_texture	*texture_hit(t_assets *asset, t_ray *ray)
{
	if (ray->hit_side == 'n')
		return ((t_texture*)dict_get(asset->textures, "NO"));
	if (ray->hit_side == 's')
		return ((t_texture*)dict_get(asset->textures, "SO"));
	if (ray->hit_side == 'e')
		return ((t_texture*)dict_get(asset->textures, "EA"));
	return ((t_texture*)dict_get(asset->textures, "WE"));
}

void	draw_walls(t_window *win, t_ray *rays, t_assets *assets)
{
	t_texture	*texture;
	int			x;

	x = 0;
	while (x < WIN_W)
	{
		texture = texture_hit(textures, rays);
		draw_wall(win, x, rays, texture);
		rays++;
		x++;
	}
}
