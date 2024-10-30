/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:52:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/30 20:34:53 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include "vec2i.h"
# include "player.h"
# include "map.h"
# include "libft.h"

typedef struct s_position{
	t_vec2i	grid;
	t_vec2d	box;
}	t_position;

typedef struct s_ray{
	double		len;
	t_position	hit_pos;
	char		hit_side;
} 	t_ray;

typedef struct s_dda{
	t_vec2d	unit;
	t_vec2d	side;
	double	current;
}	t_dda;

/*
	return :
	* the length of the ray between the player and a wall
	* the side where hit the ray
	* the position on grid and box where hit the ray
*/ 
t_ray	dda(t_vec2d *raydir, t_map *map, t_player *player, int len_max);

#endif