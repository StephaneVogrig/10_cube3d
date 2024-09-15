/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_to_border.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:46:17 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/15 15:55:41 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_LINE_TO_BORDER_H
# define DRAW_LINE_TO_BORDER_H

# include "screen.h"
# include "player.h"
# include "vec2i.h"
# include "draw_line.h"
# include <math.h>

void	draw_line_to_border(t_screen *screen, t_player player, int color);

#endif