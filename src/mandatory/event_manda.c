/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:13 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 15:58:47 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_manda.h"

int	on_win_event(int event, void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (event == ON_DEMAND_CLOSE)
		mlx_loop_end(window->mlx);
	return (SUCCESS);
}

int	on_keydown(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == KEY_ESC)
		mlx_loop_end(data->mlx);
	else
		set_key_down(&data->key, key);
	return (SUCCESS);
}

int	on_keyup(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	set_key_up(&data->key, key);
	return (SUCCESS);
}

void	event_setup(t_data *data)
{
	mlx_on_event(data->mlx, data->win.win, MLX_WINDOW_EVENT, on_win_event,
		&data->win);
	mlx_on_event(data->mlx, data->win.win, MLX_KEYDOWN, on_keydown, data);
	mlx_on_event(data->mlx, data->win.win, MLX_KEYUP, on_keyup, data);
	mlx_loop_hook(data->mlx, game_loop, data);
}
