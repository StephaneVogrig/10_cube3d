/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:57:28 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/16 16:57:02 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DRAW_UTILS_H
# define DRAW_UTILS_H

#include "minimap_bonus.h"
#include "vec2i.h"

void	draw_rectangle(t_minimap *minimap, t_vec2i begin, t_vec2i end, int color);

#endif