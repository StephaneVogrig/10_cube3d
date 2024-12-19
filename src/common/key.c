/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:33:26 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/19 18:37:24 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "key_move.h"

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
