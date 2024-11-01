/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:27:56 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/01 02:06:24 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_move.h"

static inline void	collision_manage(	t_map map,
										t_player *player,
										t_position	new)
{
	if (map.grid[player->y.grid][new.x.grid] == AREA)
	{
		player->x.box = new.x.box;
		player->x.grid = new.x.grid;
	}
	if (map.grid[new.y.grid][player->x.grid] == AREA)
	{
		player->y.box = new.y.box;
		player->y.grid = new.y.grid;
	}
}

void	player_move(t_map map, t_player *player, t_vec2i vec_dir)
{
	t_position	new;

	new = player_new_position(player, vec_dir);
	collision_manage(map, player, new);
}
