/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:13 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/19 16:44:19 by svogrig          ###   ########.fr       */
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
	else if (key == KEY_W)
		data->key.w = DOWN;
	else if (key == KEY_A)
		data->key.a = DOWN;
	else if (key == KEY_S)
		data->key.s = DOWN;
	else if (key == KEY_D)
		data->key.d = DOWN;
	else if (key == KEY_LEFT)
		data->key.left = DOWN;
	else if (key == KEY_RIGHT)
		data->key.right = DOWN;
	return (SUCCESS);
}

int	on_keyup(int key, void *param)
{
	t_data *data;
	
	data = (t_data *)param;
	if (key == KEY_W)
		data->key.w = UP;
	else if (key == KEY_A)
		data->key.a = UP;
	else if (key == KEY_S)
		data->key.s = UP;
	else if (key == KEY_D)
		data->key.d = UP;
	else if (key == KEY_LEFT)
		data->key.left = UP;
	else if (key == KEY_RIGHT)
		data->key.right = UP;
	return (SUCCESS);
}

int	event_check_move(t_player *player, t_key key, t_time_us delta_time)
{
	t_vec2i	move;

	move.x = key.w - key.s;
	move.y = key.d - key.a;
	if (move.x != 0 || move.y != 0)
	{
		player_move(player, move, delta_time);
		return (TRUE);
	}
	return (FALSE);
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
