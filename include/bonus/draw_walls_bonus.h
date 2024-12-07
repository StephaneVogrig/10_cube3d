/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:29 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/07 12:53:15 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DRAW_WALLS_BONUS_H
# define DRAW_WALLS_BONUS_H

# include "window.h"
# include "ray.h"
# include "draw_wall_utils.h"
# include "textures_bonus.h"
# include "door_bonus.h"

void	draw_walls(t_window *win, t_ray *rays, t_textures *textures, t_door *door_open_list);

#endif