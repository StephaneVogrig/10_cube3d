/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixedpoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:12:43 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 16:21:41 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fixedpoint.h"

inline void	grid_box_add_double(t_grid_box	*gb, double d)
{
	double value;

	value = gb->grid + gb->box;
	value += d;
	gb->grid = (int)value;
	gb->box = value - gb->grid;
	if (gb->box < 0)
		gb->box += 1.0;
}

inline void	grid_box_add_grid_box(t_grid_box *a, t_grid_box *b)
{
	a->box += b->box;
	if (a->box >= 1.0)
	{
		a->box -= 1.0;
		a->grid += 1;
	}
	else if (a->box < 0.0)
	{
		a->box += 1.0;
		a->grid -= 1;
	}
	a->grid += b->grid;
}
