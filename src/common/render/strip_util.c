/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:48:25 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/08 18:48:53 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "limits.h"

int	strip_screen_size(int screen_scale, double distance)
{
	float size;

	if (distance == 0)
		return (INT_MAX);
	size = screen_scale / distance;
	if (size > INT_MAX)
		return (INT_MAX);
	return ((int)size);
}
