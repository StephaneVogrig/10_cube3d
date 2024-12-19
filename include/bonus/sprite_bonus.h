/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:02:35 by aska              #+#    #+#             */
/*   Updated: 2024/12/19 18:34:07 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_BONUS_H
# define SPRITE_BONUS_H

# include "texture.h"
# include "sprite_lst_bonus.h"
# include "asset_bonus.h"
# include "position.h"
# include "player.h"
# include "ray.h"
# include "window.h"

typedef struct s_sprite
{
	t_texture	**image;
	t_vec2d		*pos;
	t_vec2d		*transform;
	int			*order;
	int			nbr;
}				t_sprite;

int		sprite_setup(t_sprite *sprite, t_sprite_lst *sprite_lst, t_asset *textures);
void	sprite_destroy(t_sprite *sprite);
void	sprite_render(t_sprite *sprite, t_player *player, t_ray *ray_tab, t_window *win);

#endif