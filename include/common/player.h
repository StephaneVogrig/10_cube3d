/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:05:50 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/03 22:05:19 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "gametime.h"
# include "key_move.h"
# include "libft.h"
# include "position.h"
# include "vector.h"
# include <math.h>

// Radian per second
# define SPEED_ROT 4.4

// Cell per second
# define SPEED_MOVE 4.0

typedef struct s_player
{
	union
	{
		t_position		position;
		struct
		{
			t_gridbox	x;
			t_gridbox	y;
		};
	};
	double				dir;
}						t_player;

t_vec2d					player_dir_move_vec(t_player *player,
							t_vec2i move_input);
void					player_rotation(t_player *player, double rotation);
int						player_rotate(t_player *player, t_key key,
							t_time_us delta_time);
void					player_set_dir(t_player *player, char dir);
t_vec2d					dir_to_dirvec(double dir);

#endif