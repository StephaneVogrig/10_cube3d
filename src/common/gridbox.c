/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gridbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:12:43 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/28 16:12:16 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "gridbox.h"

inline void	gridbox_add_double(t_gridbox *gridbox, double value)
{
	int	int_part;

	int_part = (int)value;
	gridbox->grid += int_part;
	gridbox->box += value - int_part;
	if (gridbox->box >= 1.0)
	{
		gridbox->grid++;
		gridbox->box--;
	}
	else if (gridbox->box < 0.0)
	{
		gridbox->grid--;
		gridbox->box++;
	}
}

inline double	gridbox_to_double(t_gridbox gridbox)
{
	return ((double)gridbox.grid + gridbox.box);
}
