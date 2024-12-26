/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:31:31 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/26 10:35:01 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PLAYER_MOVE_BONUS_H
# define PLAYER_MOVE_BONUS_H

# include <math.h>
# include "player.h"
# include "vector.h"
# include "data_bonus.h"
# include "gridbox.h"
// # include "map.h"
# include "dda_bonus.h"
// # include "door_bonus.h"

# define DIST_BEFORE_COLLIDE 0.01

void	player_move(t_player *player, t_vec2i move, double move_len, t_data *data);

#endif