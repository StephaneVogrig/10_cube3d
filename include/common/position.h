/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:38:10 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:04:41 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_H
# define POSITION_H

# include "axis.h"
# include "gridbox.h"
# include "vector.h"

typedef union u_position
{
	struct
	{
		t_gridbox	x;
		t_gridbox	y;
	};
	t_gridbox		axis[2];
}					t_position;

t_position			position(int grid_x, float box_x, int grid_y, float box_y);
t_vec2d				position_to_vec2d(t_position pos);

#endif
