/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:13 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/19 20:17:32 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "event_manda.h"

int	on_win_event(int event, void *param)
{
	t_window *window;

	window = (t_window *)param;
	if (event == ON_DEMAND_CLOSE)
		mlx_loop_end(window->mlx);
	return (SUCCESS);
}

int	on_keydown(int key, void *param)
{
	t_data *data;
	
	data = (t_data *)param;
	if (key == KEY_ESC)
		mlx_loop_end(data->mlx);
	else
		set_key_down(&data->key, key);
	return (SUCCESS);
}

int	on_keyup(int key, void *param)
{
	t_data *data;
	
	data = (t_data *)param;
	set_key_up(&data->key, key);
	return (SUCCESS);
}

int	event_check_move(t_player *player, t_key key, t_time_us delta_time)
{
	t_vec2i	move;

	move = key_to_move(key);
	if (!is_moving(move))
		return (FALSE);
	player_move(player, move, delta_time);
	return (TRUE);
}

int	on_loop(void *param)
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

void	event_setup(t_data *data)
{
	mlx_on_event(data->mlx, data->win.win, MLX_WINDOW_EVENT, on_win_event, &data->win);
	mlx_on_event(data->mlx, data->win.win, MLX_KEYDOWN, on_keydown, data);
	mlx_on_event(data->mlx, data->win.win, MLX_KEYUP, on_keyup, data);
	mlx_loop_hook(data->mlx, on_loop, data);
}
