/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:13:53 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/16 18:41:16 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "minimap_bonus.h"
# include "player.h"
# include "draw_line.h"

typedef struct s_dda{
	t_vec2d	len_unit;
	t_vec2d	len_side;
	t_vec2i step;
}	t_dda;

void	raycasting(t_minimap *minimap, t_map *map, t_player *player);

#endif