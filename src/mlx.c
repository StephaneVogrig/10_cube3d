/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:30:55 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/25 17:35:03 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	mlx_setup(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (FAIL);
	data->cub.win = mlx_new_window(data->mlx, CUB_W, CUB_H, "cub3d");
	if (data->cub.win == NULL)
		return (FAIL);
	if (screen_init(&data->cub, data->mlx, CUB_W, CUB_H) == FAIL)
		return (FAIL);
	data->minimap.win = mlx_new_window(data->mlx, MINIMAP_W, MINIMAP_H,
			"minimap");
	if (data->minimap.win == NULL)
		return (FAIL);
	if (screen_init(&data->minimap, data->mlx, MINIMAP_W, MINIMAP_H) == FAIL)
		return (FAIL);
	return (chk_box(SUCCESS, EQ, SUCCESS, MLX_SETUP));
}
