/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:33:26 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/19 20:23:01 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "key_move.h"

void set_key_down(t_key *key, int key_pressed)
{
	if (key_pressed == KEY_W)
		key->w = DOWN;
	else if (key_pressed == KEY_A)
		key->a = DOWN;
	else if (key_pressed == KEY_S)
		key->s = DOWN;
	else if (key_pressed == KEY_D)
		key->d = DOWN;
	else if (key_pressed == KEY_LEFT)
		key->left = DOWN;
	else if (key_pressed == KEY_RIGHT)
		key->right = DOWN;
}

void set_key_up(t_key *key, int key_pressed)
{
	if (key_pressed == KEY_W)
		key->w = UP;
	else if (key_pressed == KEY_A)
		key->a = UP;
	else if (key_pressed == KEY_S)
		key->s = UP;
	else if (key_pressed == KEY_D)
		key->d = UP;
	else if (key_pressed == KEY_LEFT)
		key->left = UP;
	else if (key_pressed == KEY_RIGHT)
		key->right = UP;
}

t_vec2i	key_to_move(t_key key)
{
	t_vec2i	move;

	move.x = key.w - key.s;
	move.y = key.d - key.a;
	return (move);
}

int	is_moving(t_vec2i move)
{
	return (move.x != 0 || move.y != 0);
}
