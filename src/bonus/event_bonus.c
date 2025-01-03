/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:13 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/02 21:45:03 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "event_bonus.h"

int	on_win_event(int event, void *param)
{
	t_window *window;

	window = (t_window *)param;
	if (event == ON_DEMAND_CLOSE)
		mlx_loop_end(window->mlx);
	else if (event == ON_FOCUS_GAIN)
		window->focused = 1;
	else if (event == ON_FOCUS_LOSS)
		window->focused = 0;
	return (SUCCESS);
}

int	on_keydown(int key, void *param)
{
	// printf("key pressed: %i\n", key);
	t_data *data;
	
	data = (t_data *)param;

	if (key == KEY_ESC)
		mlx_loop_end(data->mlx);
	else
		set_key_down(&data->key, key);
	return (SUCCESS);
}

void	mouse_mode_switch(void *mlx, t_window *win, int *mouse_mode)
{
	*mouse_mode = *mouse_mode == 0;
	if (*mouse_mode == 1)
	{
		mlx_mouse_move(mlx, win->win, win->width / 2, win->height / 2);
		mlx_mouse_hide();
	}
	else
		mlx_mouse_show();
}

int	on_keyup(int key, void *param)
{
	t_data *data;
	
	data = (t_data *)param;
	if (key == KEY_T && data->win.focused)
		mouse_mode_switch(data->mlx, &data->win, &data->mouse_mode);
	else
		set_key_up(&data->key, key);
	return (SUCCESS);
}

int on_mousedown(int button, void *param)
{
	t_data *data;
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
	mlx_on_event(data->mlx, data->win.win, MLX_WINDOW_EVENT, on_win_event, &data->win);
	mlx_on_event(data->mlx, data->win.win, MLX_KEYDOWN, on_keydown, data);
	mlx_on_event(data->mlx, data->win.win, MLX_KEYUP, on_keyup, data);
	mlx_on_event(data->mlx, data->win.win, MLX_MOUSEDOWN, on_mousedown, data);
	mlx_loop_hook(data->mlx, game_loop, data);
}
