/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:29 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:04:12 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_WALL_BONUS_H
# define DRAW_WALL_BONUS_H

# include "asset_bonus.h"
# include "color.h"
# include "dda_bonus.h"
# include "window.h"

typedef struct s_wall
{
	int			height;
	t_texture	*texture;
	float		x_in_texture;
	double		texture_dy;
}				t_wall;

typedef struct s_draw_texture
{
	t_texture	*img;
	t_vec2i		pixel;
	double		y;
	double		dy;
}				t_draw_texture;

void			draw_walls(t_window *win, t_ray *rays, t_asset *textures);

#endif