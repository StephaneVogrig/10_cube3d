/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_rules.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:26:13 by aska              #+#    #+#             */
/*   Updated: 2025/01/13 19:03:38 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TILE_RULES_H
# define TILE_RULES_H

#include "vector.h"
#include "interface_utils_bonus.h"
#include "map.h"

typedef struct s_cardinal_tiles
{
	t_tiles_raw  north;
	t_tiles_raw  north_east;
	t_tiles_raw  east;
	t_tiles_raw  south_east;
	t_tiles_raw  south;
	t_tiles_raw  south_west;
	t_tiles_raw  west;
	t_tiles_raw  north_west;
}   t_cardinal_tiles;

typedef enum e_tiles_raw
{
    TILE_FLOOR,
    TILE_WALL,
    TILE_DOOR,
    TILE_EMPTY
}   t_tiles_raw;

typedef enum e_tiles_id
{
	OOB = -1,
	TILE_FLOOR,
	TILE_BLANK,
	TILE_ONE_WALL,
	TILE_TWO_WALL,
	TILE_CORNER_WALL,
	TILE_THREE_WALL,
	TILE_FOUR_WALL,
	TILE_ONE_CORNER,
	TILE_TWO_CORNER,
	TILE_THREE_CORNER,
	TILE_FOUR_CORNER,
	TILE_ONE_WALL_CORNER,
	TILE_ONE_WALL_TWO_CORNER,
	TILE_TWO_WALL_CORNER,
	TILE_DOOR,
	TILE_DOOR_ONE_WALL,
	TILE_DOOR_TWO_WALL,
	TILE_EMPTY
}	t_tiles_id;

#endif