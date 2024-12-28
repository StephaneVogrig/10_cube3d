/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_event_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:07:56 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/28 14:08:38 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minimap_event_bonus.h"

void minimap_event_setup(t_minimap *minimap, t_data *data)
{
	mlx_on_event(minimap->mlx, minimap->win, MLX_MOUSEDOWN, on_mousedown, data);
	mlx_on_event(minimap->mlx, minimap->win, MLX_KEYDOWN, on_keydown, data);
	mlx_on_event(minimap->mlx, minimap->win, MLX_KEYUP, on_keyup, data);
}
