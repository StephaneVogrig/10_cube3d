/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:08:37 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/08 16:29:36 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DRAW_WALL_UTILS_H
# define DRAW_WALL_UTILS_H

# include "vector.h"
# include "window.h"
# include "ray.h"
# include "strip.h"

// void	draw_wall(t_window *win, int x, double img_x, t_strip *draw);
int		hitpos_wall_texture(int texture_width, t_ray *ray);

#endif