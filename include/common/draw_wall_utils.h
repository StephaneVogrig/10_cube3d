/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:08:37 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/05 23:05:49 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DRAW_WALL_UTILS_H
# define DRAW_WALL_UTILS_H

# include "texture.h"
# include "vector.h"
# include "window.h"
# include "ray.h"
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

int		wall_height(double ray_len);
void	draw_wall(t_window *win, int x, t_wall *wall, int dark);
void	draw_wall_big_pixel(t_window *win, int x, t_wall *wall, int dark);
void	draw_wall_small_pixel(t_window *win, int x, t_wall *wall, int dark);

#endif