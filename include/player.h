/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:05:50 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/25 15:59:00 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "vec2i.h"
# include <math.h>
# include "map.h"

# define SPEED_ROT (M_PI / 200)
# define SPEED_MOVE 0.05

typedef struct s_player{
	t_vec2i	grid;
	t_vec2d	box;
	double	dir;
}	t_player;

void	player_move(t_map map, t_player *player, t_vec2i dir, int rot);
void	player_set_dir(t_player *player, char dir);

#endif