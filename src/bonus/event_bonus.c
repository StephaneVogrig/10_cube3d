/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:13 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/19 17:11:09 by svogrig          ###   ########.fr       */
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
	else if (key == KEY_T && data->win.focused)
		mouse_mode_switch(data->mlx, &data->win, &data->mouse_mode);
	return (SUCCESS);
}

int	event_check_move(t_player *player, t_key key, t_time_us dt, t_data *data)
{
	t_vec2i	move;

	move.x = key.w - key.s;
	move.y = key.d - key.a;
	if (move.x != 0 || move.y != 0)
	{
		player_move(&data->map , player, move, dt, data->door_open_list);
		return (TRUE);
	}
	return (FALSE);
}

int	on_loop(void *param)
{
	static	t_time_us	oldtime;
	t_time_us	delta_time;
	t_data *data;
	int x;
	int y;
	int render_needed;

	delta_time = gametime() - oldtime;
	oldtime += delta_time;

	data = (t_data *)param;

	render_needed = door_open_list_update(data->door_open_list, delta_time);

	if (data->win.focused && data->mouse_mode)
	{
		mlx_mouse_get_pos(data->mlx, &x, &y);
		int dx = x - data->win.width / 2;
		if (dx)
		{
			data->player.dir += M_PI * dx / data->win.width;
			// printf("mouse x:%i, y:%i\n", x, y);
			render_needed = TRUE;
			mlx_mouse_move(data->mlx, data->win.win, data->win.width / 2, data->win.height / 2);
		}
	}
	if (data->key.down)
	{
		render_needed |= player_rotate(&data->player, data->key, delta_time);
		render_needed |= event_check_move(&data->player, data->key, delta_time, data);
	}
	if (!render_needed)
		return (SUCCESS);
	render(data);
	fps_print(gametime() - oldtime);
	return (SUCCESS);
}

int on_mousedown(int button, void *param)
{
	t_data *data;
	t_ray	ray;

	(void)button;
	data = (t_data *)param;

	ray.vdir = dir_to_dirvec(data->player.dir);
	dda(&ray, &data->map, &data->player.position, data->door_open_list);
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
	mlx_loop_hook(data->mlx, on_loop, data);
}
