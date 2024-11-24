/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:11:05 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 05:53:07 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DRAW_LINE_BONUS_H
# define DRAW_LINE_BONUS_H

# include "mlx.h"
# include "draw_line_utils_bonus.h"
# include "minimap_utils_bonus.h"

void	draw_line(t_minimap *minimap, t_vec2i a, t_vec2i b, int color);

#endif