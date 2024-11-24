/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixedpoint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:55:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 16:20:55 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FIXEDPOINT_H
# define FIXEDPOINT_H

typedef struct s_grid_box
{
	int		grid;
	float	box;
}	t_grid_box;

void	grid_box_add_double(t_grid_box	*gb, double d);
void	grid_box_add_grid_box(t_grid_box *a, t_grid_box *b);

#endif
