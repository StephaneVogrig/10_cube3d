/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_screen_height.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:16:29 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/02 23:16:59 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall_screen_height.h"

int	wall_screen_height(int screen_scale, double distance)
{
	float	size_f;
	int		size_i;

	if (distance == 0)
		return (INT_MAX);
	size_f = screen_scale / distance;
	if (size_f < 1.5)
		return (0);
	if (size_f > (float)INT_MAX)
		return (INT_MAX);
	size_i = (int)(size_f + 0.5);
	if (size_i % 2 == 1)
		size_i++;
	return (size_i);
}
