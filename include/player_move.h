/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:31:31 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/31 00:52:16 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_MOVE_H
# define PLAYER_MOVE_H

#include "player.h"


void	player_move(t_map map, t_player *player, t_vec2i dir);

#endif