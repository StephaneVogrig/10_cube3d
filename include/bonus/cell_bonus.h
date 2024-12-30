/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:22:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/30 20:26:45 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CELL_BONUS_H
# define CELL_BONUS_H

# include "libft.h"
# include "door_bonus.h"

int	cell_is_wall(char cell);
int	cell_is_wall_or_door(char cell);

#endif