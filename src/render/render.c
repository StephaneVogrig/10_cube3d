/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:16:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/24 23:39:59 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render(t_data *data)
{
	raycasting(&data->win, &data->minimap, &data->map, &data->player);
	fps_print(chrono(STOP));
}
