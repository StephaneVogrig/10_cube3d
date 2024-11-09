/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:13:53 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/07 23:51:04 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "minimap_bonus.h"
# include "dda.h"
# include "window.h"
# include "texture.h"

typedef	struct s_draw
{
	t_texture	*texture;
	t_vec2i 	texture_pixel;
	t_vec2i		pix;
	int			y_max;
	int			dark;
}	t_draw;

void	raycasting(t_window *cub, t_map *map, t_player *player, t_ray *rays);
int		color_darkened(int color, int dark);
int		texture_get_color(t_texture *t, int x, int y, int dark);

#endif
