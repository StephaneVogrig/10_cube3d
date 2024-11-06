/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:16:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/06 12:00:46 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "render.h"

void	render(t_data *data)
{
	t_ray ray[WIN_W];

	raycasting(&data->win, &data->minimap, &data->map, &data->player, &ray[0]);
	fps_print(chrono(STOP));
}
