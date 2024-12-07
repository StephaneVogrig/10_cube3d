/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:07:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/03 15:30:25 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "player.h"

t_vec2d	player_dir_move_vec(t_player *player, t_vec2i move_input)
{
	double	cos_d;
	double	sin_d;
	t_vec2d	compose_move;

	cos_d = cos(player->dir);
	sin_d = sin(player->dir);
	compose_move.x = move_input.x * cos_d - move_input.y * sin_d;
	compose_move.y = move_input.x * sin_d + move_input.y * cos_d;
	return (compose_move);
}

void	player_rotation(t_player *player, double rotation)
{
	player->dir += rotation;
	if (player->dir > M_PI)
		player->dir = player->dir - 2 * M_PI;
	if (player->dir < -M_PI)
		player->dir = player->dir + 2 * M_PI;
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
