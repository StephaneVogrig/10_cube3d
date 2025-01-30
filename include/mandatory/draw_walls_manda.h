/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_manda.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:29 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/30 19:12:23 by svogrig          ###   ########.fr       */
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
# include "data_manda.h"

void	draw_walls(t_window *win, t_ray *rays, t_data *data);
void	draw_wall(t_window *win, int x, double img_x, t_strip *strip);

#endif