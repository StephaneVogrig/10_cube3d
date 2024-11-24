/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:38:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 06:32:38 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef POSITION_H
# define POSITION_H

# include "vector.h"

typedef struct s_grid_box
{
	int		grid;
	float	box;
}	t_grid_box;


typedef struct s_position{
	t_grid_box	x;
	t_grid_box	y;
}	t_position;

#endif
