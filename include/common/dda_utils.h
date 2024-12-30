/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:29:19 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/30 15:41:32 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DDA_UTILS_H
# define DDA_UTILS_H

# include "ray.h"
# include "map.h"
# include "utils.h"

typedef struct s_dda_axis
{
	double	unit;
	double	len;
	int		step;
	int		current;
}	t_dda_axis;

typedef struct s_dda
{
	t_dda_axis	x;
	t_dda_axis	y;
	int			len_max;
	int			collide;
	char		hit_side;
	double		len;
}	t_dda;

void	dda_init(t_dda *dda, t_vec2d *ray_vec, t_position *start, t_map *map);
int		dda_no_need(t_map *map, t_position *start, t_dda *dda);
void	dda_ray_set(t_ray *ray, t_dda *dda, t_position *start);

#endif
