/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:13:53 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/06 20:18:00 by svogrig          ###   ########.fr       */
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
	double		texture_dy;
	double		texture_y;
	t_vec2i		pix;
	int			x;
	int			y_start;
	int			y_end;
	int			dark;
}	t_draw;

void	raycasting(t_window *cub, t_map *map, t_player *player, t_ray *rays);
int		color_darkened(int color, int dark);

#endif
