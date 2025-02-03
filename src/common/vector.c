/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:32:33 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/03 19:39:18 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2i	vector2i(int x, int y)
{
	t_vec2i	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

t_vec2d	vector2d(double x, double y)
{
	t_vec2d	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

void	vec2d_plus_vec2d(t_vec2d *vec_a, t_vec2d *vec_b)
{
	vec_a->x += vec_b->x;
	vec_a->y += vec_b->y;
}
