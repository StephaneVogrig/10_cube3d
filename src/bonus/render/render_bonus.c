/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:30:04 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/02 11:44:33 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

void	render(t_data *data)
{
	window_clear(&data->win);
	raycasting(data->rays.tab, data);
	draw_floor_ceil(data);
	draw_walls(&data->win, data->rays.tab, data);
	sprite_render(&data->sprite, &data->player, data);
	render_interface(&data->minimap, data);
}
