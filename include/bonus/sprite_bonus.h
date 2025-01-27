/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:02:35 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 16:04:24 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_BONUS_H
# define SPRITE_BONUS_H

# include "asset_bonus.h"
# include "color.h"
# include "gametime.h"
# include "player.h"
# include "position.h"
# include "ray.h"
# include "sprite_lst_bonus.h"
# include "strip_bonus.h"
# include "texture.h"
# include "window.h"

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

/* sprite_bonus.c */

int				sprite_setup(t_sprite *sprite, t_sprite_lst *sprite_lst,
					t_asset *textures);
void			sprite_destroy(t_sprite *sprite);
int				sprite_update(t_sprite *sprite, t_time_us dt);

/* sprite_collect_bonus.c*/

void			sprite_collect(t_sprite *sprite, t_player *player);

#endif
