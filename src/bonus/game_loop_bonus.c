/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:38:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/26 10:25:10 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

# include "game_loop_bonus.h"

static int	check_mouse_move(t_data *data)
{
	int x;
	int y;
	int dx;

	if (!data->win.focused || !data->mouse_mode)
		return (FALSE);
	mlx_mouse_get_pos(data->mlx, &x, &y);
	dx = x - data->win.width / 2;
	if (!dx)
		return (FALSE);
	data->player.dir += M_PI * dx / data->win.width;
	mlx_mouse_move(data->mlx, data->win.win, data->win.width / 2, data->win.height / 2);
	return (TRUE);
}

static int	check_move(t_key key, t_time_us delta_time, t_data *data)
{
	t_vec2i	move_dir_vec;
	double	move_len;

	move_dir_vec = key_to_move(key);
	if (!is_moving(move_dir_vec))
		return (FALSE);
	move_len = (SPEED_MOVE * delta_time) / USECOND_PER_SECOND;
	player_move(&data->player, move_dir_vec, move_len, data);
	return (TRUE);
}

int	game_loop(void *param)
{
	static	t_time_us	oldtime;
	t_time_us			delta_time;
	t_data				*data;
	int					render_needed;

	delta_time = gametime() - oldtime;
	oldtime += delta_time;
	data = (t_data *)param;
	render_needed = door_open_list_update(data->door_open_list, delta_time);
	render_needed |= sprite_update(&data->sprite, delta_time);
	render_needed |= check_mouse_move(data);
	if (data->key.down)
	{
		render_needed |= player_rotate(&data->player, data->key, delta_time);
		render_needed |= check_move(data->key, delta_time, data);
	}
	if (!render_needed)
		return (SUCCESS);
	render(data);
	fps_print(gametime() - oldtime);
	return (SUCCESS);
}
