/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_manda.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:30:17 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 15:58:49 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_move_manda.h"

void	player_move(t_player *player, t_vec2i move, double len_move)
{
	t_vec2d	dir_move_vec;

	dir_move_vec = player_dir_move_vec(player, move);
	gridbox_add_double(&player->position.x, dir_move_vec.x * len_move);
	gridbox_add_double(&player->position.y, dir_move_vec.y * len_move);
}
