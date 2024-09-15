/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:47:13 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/15 22:28:58 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

int	mouse_hook(int button, void *param)
{
	(void)button;
	(void)param;
	
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
	return (SUCCESS);
}

int	on_loop(void *param)
{
	t_data *data;
	clock_t	begin;
	clock_t	delay;
	
	data = (t_data *)param;
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

void	event_setup(t_data *data)
{
	printf("event_setup\n");
    // mlx_on_event(data->mlx, data->cub.win, MLX_WINDOW_EVENT, window_hook, data->mlx);
    // mlx_on_event(data->mlx, data->cub.win, MLX_KEYDOWN, on_keydown, data);
    // mlx_on_event(data->mlx, data->cub.win, MLX_KEYUP, on_keyup, data);
    mlx_on_event(data->mlx, data->minimap.screen.win, MLX_WINDOW_EVENT, window_hook, data->mlx);
    mlx_on_event(data->mlx, data->minimap.screen.win, MLX_KEYDOWN, on_keydown, data);
    mlx_on_event(data->mlx, data->minimap.screen.win, MLX_KEYUP, on_keyup, data);
	mlx_loop_hook(data->mlx, on_loop, data);
    // mlx_on_event(data->mlx, data->win_cub3d, MLX_MOUSEDOWN, mouse_hook, NULL);
}
