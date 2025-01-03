/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:22:48 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/01 15:24:07 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CELL_BONUS_H
# define CELL_BONUS_H

# include "libft.h"
# include "map.h"
# include "position.h"

int	cell_is_wall(char *cell);
int	cell_is_wall_or_door(char *cell);
int	cell_is_door(char *cell);
char *map_get_cell_ptr(t_map *map, t_position *p);

#endif