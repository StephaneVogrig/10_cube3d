/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:31:31 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/07 12:53:15 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PLAYER_MOVE_BONUS_H
# define PLAYER_MOVE_BONUS_H

# include "player.h"
# include "position.h"
# include "gametime.h"
# include "map.h"
# include "door_bonus.h"

# define DIST_BEFORE_COLLIDE 0.01

void	player_move(t_map *map, t_player *player, t_vec2i move, t_time_us delta_time, t_door *door_open_list);

#endif