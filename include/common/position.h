/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:38:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/04 04:25:05 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef POSITION_H
# define POSITION_H

# include "gridbox.h"

typedef struct s_position{
	t_gridbox	x;
	t_gridbox	y;
}	t_position;

#endif
