/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:38:10 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/03 12:11:16 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef POSITION_H
# define POSITION_H

# include "gridbox.h"
# include "vector.h"
# include "axis.h"

typedef union u_position
{
	struct
	{
		t_gridbox	x;
		t_gridbox	y;
	};
	t_gridbox	axis[2];
}	t_position;

t_position	position(int grid_x, float box_x, int grid_y, float box_y);
t_vec2d		position_to_vec2d(t_position pos);

#endif
