/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:14:09 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/16 17:51:02 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include "vec2i.h"
# include "map.h"
# include "player.h"
# include "draw_line_bonus.h"
# include "minimap_utils_bonus.h"

int		minimap_scale(t_map *map, t_minimap *minimap);
int		minimap_setup(void *mlx, t_minimap *minimap, t_map *map);
void	minimap_draw_ray(t_minimap *minimap, t_player *player, double raylen,
																t_vec2d raydir);

#endif
