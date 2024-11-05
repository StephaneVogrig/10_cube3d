/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:14:09 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/05 18:04:58 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include "vec2i.h"
# include "map.h"
# include "screen.h"
# include "player.h"
# include "draw_line.h"

# define MINIMAP_W 320
# define MINIMAP_H 180

typedef struct s_minimap{
    t_screen	screen;
	int			scale;
}   t_minimap;

int		minimap_scale(t_map *map, t_minimap *minimap);
int		minimap_setup(void *mlx, t_minimap *minimap, t_map *map);

#endif
