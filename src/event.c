/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:13 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/22 18:48:28 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "event.h"

int	mouse_hook(int button, void *param)
{
	(void)button;
	(void)param;
	
	return (SUCCESS);
}

/*
	event code :
	0 = on demand close
	1 = on move window
	4 = on flyover start
	6 = on flyover end
	5 = on focus gain
	7 = on focus loss
*/
int	on_win_event(int event, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (event == 0)
		mlx_loop_end(data->mlx);
	else if (event == 5)
		data->win.focused = 1;
	else if (event == 7)
		data->win.focused = 0;
	// printf("on_cub3d_win event: %i overfly: %i focused: %i\n", event, data->win.overfly, data->win.focused);
	return (SUCCESS);
}

int window_hook(int event, void* mlx)
{
	if(event == 0)
		mlx_loop_end(mlx);
	return (SUCCESS);
}

int	on_keydown(int key, void *param)
{
	// printf("key pressed: %i\n", key);
	t_data *data;
	
	data = (t_data *)param;
	if (key == KEY_W)
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
	if (key == KEY_ESC)
		mlx_loop_end(data->mlx);
	else if (key == KEY_W)
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

int	on_loop(void *param)
{
	t_data *data;
	t_vec2i move;
	int	rot;
	int x;
	int y;
	int render_needed;
	
	chrono(START);
	data = (t_data *)param;
	render_needed = FALSE;
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
		move.x = data->key.w - data->key.s;
		move.y = data->key.d - data->key.a;
		rot = data->key.right - data->key.left;
		player_move(data->map , &data->player, move, rot);
		render_needed = TRUE;
	}
	if (render_needed)
		render(data);
	return (SUCCESS);
}

int on_mousedown(int button, void *param)
{
	(void)button;
	(void)param;
	t_data *data;

	data = (t_data *)param;
	(void)data;
	return(SUCCESS);
}

int on_mouseup(int button, void *param)
{
	(void)button;
	(void)param;
	t_data *data;

	data = (t_data *)param;
	(void)data;
	return(SUCCESS);
}

void	event_setup(t_data *data)
{
	printf("event_setup\n");
    mlx_on_event(data->mlx, data->win.win, MLX_WINDOW_EVENT, on_win_event, data);
    mlx_on_event(data->mlx, data->win.win, MLX_KEYDOWN, on_keydown, data);
    mlx_on_event(data->mlx, data->win.win, MLX_KEYUP, on_keyup, data);
    mlx_on_event(data->mlx, data->minimap.screen.win, MLX_WINDOW_EVENT, window_hook, data->mlx);
    mlx_on_event(data->mlx, data->minimap.screen.win, MLX_KEYDOWN, on_keydown, data);
    mlx_on_event(data->mlx, data->minimap.screen.win, MLX_KEYUP, on_keyup, data);
    mlx_on_event(data->mlx, data->win.win, MLX_MOUSEDOWN, on_mousedown, data);
    mlx_on_event(data->mlx, data->win.win, MLX_MOUSEUP, on_mouseup, data);
	mlx_loop_hook(data->mlx, on_loop, data);
}
