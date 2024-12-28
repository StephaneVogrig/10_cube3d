/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_render_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:04:34 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/28 15:12:21 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MINIMAP_RENDER_BONUS_H
# define MINIMAP_RENDER_BONUS_H

# include "ray.h"
# include "draw_utils_bonus.h"
# include "draw_line_bonus.h"
# include "data_bonus.h"
# include "minimap_bonus.h"

void	render_minimap(t_minimap *minimap, t_data *data);

#endif