/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:52:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/17 18:12:07 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include "vec2i.h"
# include "player.h"
# include "map.h"

typedef struct s_dda{
	t_vec2d	unit;
	t_vec2d	side;
	double	current;
}	t_dda;

/*
	return the length of the ray between the player and a wall.
	a sign is to indicate the axis hit by the ray
	positive is for x axis
	negative is for y axis
*/ 
double	dda(t_vec2d *raydir, t_map *map, t_player *player);

#endif