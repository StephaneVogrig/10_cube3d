/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:30:18 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/27 03:16:50 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RENDER_BONUS_H
# define RENDER_BONUS_H

# include <math.h>
# include "data_bonus.h"
# include "raycasting_bonus.h"
# include "draw_floor_ceil_bonus.h"
# include "draw_utils_bonus.h"
# include "draw_line_bonus.h"
# include "draw_walls_bonus.h"
# include "sprite_bonus.h"
# include "option_bonus.h"
# include "sprite_render_bonus.h"

void	render(t_data *data);

#endif