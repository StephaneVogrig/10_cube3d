/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:02:35 by aska              #+#    #+#             */
/*   Updated: 2024/12/23 04:44:26 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SPRITE_BONUS_H
# define SPRITE_BONUS_H

# include "texture.h"
# include "sprite_lst_bonus.h"
# include "asset_bonus.h"
# include "position.h"
# include "player.h"
# include "ray.h"
# include "window.h"
# include "color.h"
# include "gametime.h"

/*
	square of distance between player and sprite for collect sprite
	for example 0.25 for a distance of 0.5
	the square is used instead of distance for simplified calculations
*/
# define DISTANCE_COLLECT 0.1

typedef struct s_sprite
{
	t_texture	**image;
	int			*nbr_state;
	float		*state;
	t_vec2d		*pos;
	t_vec2d		*transform;
	int			*order;
	int			*collected;
	int			nbr;
}				t_sprite;

typedef struct s_sprite_draw
{
	t_texture	*img;
	t_vec2i		screen_start;
	t_vec2i		screen_end;
	t_vec2d		img_start;
	t_vec2d		img_delta;
	t_vec2i		sprite_screen_size;
	double		distance;
}	t_sprite_draw;

/* sprite_bonus.c */

int		sprite_setup(t_sprite *sprite, t_sprite_lst *sprite_lst, t_asset *textures);
void	sprite_destroy(t_sprite *sprite);
void	sprite_render(t_sprite *sprite, t_player *player, t_ray *ray_tab, t_window *win);

/* sprite_draw_bonus.c */

void	sprite_draw(t_sprite *sprite, int i, t_window *win, t_ray *ray_tab);

/* sprite_transform_bonus.c */

void	sprite_transform_coordonate(t_sprite *sprite, t_player *player);

/* sprite_update_bonus.c*/

int		sprite_update(t_sprite *sprite, t_time_us dt);

/* sprite_collect_bonus.c*/

void	sprite_collect(t_sprite *sprite, t_player *player);

/* sprite_draw_compute_bonus.c*/

void	screen_end_compute(t_sprite_draw *draw, t_window *win);
void	img_start_compute(t_sprite_draw *stripe, int sprite_state, int sprite_size);
void	screen_start_compute(t_sprite_draw *draw, double screen_x, t_window *win);
void	sprite_screen_size_compute(t_sprite_draw *draw, t_window *win);
void	img_delta_compute(t_sprite_draw *draw, int sprite_size);

#endif
