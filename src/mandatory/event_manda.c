/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:13 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/16 18:38:03 by svogrig          ###   ########.fr       */
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
		data->key.esc = DOWN;
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

int	on_loop(void *param)
{
	static	t_time_us	oldtime;
	t_time_us	delta_time;
	t_data *data;
	t_vec2i move;
	int render_needed;

	delta_time = gametime() - oldtime;
	oldtime += delta_time;
	chrono(START);
	data = (t_data *)param;
	if (data->key.esc == DOWN)
		mlx_loop_end(data->mlx);
	render_needed = FALSE;
	if (data->key.down)
	{
		int	sign_rot = data->key.right - data->key.left;
		if (sign_rot != 0)
		{
			double rotation = (SPEED_ROT * delta_time) / 10000;
			if (sign_rot < 0)
				rotation = -rotation;
			player_rotation(&data->player, rotation);
			render_needed = TRUE;
		}
		move.x = data->key.w - data->key.s;
		move.y = data->key.d - data->key.a;
		if (move.x != 0 || move.y != 0)
		{
			player_move(&data->player, move, delta_time);
			render_needed = TRUE;
		}
	}
	if (render_needed)
		render(data);
	return (SUCCESS);
}

void	event_setup(t_data *data)
{
	mlx_on_event(data->mlx, data->win.win, MLX_WINDOW_EVENT, on_win_event, &data->win);
	mlx_on_event(data->mlx, data->win.win, MLX_KEYDOWN, on_keydown, data);
	mlx_on_event(data->mlx, data->win.win, MLX_KEYUP, on_keyup, data);
	mlx_loop_hook(data->mlx, on_loop, data);
}
