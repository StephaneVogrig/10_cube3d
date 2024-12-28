/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_event_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:07:56 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/28 16:03:42 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minimap_event_bonus.h"

static int	minimap_hook(int event, void *mlx)
{
	if (event == 0)
		mlx_loop_end(mlx);
	return (SUCCESS);
}

void	minimap_event_setup(t_minimap *minimap, t_data *data)
{
	void	*mlx;

	mlx = minimap->mlx;
	mlx_on_event(mlx, minimap->win, MLX_MOUSEDOWN, on_mousedown, data);
	mlx_on_event(mlx, minimap->win, MLX_KEYDOWN, on_keydown, data);
	mlx_on_event(mlx, minimap->win, MLX_KEYUP, on_keyup, data);
	mlx_on_event(mlx, minimap->win, MLX_WINDOW_EVENT, minimap_hook, mlx);
}
