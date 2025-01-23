/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:48:25 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/23 18:48:54 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include <stdio.h>

int	strip_screen_size(int screen_scale, double distance)
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
	if (size_i % 2 == 0)
		size_i += 2;
	else
		size_i++;
	return (size_i);
}
