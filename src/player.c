/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:07:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/21 19:39:11 by stephane         ###   ########.fr       */
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

void	player_move(t_map map, t_player *player, t_key key)
{
	double cos_dir;
	double sin_dir;

	player->dir += (key.right - key.left) * SPEED_ROT;
	if(player->dir > M_PI)
		player->dir = player->dir - 2 * M_PI;
	if(player->dir < -M_PI)
		player->dir = player->dir + 2 * M_PI;

		
	cos_dir = cos(player->dir);
	sin_dir = sin(player->dir);

	t_vec2i	new_grid;
	t_vec2d	new_box;
	
	new_box.x = player->box.x + ((key.w - key.s) * cos_dir - (key.d - key.a) * sin_dir) * SPEED_MOVE;
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

	new_box.y = player->box.y + ((key.w - key.s) * sin_dir + (key.d - key.a) * cos_dir) * SPEED_MOVE;
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

t_vec2i	player_get_pos_minimap(t_player *player, t_minimap *minimap)
{
	t_vec2i pos;
	
	pos.x = player->grid.x * minimap->scale + (player->box.x * minimap->scale);
	pos.y = player->grid.y * minimap->scale + (player->box.y * minimap->scale);
	// printf("scale: %i pos x: %i y: %i\n", minimap->scale, pos.x, pos.y);
	// printf("grid x: %i y: %i\n", player->grid.x, player->grid.y);
	return (pos);
}
