/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:14:09 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/01 00:01:54 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

#include "vec2i.h"
#include "map.h"
#include "screen.h"

# define MINIMAP_W 1024
# define MINIMAP_H 512

typedef struct s_minimap{
    t_screen	screen;
	int			scale;
}   t_minimap;

int	minimap_scale(t_map *map, t_minimap *minimap);
int	minimap_setup(void *mlx, t_minimap *minimap, t_map *map);

#endif