/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:27:56 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/31 02:30:08 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_move.h"

void	player_move(t_map map, t_player *player, t_vec2i vec_dir)
{
	t_position	new;

	new = player_new_position(player, vec_dir);
	if (map.grid[player->grid.y][new.grid.x] == AREA)
	{
		player->box.x = new.box.x;
		player->grid.x = new.grid.x;
	}
	if (map.grid[new.grid.y][player->grid.x] == AREA)
	{
		player->box.y = new.box.y;
		player->grid.y = new.grid.y;
	}
}
