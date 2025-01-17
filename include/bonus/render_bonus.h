/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:30:18 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/28 15:17:50 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RENDER_BONUS_H
# define RENDER_BONUS_H

# include "data_bonus.h"
# include "draw_floor_ceil_bonus.h"
# include "draw_walls_bonus.h"
# include "minimap_render_bonus.h"
# include "raycasting_bonus.h"
# include "sprite_render_bonus.h"

# include "window.h"

void	render(t_data *data);

#endif