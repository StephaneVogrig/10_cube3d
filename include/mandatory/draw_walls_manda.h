/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_manda.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:29 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:04:48 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_WALLS_MANDA_H
# define DRAW_WALLS_MANDA_H

# include "draw_wall_utils.h"
# include "ray.h"
# include "strip_manda.h"
# include "textures_manda.h"
# include "vector.h"
# include "window.h"

void	draw_walls(t_window *win, t_ray *rays, t_textures *textures,
			double scale);
void	draw_wall(t_window *win, int x, double img_x, t_strip *strip);

#endif