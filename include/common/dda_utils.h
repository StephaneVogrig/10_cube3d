/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:29:19 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/02 19:12:41 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DDA_UTILS_H
# define DDA_UTILS_H

# include "ray.h"
# include "map.h"

typedef struct s_dda_axis
{
	double	unit;
	double	len;
	int		step;
}	t_dda_axis;

typedef struct s_dda
{
	t_dda_axis	x;
	t_dda_axis	y;
	int			len_max;
	int			collide;
}	t_dda;

int		dda_no_need(t_map *map, t_position *start, t_dda dda, int len_max);
void	dda_loop(t_dda *dda, t_ray *ray, t_map *map, int len_max);
void	dda_ray_set(t_ray *ray, t_dda *dda, t_position *start);

void	dda_init(t_dda *dda, t_vec2d *ray_vec, t_position *start, t_map *map);

int		cell_is_wall(char cell);

void	dda_set(t_dda_axis *dda, double ray_vec, double box);

int		is_collide(t_map *map, t_ray *ray, t_dda *dda);

#endif
