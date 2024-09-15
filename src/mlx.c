/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:30:55 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/15 22:25:25 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	mlx_setup(t_data *data)
{
	printf("mlx_setup\n");

	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ERROR);

	// data->cub.win = mlx_new_window(data->mlx, CUB_W, CUB_H, "cub3d");
	// if (data->cub.win == NULL)
	// 	return (ERROR);
	// if (screen_init(&data->cub, data->mlx, CUB_W, CUB_H) == ERROR)
	// 	return (ERROR);
		
	data->minimap.screen.win = mlx_new_window(data->mlx, MINIMAP_W, MINIMAP_H, "minimap");
	if (data->minimap.screen.win == NULL)
		return (ERROR);
	if (screen_init(&data->minimap.screen, data->mlx, MINIMAP_W, MINIMAP_H) == ERROR)
		return (ERROR);

	return (SUCCESS);	
}
