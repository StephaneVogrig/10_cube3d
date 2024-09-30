/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:21:52 by aska              #+#    #+#             */
/*   Updated: 2024/09/30 19:27:59 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

#include "file_process.h"
#include "map.h"
#include "player.h"

int	map_checker(t_map *map, t_player *player)
int	set_var_creation_map_ff(t_map *map, char **map_ff)
void	chk_flood_fill(t_cub *cub, int x, int y)


#endif