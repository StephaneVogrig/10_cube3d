/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:29 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/10 15:27:14 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_WALLS_BONUS_H
# define DRAW_WALLS_BONUS_H

# include "window.h"
# include "ray.h"
# include "draw_wall_utils.h"
# include "asset_bonus.h"
# include "door_bonus.h"

void	draw_walls(t_window *win, t_ray *rays, t_textures *textures, t_door *door_open_list);

#endif