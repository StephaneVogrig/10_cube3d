/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:30:55 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/18 09:41:56 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	mlx_setup(t_data *data)
{
	printf("mlx_setup\n");

	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ERROR);
	data->cub.win = mlx_new_window(data->mlx, CUB_W, CUB_H, "cub3d");
	if (data->cub.win == NULL)
		return (ERROR);		
    data->cub.mlx = data->mlx;
    data->cub.width = CUB_W;
	data->cub.height = CUB_H;
	return (SUCCESS);	
}
