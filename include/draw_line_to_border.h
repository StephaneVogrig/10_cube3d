/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_to_border.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:46:17 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/22 19:13:43 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DRAW_LINE_TO_BORDER_H
# define DRAW_LINE_TO_BORDER_H

# include "screen.h"
# include "player.h"
# include "vec2i.h"
# include "draw_line.h"
# include "draw_line.h"
# include "minimap_bonus.h"
# include <math.h>

#define XMIN 10
#define YMIN 10
#define XMAX (minimap->screen.width - 10)
#define YMAX (minimap->screen.height - 10)

void	draw_line_to_border(t_minimap *minimap, t_player *player, int color);

#endif