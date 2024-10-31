/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_manda.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:30:17 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/31 02:23:53 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_move.h"

void	player_move(t_map map, t_player *player, t_vec2i vec_dir)
{
	player->position = player_new_position(player, vec_dir);
	(void)map;
}
