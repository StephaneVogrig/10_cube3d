/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_event_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:12:02 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 15:12:04 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface_event_bonus.h"

static int	minimap_hook(int event, void *mlx)
{
	if (event == 0)
		mlx_loop_end(mlx);
	return (SUCCESS);
}

void	interface_event_setup(t_interface *minimap, t_data *data)
{
	void	*mlx;

	mlx = minimap->mlx;
	mlx_on_event(mlx, minimap->win, MLX_MOUSEDOWN, on_mousedown, data);
	mlx_on_event(mlx, minimap->win, MLX_KEYDOWN, on_keydown, data);
	mlx_on_event(mlx, minimap->win, MLX_KEYUP, on_keyup, data);
	mlx_on_event(mlx, minimap->win, MLX_WINDOW_EVENT, minimap_hook, mlx);
}
