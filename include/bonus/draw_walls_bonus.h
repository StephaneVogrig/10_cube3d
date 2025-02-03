/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:29 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/03 21:39:54 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_WALLS_BONUS_H
# define DRAW_WALLS_BONUS_H

# include "asset_bonus.h"
# include "color.h"
# include "data_bonus.h"
# include "door_bonus.h"
# include "draw_wall_utils.h"
# include "fog_bonus.h"
# include "pointer_table_bonus.h"
# include "ray.h"
# include "strip_bonus.h"
# include "vector.h"
# include "window.h"

void	draw_walls(t_window *win, t_ray *rays, t_data *data);
void	draw_wall(t_window *win, int x, double img_x, t_strip *strip);

#endif