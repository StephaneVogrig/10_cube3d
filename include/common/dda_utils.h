/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:29:19 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/28 00:17:02 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DDA_UTILS_H
# define DDA_UTILS_H

# include "ray.h"
# include "map.h"

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

void	dda_init(t_dda *dda, t_vec2d *ray_vec, t_position *p, t_map *map);
int		dda_no_need(t_map *map, t_player *player, t_dda dda, int len_max);
void	dda_loop(t_dda *dda, t_ray *ray, t_map *map, int len_max);
void	dda_ray_set(t_ray *ray, t_dda *dda, t_player *player);

int		is_collide(t_map *map, t_ray *ray, t_dda *dda);

#endif
