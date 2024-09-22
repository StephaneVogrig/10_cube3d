/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:07:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/22 19:03:57 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "player.h"

void	collide_border_map(double *pos, int *grid, int limit)
{
	if (*pos >= 0.95 && *grid == limit - 1)
		*pos = 0.95;
	else if (*pos >= 1)
	{
			*grid += 1;
			*pos -= 1;
	}
	if (*pos <= 0.05 && *grid == 0)
			*pos = 0.05;
	else if (*pos < 0)
	{
		*grid -= 1;
		*pos += 1;
	}
}

void	player_move(t_map map, t_player *player, t_vec2i dir, int rot)
{
	double cos_dir;
	double sin_dir;

	player->dir += rot * SPEED_ROT;
	if(player->dir > M_PI)
		player->dir = player->dir - 2 * M_PI;
	if(player->dir < -M_PI)
		player->dir = player->dir + 2 * M_PI;

		
	cos_dir = cos(player->dir);
	sin_dir = sin(player->dir);

	t_vec2i	new_grid;
	t_vec2d	new_box;
	
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
	if (map.grid[player->grid.y][new_grid.x] == '0')
	{
		player->box.x = new_box.x;
		player->grid.x = new_grid.x;
	}
	if (map.grid[new_grid.y][player->grid.x] == '0')
	{
		player->box.y = new_box.y;
		player->grid.y = new_grid.y;
	}
	// printf("grid x: %i y: %i box x: %f y: %f\n", player->grid.x, player->grid.y, player->box.x, player->box.y);
	// collide_border_map(&player->box.x, &player->grid.x, map.width);
	// collide_border_map(&player->box.y, &player->grid.y, map.height);
}

void	player_set_dir(t_player *player, char dir)
{
	if (dir == 'N')
		player->dir = -M_PI_2;
	else if (dir == 'S')
		player->dir = M_PI_2;
	else if (dir == 'W')
		player->dir = M_PI;
	else if (dir == 'E')
		player->dir = 0;
}
