/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:05:50 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/01 11:31:52 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "libft.h"
# include "map.h"
# include "vec2i.h"
# include <math.h>

# define SPEED_ROT (M_PI / 200)
# define SPEED_MOVE 0.06

typedef struct s_player
{
	t_vec2i	grid;
	t_vec2d	box;
	double	dir;
}			t_player;

void		player_move(t_map map, t_player *player, t_vec2i dir, int rot);
void		player_set_dir(t_player *player, char dir);
int			player_finder(t_map *map, t_player *player);

#endif