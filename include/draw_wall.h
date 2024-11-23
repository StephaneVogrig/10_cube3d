/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:29 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/23 15:06:23 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DRAW_WALL_H
# define DRAW_WALL_H

# include "window.h"
# include "texture_manda.h"
# include "dda.h"
# include "color.h"

typedef	struct s_wall
{
	int			height;
	t_texture	*texture;
	float		x_in_texture;
	double		texture_dy;
}	t_wall;

typedef	struct s_draw_texture
{
	t_texture	*img;
	t_vec2i 	pixel;
	double		y;
	double		dy;
}	t_draw_texture;

void	draw_walls(t_window *win, t_ray *rays, t_textures *textures);

#endif