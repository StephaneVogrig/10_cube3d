/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:11:05 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/28 14:21:18 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DRAW_LINE_BONUS_H
# define DRAW_LINE_BONUS_H

# include "draw_line_utils_bonus.h"
# include "minimap_bonus.h"
# include "mlx.h"

void	draw_line(t_minimap *minimap, t_vec2i a, t_vec2i b, int color);

#endif