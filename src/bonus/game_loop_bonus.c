/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:38:20 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/04 16:42:02 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop_bonus.h"

static
bool	check_mouse_move(t_data *data)
{
	int	x;
	int	y;
	int	dx;

	if (!data->win_focused || !data->mouse_mode)
		return (false);
	mlx_mouse_get_pos(data->mlx, &x, &y);
	dx = x - data->win.width / 2;
	if (!dx)
		return (false);
	data->player.dir += M_PI * dx / data->win.width;
	mouse_set_on_center(&data->win);
	return (true);
}

static
bool	check_in_door(t_position *position, char *cell, t_data *data)
{
	t_door	door;
	t_axis	x;
	t_axis	y;

	if (!cell_is_door(cell))
		return (false);
	door_init(&door, cell, data->door_open_list);
	x = door_get_direction(&data->map, *position);
	if (!is_between_doorside(position->axis[x].box, &door))
		return (false);
	y = y_with_x(x);
	if (is_in_closepart(position->axis[y].box, &door))
		return (true);
	if (data->collision_enable)
		door_open(cell, data->door_open_list);
	return (false);
}

static
void	update_data(t_data *data)
{
	char	*cell;

	cell = map_get_cell_ptr(&data->map, &data->player.position);
	data->in_wall = cell_is_wall(cell);
	if (data->in_wall)
		data->in_door = false;
	else
		data->in_door = check_in_door(&data->player.position, cell, data);
	data->dark = data->in_wall | data->in_door;
}

static
bool	check_move(t_key key, t_time_us delta_time, t_data *data)
{
	t_vec2i	move_dirvec;
	double	move_len;

	move_dirvec = key_to_move(key);
	if (!is_moving(move_dirvec))
		return (false);
	move_len = (SPEED_MOVE * delta_time) / USECOND_PER_SECOND;
	player_move(&data->player, move_dirvec, move_len, data);
	return (true);
}

int	game_loop(void *param)
{
	static t_time_us	oldtime;
	t_time_us			delta_time;
	t_data				*data;
	bool				render_needed;

	delta_time = gametime() - oldtime;
	oldtime += delta_time;
	data = (t_data *)param;
	render_needed = check_mouse_move(data);
	if (data->key.down)
	{
		render_needed |= player_rotate(&data->player, data->key, delta_time);
		render_needed |= check_move(data->key, delta_time, data);
	}
	update_data(data);
	render_needed |= door_open_list_update(data->door_open_list, delta_time);
	render_needed |= sprite_update(&data->sprite, delta_time);
	if (!render_needed)
		return (SUCCESS);
	render(data);
	if (data->fps_enable)
		fps_print(gametime() - oldtime);
	return (SUCCESS);
}
