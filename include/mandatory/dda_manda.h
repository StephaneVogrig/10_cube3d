/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_manda.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:52:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 03:29:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DDA_MANDA_H
# define DDA_MANDA_H

# include "player.h"
# include "ray.h"
# include "map_manda.h"

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