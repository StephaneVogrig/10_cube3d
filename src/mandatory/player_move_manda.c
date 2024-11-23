/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_manda.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:30:17 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/23 19:43:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "player_move_manda.h"

void	player_move(t_map map, t_player *player, t_vec2d move)
{
	player->position = new_position(player->position, player->dir, move);
	(void)map;
}
