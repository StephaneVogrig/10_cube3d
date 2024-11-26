/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:08:37 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/26 12:55:48 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DRAW_WALL_H
# define DRAW_WALL_H

# include "asset.h"
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

void	draw_wall(t_window *win, int x, t_ray *ray, t_texture *texture);

#endif