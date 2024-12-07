/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:13:08 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/05 23:58:33 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RAY_H
# define RAY_H

# include "vector.h"
# include "position.h"

typedef struct s_ray
{
	t_vec2d		vdir;
	double		len;
	t_position	hit_pos;
	char		*hit_cell;
	char		hit_side;
	int			dark;
} 	t_ray;

#endif