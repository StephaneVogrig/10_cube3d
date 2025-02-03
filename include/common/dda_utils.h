/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:29:19 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/03 19:54:44 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_UTILS_H
# define DDA_UTILS_H

# include <stdbool.h>
# include "map.h"
# include "ray.h"
# include "position.h"
# include "utils.h"
# include "vector.h"
# include "wall_screen_height.h"

typedef struct s_dda_axis
{
	double		unit;
	double		len;
	int			step;
	int			current;
}				t_dda_axis;

typedef struct s_dda
{
	t_dda_axis	x;
	t_dda_axis	y;
	int			len_max;
	char		hit_side;
	double		len;
}				t_dda;

void	dda_init(t_dda *dda, t_vec2d *ray_vec, t_position *start,
			float scale_screen);
bool	dda_no_need(t_map *map, t_position *start, t_dda *dda);
void	dda_ray_set(t_ray *ray, t_dda *dda, t_position *start,
			float scale_screen);
void	dda_ray_set_axis(t_ray *ray, t_dda *dda);
int		wall_screen_height(int screen_scale, double distance);

#endif
