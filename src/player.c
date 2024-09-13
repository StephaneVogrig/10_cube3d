/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:07:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/13 23:39:49 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_move(t_player *player, t_key key)
{
	double cos_dir;
	double sin_dir;

	cos_dir = cos(player->dir);
	sin_dir = sin(player->dir);
	player->dir += (key.right - key.left) * SPEED_ROT;
	
	player->pos.x += (key.w - key.s) * sin_dir + (key.d - key.a) * cos_dir;
	if (player->pos.x < 0)
		player->pos.x = 0;
	if (player->pos.x > MINIMAP_W)
		player->pos.x = MINIMAP_W;
	
	player->pos.y += (key.s - key.w) * cos_dir + (key.d - key.a) * sin_dir;
	if (player->pos.y < 0)
		player->pos.y = 0;
	if (player->pos.y > MINIMAP_H)
		player->pos.y = MINIMAP_H;
}

void	player_set_dir(t_player *player, char dir)
{
	if (dir == 'N')
		player->dir = 0;
	else if (dir == 'S')
		player->dir = M_PI;
	else if (dir == 'W')
		player->dir = -M_PI_2;
	else if (dir == 'E')
		player->dir = M_PI_2;
}