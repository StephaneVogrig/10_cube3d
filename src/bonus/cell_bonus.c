/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:23:40 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/30 20:27:42 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cell_bonus.h"

inline int	cell_is_wall(char cell)
{
	if (cell > '0' && cell <= '9')
		return (TRUE);
	return (FALSE);
}

inline int	cell_is_wall_or_door(char cell)
{
	if (cell_is_wall(cell) || cell_is_door(cell))
		return (TRUE);
	return (FALSE);
}
