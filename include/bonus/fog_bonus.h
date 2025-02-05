/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:35:37 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/05 15:21:15 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOG_BONUS_H
# define FOG_BONUS_H

# include "color.h"
# include "math.h"

# define FOG_DENSITY 0.25

/*
 *	distance at which start the fog, in cell (float)
*/
# define FOG_DISTANCE_START 1.0

float	fog_compute(double distance, int fog_enable);
float	fog_exponential(double len);
void	fog_color(t_rgb *start, float fog);
void	fog_tab_fill(char *tab, float fog);
void	fog_color_with_tab(t_rgb *color, char *fog_tab);

#endif
