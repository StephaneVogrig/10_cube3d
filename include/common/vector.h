/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:33:02 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 06:31:57 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec2int{
	int	x;
	int	y;
}	t_vec2i;

typedef struct s_vec2double{
	double	x;
	double	y;
}	t_vec2d;

t_vec2i	vector2i(int x, int y);
t_vec2d	vector2d(double x, double y);

#endif