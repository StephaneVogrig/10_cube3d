/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:30:04 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/21 11:58:09 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

void	render(t_data *data)
{
	window_clear(&data->win);
	data->dark = map_get_cell(&data->map, &data->player.position) == WALL;
	raycasting(data->rays.tab, data);
	draw_floor_ceil(data);
	draw_walls(&data->win, data->rays.tab, data);
	sprite_render(&data->sprite, &data->player, &data->win, data);
	render_interface(&data->minimap, data);
}
