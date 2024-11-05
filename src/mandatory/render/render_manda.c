/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:16:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/05 13:41:29 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "render.h"

void	render(t_data *data)
{
	t_ray	rays[data->win.width];

	ft_bzero(rays, sizeof(rays));
	raycasting(&data->win, &data->map, &data->player, &rays[0]);
	fps_print(chrono(STOP));
}
