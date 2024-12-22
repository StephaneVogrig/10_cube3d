/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:02:35 by aska              #+#    #+#             */
/*   Updated: 2024/12/22 02:07:17 by svogrig          ###   ########.fr       */
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

typedef struct s_sprite
{
	t_texture	**image;
	int			*nbr_state;
	float		*state;
	t_vec2d		*pos;
	t_vec2d		*transform;
	int			*order;
	int			nbr;
}				t_sprite;

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

#endif