/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_manda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:05:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/23 20:09:37 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "game_loop_manda.h"

int	event_check_move(t_player *player, t_key key, t_time_us delta_time)
{
	t_vec2i	move;

	move = key_to_move(key);
	if (!is_moving(move))
		return (FALSE);
	player_move(player, move, delta_time);
	return (TRUE);
}

int	game_loop(void *param)
{
	static	t_time_us	oldtime;
	t_time_us			delta_time;
	t_data				*data;
	int					render_needed;

	delta_time = gametime() - oldtime;
	oldtime += delta_time;
	data = (t_data *)param;
	if (data->key.down == 0)
		return (SUCCESS);
	render_needed = player_rotate(&data->player, data->key, delta_time);
	render_needed |= event_check_move(&data->player, data->key, delta_time);
	if (!render_needed)
		return (SUCCESS);
	render(data);
	fps_print(gametime() - oldtime);
	return (SUCCESS);
}
