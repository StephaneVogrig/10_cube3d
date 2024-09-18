/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:14:09 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/18 05:16:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

#include "vec2i.h"
#include "map.h"
#include "screen.h"

# define MINIMAP_W 400
# define MINIMAP_H 225

typedef struct s_minimap{
    t_screen	screen;
	int			scale;
}   t_minimap;

int	minimap_scale(t_map *map, t_minimap *minimap);
int	minimap_setup(t_minimap *minimap, t_map *map);

#endif