/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:15:02 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/15 22:00:14 by svogrig          ###   ########.fr       */
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

void	minimap_setup(t_minimap *minimap, t_map *map)
{
	minimap->scale = minimap_scale(map, minimap);
}
