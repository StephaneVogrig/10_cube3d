/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_manda.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:31:31 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/26 10:11:56 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PLAYER_MOVE_MANDA_H
# define PLAYER_MOVE_MANDA_H

# include "player.h"
# include "vector.h"
# include "gridbox.h"

void	player_move(t_player *player, t_vec2i move, double len_move);

#endif