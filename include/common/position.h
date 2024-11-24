/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:38:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 16:48:29 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef POSITION_H
# define POSITION_H

# include "fixedpoint.h"

typedef struct s_position{
	t_fixedpoint	x;
	t_fixedpoint	y;
}	t_position;

#endif
