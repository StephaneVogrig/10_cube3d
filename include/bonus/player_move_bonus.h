/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:31:31 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/01 17:37:24 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PLAYER_MOVE_H
# define PLAYER_MOVE_H

# include "player.h"
# include "position.h"
# include "gametime.h"
# include "map.h"

# define DIST_BEFORE_COLLIDE 0.01

void	player_move(t_map *map, t_player *player, t_vec2i move, t_gtime delta_time);

#endif