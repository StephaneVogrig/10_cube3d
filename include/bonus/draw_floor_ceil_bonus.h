/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceil_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:56:00 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/27 23:58:26 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DRAW_FLOOR_CEIL_H
# define DRAW_FLOOR_CEIL_H

# include "data_bonus.h"
# include "pointer_table_bonus.h"
# include "ray.h"

typedef struct s_element
{
	t_texture	*tex;
	int			y;
}	t_element;

typedef struct s_context
{
	int			dark;
	t_window	*win;
	t_vec2d		box;
}	t_context;

typedef struct s_floorceil_draw
{
	t_element	ceil;
	t_element	floor;
	t_context	context;
}	t_floorceil_draw;

void	draw_floor_ceil(t_data *data, t_ray *rays, int dark);

#endif