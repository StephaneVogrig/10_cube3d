/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:38:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/05 18:31:00 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef POSITION_H
# define POSITION_H

# include "vec2i.h"

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
