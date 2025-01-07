/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:35:37 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/07 23:54:08 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FOG_BONUS_H
# define FOG_BONUS_H

# include "color.h"

# define FOG_DISTFRONT 1.0
# define FOG_DISTBACK 8
# define DENSITY 0.25

float	fog_linear(double len);
float	fog_exponential(double len);
int		fog_color(int color, float fog);

#endif