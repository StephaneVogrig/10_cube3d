/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:05:50 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/31 02:36:19 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "libft.h"
# include "map.h"
# include "vec2i.h"
# include <math.h>
# include "position.h"

# define SPEED_ROT (M_PI / 50)
# define SPEED_MOVE 0.06

typedef struct s_player
{
	union {
		t_position	position;
		struct {
			t_vec2i	grid;
			t_vec2d	box;
		};
	};
	double	dir;
}			t_player;

t_position	player_new_position(t_player *player, t_vec2i vec_dir);
void		player_rotation(t_player *player, int rot);
void		player_set_dir(t_player *player, char dir);
int			player_finder(t_map *map, t_player *player);

#endif