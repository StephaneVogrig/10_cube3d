/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:07 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 03:35:33 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "draw_walls_bonus.h"

t_texture	*texture_hit(t_textures *textures, t_ray *ray)
{
	(void)ray;
	return (&textures->tex[1]);
}

void	draw_walls(t_window *win, t_ray *rays, t_textures *textures)
{
	t_texture	*texture;
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		texture = texture_hit(textures, rays);
		draw_wall(win, x, rays, texture);
		rays++;
		x++;
	}
}
