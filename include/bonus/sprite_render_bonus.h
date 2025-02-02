/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_render_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:03:53 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/02 14:05:42 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_RENDER_BONUS_H
# define SPRITE_RENDER_BONUS_H

# include "data_bonus.h"
# include "fog_bonus.h"
# include "sprite_bonus.h"
# include "strip_bonus.h"

void	sprite_render(t_sprite *sprite, t_player *player, t_data *data);

/* sprite_draw_bonus.c */

void	sprite_draw(t_sprite *sprite, int i, t_data *data);

#endif
