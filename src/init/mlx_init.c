/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:49:24 by aska              #+#    #+#             */
/*   Updated: 2024/08/02 17:36:05 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../include/cub3d.h"

int	mlx_initialize(t_cub *cub)
{
	cub->err = 0;
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
		return (FAIL);
	cub->win = ft_calloc(1, sizeof(t_win));
	if (cub->win != NULL)
		return (FAIL);
	cub->win->w_game = mlx_new_window(cub->mlx, cub->win->game_wid,
			cub->win->game_hei, "Cub3D");
	cub->win->w_mini = mlx_new_window(cub->mlx, cub->win->mini_hei,
			cub->win->mini_wid, "MiniMap");
	if (cub->win->w_game == NULL || cub->win->w_mini == NULL)
		return (FAIL);
	return (SUCCESS);
}
