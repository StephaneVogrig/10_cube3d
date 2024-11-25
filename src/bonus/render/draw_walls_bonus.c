/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:07 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 20:45:50 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "draw_walls_bonus.h"
#include "id_tex_bonus.h"

void	draw_walls(t_window *win, t_ray *rays, t_textures *textures)
{
	t_texture	*texture;
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		texture = &textures->tex[get_index_by_key(rays->hit_texture)];
		draw_wall(win, x, rays, texture);
		rays++;
		x++;
	}
}
