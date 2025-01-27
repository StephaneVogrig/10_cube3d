/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_manda.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:31:31 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 16:04:51 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_MOVE_MANDA_H
# define PLAYER_MOVE_MANDA_H

# include "gridbox.h"
# include "player.h"
# include "vector.h"

void	player_move(t_player *player, t_vec2i move, double len_move);

#endif