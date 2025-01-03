/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:26:45 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/31 16:20:09 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "position.h"

t_position	position(int grid_x, float box_x, int grid_y, float box_y)
{
	t_position	pos;

	pos.x.grid = grid_x;
	pos.x.box = box_x;
	pos.y.grid = grid_y;
	pos.y.box = box_y;
	return (pos);
}

inline t_vec2d	position_to_vec2d(t_position pos)
{
	t_vec2d	pos_vec;

	pos_vec.x = pos.x.grid + pos.x.box;
	pos_vec.y = pos.y.grid + pos.y.box;
	return (pos_vec);	
}
