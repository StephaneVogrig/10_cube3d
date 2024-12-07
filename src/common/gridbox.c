/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gridbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:12:43 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/04 19:40:36 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "gridbox.h"

inline void	gridbox_add_double(t_gridbox	*fixpoint, double value)
{
	int		int_part;

	int_part = (int)value;
	fixpoint->grid += int_part;
	fixpoint->box += value - int_part;
	if (fixpoint->box >= 1.0)
	{
		fixpoint->grid++;
		fixpoint->box--;
	}
	else if (fixpoint->box < 0.0)
	{
		fixpoint->grid--;
		fixpoint->box++;
	}
}
