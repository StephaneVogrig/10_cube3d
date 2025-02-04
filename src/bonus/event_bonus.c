/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:13 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/04 16:53:32 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_bonus.h"

static
int	on_win_event(int event, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (event == ON_FOCUS_GAIN)
		data->win_focused = 1;
	else if (event == ON_FOCUS_LOSS)
		data->win_focused = 0;
	return (SUCCESS);
}

int	on_keydown(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == KEY_ESC)
		mlx_loop_end(data->mlx);
	else if (key == KEY_F)
		data->fog_enable = (data->fog_enable == FALSE);
	else if (key == KEY_P)
		data->fps_enable = (data->fps_enable == FALSE);
	else if (key == KEY_C)
		data->collision_enable = (data->collision_enable == FALSE);
	else
		set_key_down(&data->key, key);
	return (SUCCESS);
}

int	on_keyup(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == KEY_T && data->win_focused)
		mouse_mode_switch(&data->win, &data->mouse_mode);
	else
		set_key_up(&data->key, key);
	return (SUCCESS);
}

int	on_mousedown(int button, void *param)
{
	t_data	*data;
	t_ray	ray;

	(void)button;
	data = (t_data *)param;
	ray.dirvec = dir_to_dirvec(data->player.dir);
	raycast(&ray, &data->player.position, data);
	if ((*ray.hit_cell == 'R' || *ray.hit_cell == 'L')
		&& ray.len < DOOR_OPEN_DIST)
		door_open(ray.hit_cell, data->door_open_list);
	return (SUCCESS);
}

void	event_setup(t_data *data)
{
	mlx_on_event(data->mlx, data->win.win, MLX_WINDOW_EVENT, on_win_event,
		data);
	mlx_on_event(data->mlx, data->win.win, MLX_KEYDOWN, on_keydown, data);
	mlx_on_event(data->mlx, data->win.win, MLX_KEYUP, on_keyup, data);
	mlx_on_event(data->mlx, data->win.win, MLX_MOUSEDOWN, on_mousedown, data);
	mlx_loop_hook(data->mlx, game_loop, data);
}
