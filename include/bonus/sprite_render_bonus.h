/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_render_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:03:53 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/27 03:31:38 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SPRITE_RENDER_BONUS_H
# define SPRITE_RENDER_BONUS_H

# include "sprite_bonus.h"
# include "data_bonus.h"

void	sprite_render(t_sprite *sprite, t_player *player, t_window *win,\
						t_data *data);

/* sprite_draw_bonus.c */

void	sprite_draw(t_sprite *sprite, int i, t_window *win, t_data *data);

#endif