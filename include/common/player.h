/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:05:50 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/22 06:54:01 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "libft.h"
# include "vec2i.h"
# include <math.h>
# include "position.h"
# include "gametime.h"

# define SPEED_ROT (M_PI / 70)
# define SPEED_MOVE 0.06

typedef struct s_player
{
	union {
		t_position	position;
		struct {
			t_grid_box	x;
			t_grid_box	y;
		};
	};
	double	dir;
}			t_player;

t_position	new_position(t_position start, double dir, t_vec2d move);
void		player_rotation(t_player *player, double rotation);
void		player_set_dir(t_player *player, char dir);

#endif