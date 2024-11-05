/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:15:02 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/05 18:05:11 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minimap_bonus.h"

int	minimap_scale(t_map *map, t_minimap *minimap)
{
	t_vec2i	scale;

	scale.x = minimap->screen.width / map->width;
	scale.y = minimap->screen.height / map->height;
	if (scale.y < scale.x)
		return (scale.y);
	return (scale.x);
}

int window_hook(int event, void* mlx)
{
	if(event == 0)
		mlx_loop_end(mlx);
	return (SUCCESS);
}

int	minimap_setup(void *mlx, t_minimap *minimap, t_map *map)
{
	(void)mlx;
	minimap->screen.win = mlx_new_window(mlx, MINIMAP_W, MINIMAP_H, "minimap");
	if (minimap->screen.win == NULL)
		return (ft_return(ERROR, FAIL, "Error minimap setup"));
	if (screen_init(&minimap->screen, mlx, MINIMAP_W, MINIMAP_H) == ERROR)
		return (FAIL);
	minimap->scale = minimap_scale(map, minimap);
    mlx_on_event(mlx, minimap->screen.win, MLX_WINDOW_EVENT, window_hook, mlx);
	return (chk_box(SUCCESS, EQ, SUCCESS, "Minimap initialization"));
}
