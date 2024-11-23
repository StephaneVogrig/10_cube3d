/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:31:37 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/23 16:35:54 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MAP_H
# define MAP_H

# include "textures_manda.h"
# include "player.h"

# define AREA 'x'
# define WALL '1'

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	t_textures			textures;

}				t_map;

int				set_map_info(t_map *map, char *line);
int				map_player_finder(t_map *map, t_player *player);

#endif