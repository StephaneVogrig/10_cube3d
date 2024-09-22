/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:52:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/22 18:56:29 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DDA_H
# define DDA_H

# include "vec2i.h"
# include "player.h"
# include "map.h"
# include "libft.h"

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