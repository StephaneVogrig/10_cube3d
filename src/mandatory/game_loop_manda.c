/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_manda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:05:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/31 15:04:28 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "game_loop_manda.h"

static int	check_move(t_key key, t_time_us delta_time, t_player *player)
{
	t_vec2i	move_dirvec;
	double	move_len;

	move_dirvec = key_to_move(key);
	if (!is_moving(move_dirvec))
		return (FALSE);
	move_len = (SPEED_MOVE * delta_time) / USECOND_PER_SECOND;
	player_move(player, move_dirvec, move_len);
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
	render_needed |= check_move(data->key, delta_time, &data->player);
	if (!render_needed)
		return (SUCCESS);
	render(data);
	fps_print(gametime() - oldtime);
	return (SUCCESS);
}
