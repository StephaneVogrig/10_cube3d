/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:11:05 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/16 17:50:55 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DRAWLINE_H
# define DRAWLINE_H

# include "draw_line_utils_bonus.h"
# include "minimap_utils_bonus.h"

void	draw_line(t_minimap *minimap, t_vec2i a, t_vec2i b, int color);

#endif