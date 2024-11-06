/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:13:53 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/06 08:08:27 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "minimap_bonus.h"
# include "dda.h"
# include "window.h"
# include "texture.h"

typedef struct s_draw_texture
{
	t_texture	*mlx_img;
	t_vec2i		pixel;
	int			dy;
	int			y;
	int			dark;
}	t_draw_texture;

typedef struct s_draw_loop
{
	int	start;
	int	end;
}	t_draw_loop;

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
void	render_draw_wall(t_window *win, t_map *map, t_ray *rays);
int	texture_get_color(t_texture *t, int x, int y, int dark);
int color_darkened(int color, int dark);

#endif
