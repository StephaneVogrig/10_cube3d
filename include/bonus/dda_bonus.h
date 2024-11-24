/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:52:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 16:40:13 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DDA_BONUS_H
# define DDA_BONUS_H

# include "player.h"
# include "ray.h"
# include "map.h"
# include "fixedpoint.h"
# include "position.h"

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

void	dda(t_ray *ray, t_map *map, t_player *player, int len_max);
char 	map_get_grid(t_map *map, t_position *p);

#endif