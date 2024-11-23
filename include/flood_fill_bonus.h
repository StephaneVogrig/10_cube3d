/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:21:52 by aska              #+#    #+#             */
/*   Updated: 2024/11/23 19:14:25 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FLOOD_FILL_BONUS_H
# define FLOOD_FILL_BONUS_H

# include "lstmap_extraction_utils_bonus.h"
# include "map_bonus.h"
# include "player.h"
# include "stack.h"

int		map_checker(t_map *map, t_player *player);
t_bool	chk_flood_fill(t_map *map, int x, int y);

#endif