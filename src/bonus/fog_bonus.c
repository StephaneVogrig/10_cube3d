/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:35:05 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 15:01:44 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fog_bonus.h"

float	fog_compute(double distance, int fog_enable)
{
	if (fog_enable)
		return (fog_exponential(distance));
	return (1.0);
}

float	fog_exponential(double len)
{
	if (len < 1.0)
		return (1.0);
	return (exp(-DENSITY * (len - 1.0)));
}

void	fog_color(t_rgb *start, float fog)
{
	start->r *= fog;
	start->g *= fog;
	start->b *= fog;
}

void	fog_tab_fill(char *tab, float fog)
{
	int	i;

	*tab = 0;
	i = 1;
	while (i < 256)
	{
		tab[i] = i * fog;
		i++;
	}
}

void	fog_color_with_tab(t_rgb *color, char *fog_tab)
{
	color->r = fog_tab[color->r];
	color->g = fog_tab[color->g];
	color->b = fog_tab[color->b];
}
