/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:07:10 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/31 15:04:28 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "player.h"

t_vec2d	dir_to_dirvec(double dir)
{
	t_vec2d	vec;

	vec.x = cos(dir);
	vec.y = sin(dir);
	return (vec);
}

/*
	Compute the director vector of the player movement.
	move_input.x : 1 = forward, -1 = backward, 0 = no move forward/backward
	move_input.y : 1 = right, -1 = left, 0 = no move right/left
*/
t_vec2d	player_dir_move_vec(t_player *player, t_vec2i move_input)
{
	t_vec2d	dirvec;
	t_vec2d	compose_move;

	dirvec = dir_to_dirvec(player->dir);
	compose_move.x = dirvec.x * move_input.x - dirvec.y * move_input.y;
	compose_move.y = dirvec.y * move_input.x +  dirvec.x * move_input.y;
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

int	player_rotate(t_player *player, t_key key, t_time_us delta_time)
{
	double	rotation;
	int		sign_rot;

	sign_rot = key.right - key.left;
	if (sign_rot == 0)
		return (FALSE);
	rotation = (SPEED_ROT * delta_time) / 10000;
	if (sign_rot < 0)
		rotation = -rotation;
	player_rotation(player, rotation);
	return (TRUE);
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
