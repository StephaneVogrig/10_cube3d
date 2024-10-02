/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:15:02 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/28 17:33:22 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	minimap_setup(void *mlx, t_minimap *minimap, t_map *map)
{
	(void)mlx;
	minimap->screen.win = mlx_new_window(mlx, MINIMAP_W, MINIMAP_H, "minimap");
	if (minimap->screen.win == NULL)
		return (ERROR);
	if (screen_init(&minimap->screen, mlx, MINIMAP_W, MINIMAP_H) == ERROR)
		return (ERROR);
	minimap->scale = minimap_scale(map, minimap);
	return (SUCCESS);
}
