/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:08:37 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/23 16:37:41 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef DRAW_WALL_UTILS_H
# define DRAW_WALL_UTILS_H

# include "texture.h"
# include "vector.h"
# include "window.h"
# include "ray.h"
# include "color.h"

typedef struct s_wall_draw
{
	t_texture	*img;
	t_vec2i		screen_start;
	t_vec2i		screen_end;
	t_vec2d		img_start;
	t_vec2d		img_delta;
	t_vec2i		img_screen_size;
	int			dark;
}	t_wall_draw;

int		wall_height(t_window *win, double ray_len);
void	draw_wall(t_window *win, int x, t_wall_draw *draw);

#endif