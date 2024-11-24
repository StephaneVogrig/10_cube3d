/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:32:33 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 06:32:38 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "vector.h"

t_vec2i	vector2i(int x, int y)
{
	t_vec2i	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

t_vec2d	vector2d(double x, double y)
{
	t_vec2d	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}
