/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:57:28 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 06:36:09 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DRAW_UTILS_BONUS_H
# define DRAW_UTILS_BONUS_H

#include "minimap_bonus.h"
#include "vector.h"

void	draw_rectangle(t_minimap *minimap, t_vec2i begin, t_vec2i end, int color);

#endif