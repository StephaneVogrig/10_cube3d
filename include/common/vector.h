/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:33:02 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/03 19:39:32 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "axis.h"

typedef struct s_vec2int
{
	struct
	{
		int		x;
		int		y;
	};
	int			axis[2];
}				t_vec2i;

typedef union u_vec2double
{
	struct
	{
		double	x;
		double	y;
	};
	double		axis[2];
}				t_vec2d;

t_vec2i		vector2i(int x, int y);
t_vec2d		vector2d(double x, double y);
void		vec2d_plus_vec2d(t_vec2d *vec_a, t_vec2d *vec_b);

#endif