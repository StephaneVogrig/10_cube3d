/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:38:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/01 02:04:13 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_H
# define POSITION_H

# include "vec2i.h"

typedef struct s_grid_box
{
	int		grid;
	double	box;
}	t_grid_box;


typedef struct s_position{
	t_grid_box	x;
	t_grid_box	y;
}	t_position;

#endif
