/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:13 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/17 21:08:29 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else if (event == 4)
		data->cub.overfly = 1;
	else if (event == 6)
		data->cub.overfly = 0;
	else if (event == 5)
		data->cub.focused = 1;
	else if (event == 7)
		data->cub.focused = 0;
	// printf("on_cub3d_win event: %i overfly: %i focused: %i\n", event, data->cub.overfly, data->cub.focused);
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
	printf("key pressed: %i\n", key);
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

void	mouse_mode_switch(void *mlx, t_screen *screen, int *mouse_mode)
{
	*mouse_mode = *mouse_mode == 0;
	if (*mouse_mode == 1)
	{
		mlx_mouse_move(mlx, screen->win, screen->width / 2, screen->height / 2);
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
	else if (key == KEY_T && data->cub.focused)
		mouse_mode_switch(data->mlx, &data->cub, &data->mouse_mode);
	return (SUCCESS);
}

int	on_loop(void *param)
{
	t_data *data;
	clock_t	begin;
	clock_t	delay;
	int x;
	int y;
	
	data = (t_data *)param;
	if (data->cub.focused && data->cub.overfly && data->mouse_mode)
	{
		mlx_mouse_get_pos(data->mlx, &x, &y);
		int dx = x - data->cub.width / 2;
		if (dx)
		{
			data->player.dir += M_PI * dx / data->cub.width;
			printf("mouse x:%i, y:%i\n", x, y);
			render(data);
			mlx_mouse_move(data->mlx, data->cub.win, data->cub.width / 2, data->cub.height / 2);
		}
	}
	if (data->key.down)
	{
		begin = clock();
		player_move(data->map , &data->player, data->key);
		render(data);
		delay = (clock() - begin);
		if (delay == 0)
			printf("fps: infini\n");
		else
			printf("time: %ld fps: %ld\n", delay, CLOCKS_PER_SEC / delay);
	}
	return (SUCCESS);
}

int on_mousedown(int button, void *param)
{
	(void)button;
	(void)param;
	t_data *data;

	data = (t_data *)param;
	return(SUCCESS);
}

int on_mouseup(int button, void *param)
{
	(void)button;
	(void)param;
	t_data *data;

	data = (t_data *)param;
	data->key.left = UP;
	return(SUCCESS);
}

void	event_setup(t_data *data)
{
	printf("event_setup\n");
    mlx_on_event(data->mlx, data->cub.win, MLX_WINDOW_EVENT, on_win_event, data);
    mlx_on_event(data->mlx, data->cub.win, MLX_KEYDOWN, on_keydown, data);
    mlx_on_event(data->mlx, data->cub.win, MLX_KEYUP, on_keyup, data);
    mlx_on_event(data->mlx, data->minimap.screen.win, MLX_WINDOW_EVENT, window_hook, data->mlx);
    mlx_on_event(data->mlx, data->minimap.screen.win, MLX_KEYDOWN, on_keydown, data);
    mlx_on_event(data->mlx, data->minimap.screen.win, MLX_KEYUP, on_keyup, data);
    mlx_on_event(data->mlx, data->cub.win, MLX_MOUSEDOWN, on_mousedown, data);
    mlx_on_event(data->mlx, data->cub.win, MLX_MOUSEUP, on_mouseup, data);
	mlx_loop_hook(data->mlx, on_loop, data);
    // mlx_on_event(data->mlx, data->win_cub3d, MLX_MOUSEDOWN, mouse_hook, NULL);
}
