/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:26:45 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/22 20:32:34 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "position.h"

inline t_vec2d	position_to_vec2d(t_position pos)
{
	t_vec2d	pos_vec;

	pos_vec.x = pos.x.grid + pos.x.box;
	pos_vec.y = pos.y.grid + pos.y.box;
	return (pos_vec);	
}
