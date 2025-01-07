/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:35:05 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/07 23:30:36 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "fog_bonus.h"
#include "math.h"

float	fog_linear(double len)
{
	if (len > FOG_DISTBACK)
		return (0.0);
	if (len < FOG_DISTFRONT)
		return (1.0);
	return ((FOG_DISTBACK - len) / (FOG_DISTBACK - FOG_DISTFRONT));
}

float	fog_exponential(double len)
{
	return (exp(-DENSITY * len));
}

int	fog_color(int start, float fog)
{
	t_rgb	color;
	t_rgb	foged;

	color = (t_rgb)start;
	if (fog > 0.0)
	{
			foged.r = (unsigned char)color.r * fog;
			foged.g = (unsigned char)color.g * fog;
			foged.b = (unsigned char)color.b * fog;
	}
	return (foged.integer);
}