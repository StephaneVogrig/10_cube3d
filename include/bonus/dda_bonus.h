/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:52:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/23 19:17:33 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DDA_BONUS_H
# define DDA_BONUS_H

# include "vec2i.h"
# include "player.h"
# include "libft.h"
# include "position.h"
# include "map_bonus.h"

typedef struct s_ray
{
	t_vec2d		vdir;
	double		len;
	t_position	hit_pos;
	char		hit_side;
	int			dark;
} 	t_ray;

typedef struct s_dda_
{
	double	unit;
	double	len;
	int		step;
}	t_dda_;

typedef struct s_dda
{
	t_dda_	x;
	t_dda_	y;
	int		len_max;
	int		collide;
}	t_dda;

/*
	return :
	* the length of the ray between the player and a wall
	* the side where hit the ray
	* the position on grid and box where hit the ray
*/ 
void	dda(t_ray *ray, t_map *map, t_player *player, int len_max);
char 	map_get_grid(t_map *map, t_position *p);

#endif