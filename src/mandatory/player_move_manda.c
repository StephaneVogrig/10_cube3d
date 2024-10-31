/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_manda.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:30:17 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/31 00:52:06 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_move.h"

void	player_move(t_map map, t_player *player, t_vec2i dir)
{
	double	cos_dir;
	double	sin_dir;
	t_vec2i	new_grid;
	t_vec2d	new_box;

	cos_dir = cos(player->dir);
	sin_dir = sin(player->dir);
	new_box.x = player->box.x + (dir.x * cos_dir - dir.y * sin_dir) * SPEED_MOVE;
	if (new_box.x >= 1)
	{
		new_box.x -= 1;
		new_grid.x = player->grid.x + 1;
	}
	else if (new_box.x < 0)
	{
		new_box.x += 1;
		new_grid.x = player->grid.x - 1;
	}
	else
		new_grid.x = player->grid.x;
	new_box.y = player->box.y + (dir.x * sin_dir + dir.y * cos_dir) * SPEED_MOVE;
	if (new_box.y >= 1)
	{
		new_box.y -= 1;
		new_grid.y = player->grid.y + 1;
	}
	else if (new_box.y < 0)
	{
		new_box.y += 1;
		new_grid.y = player->grid.y - 1;
	}
	else
		new_grid.y = player->grid.y;
		
	(void)map;
	player->box.x = new_box.x;
	player->grid.x = new_grid.x;
	player->box.y = new_box.y;
	player->grid.y = new_grid.y;
	
	// if (map.grid[player->grid.y][new_grid.x] == AREA)
	// {
	// 	player->box.x = new_box.x;
	// 	player->grid.x = new_grid.x;
	// }
	// if (map.grid[new_grid.y][player->grid.x] == AREA)
	// {
	// 	player->box.y = new_box.y;
	// 	player->grid.y = new_grid.y;
	// }
}
