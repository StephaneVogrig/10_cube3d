/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:13:53 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/03 13:50:10 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "minimap_bonus.h"
# include "dda.h"
# include "window.h"
# include "texture.h"

typedef	struct s_draw{
	t_texture	*texture;
	t_vec2i 	texture_pixel;
	t_vec2i		pix;
	int			y_max;
}	t_draw;

void	raycasting(t_window *cub, t_minimap *minimap, t_map *map, t_player *player);

#endif
