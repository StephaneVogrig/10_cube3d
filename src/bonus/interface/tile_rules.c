/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:25:48 by aska              #+#    #+#             */
/*   Updated: 2025/01/13 23:42:24 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile_rules.h"

static int chk_border(int x, int y, int width, int height)
{
	if (x < 0 || y < 0 || x >= width || y >= height)
		return (OOB);
	return (0);
}

static t_tiles_id chk_cell(char cell)
{
	if (ft_isthis(cell, "123456789"))
		return (TILE_WALL);
	else if (ft_isthis(cell, " "))
		return (TILE_EMPTY);
	else if (ft_isthis(cell, "RLT"))
		return (TILE_DOOR);
	return (TILE_FLOOR);
}


static t_cardinal_tiles chk_cardinal_cell(char cell, t_vec2i coord, t_map *map)
{
	t_cardinal_tiles card_tile;

	if (chk_border(coord.x, coord.y - 1, map->width, map->height) != OOB)
		card_tile.north = chk_cell(map->grid[coord.y - 1][coord.x]);
	if (chk_border(coord.x + 1, coord.y - 1, map->width, map->height) != OOB)
		card_tile.north_east = chk_cell(map->grid[coord.y - 1][coord.x + 1]);
	if (chk_border(coord.x + 1, coord.y, map->width, map->height) != OOB)
		card_tile.east = chk_cell(map->grid[coord.y][coord.x + 1]);
	if (chk_border(coord.x + 1, coord.y + 1, map->width, map->height) != OOB)
		card_tile.south_east = chk_cell(map->grid[coord.y + 1][coord.x + 1]);
	if (chk_border(coord.x, coord.y + 1, map->width, map->height) != OOB)
		card_tile.south = chk_cell(map->grid[coord.y + 1][coord.x]);
	if (chk_border(coord.x - 1, coord.y + 1, map->width, map->height) != OOB)
		card_tile.south_west = chk_cell(map->grid[coord.y + 1][coord.x - 1]);
	if (chk_border(coord.x - 1, coord.y, map->width, map->height) != OOB)
		card_tile.west = chk_cell(map->grid[coord.y][coord.x - 1]);
	if (chk_border(coord.x - 1, coord.y - 1, map->width, map->height) != OOB)
		card_tile.north_west = chk_cell(map->grid[coord.y - 1][coord.x - 1]);
	return (card_tile);
}

static int	*get_tile_from_id(t_tiles_id id, t_interface *interface)
{
	if (id == TILE_FLOOR)
		return (interface->tiles_index.floor);
	else if (id == TILE_BLANK)
		return (interface->tiles_index.blank);
	else if (id == TILE_WALL)
		return (interface->tiles_index.one_wall);
	else if (id == TILE_TWO_WALL)
		return (interface->tiles_index.two_wall);
	else if (id == TILE_CORNER_WALL)
		return (interface->tiles_index.corner_wall);
	else if (id == TILE_THREE_WALL)
		return (interface->tiles_index.three_wall);
	else if (id == TILE_FOUR_WALL)
		return (interface->tiles_index.four_wall);
	else if (id == TILE_ONE_CORNER)
		return (interface->tiles_index.one_corner);
	else if (id == TILE_TWO_CORNER)
		return (interface->tiles_index.two_corner);
	else if (id == TILE_THREE_CORNER)
		return (interface->tiles_index.three_corner);
	else if (id == TILE_FOUR_CORNER)
		return (interface->tiles_index.four_corner);
	else if (id == TILE_ONE_WALL_CORNER)
		return (interface->tiles_index.one_wall_corner);
	else if (id == TILE_ONE_WALL_TWO_CORNER)
		return (interface->tiles_index.one_wall_two_corner);
	else if (id == TILE_TWO_WALL_CORNER)
		return (interface->tiles_index.two_wall_corner);
	else if (id == TILE_DOOR)
		return (interface->tiles_index.door);
	else if (id == TILE_DOOR_ONE_WALL)
		return (interface->tiles_index.door_one_wall);
	else if (id == TILE_DOOR_TWO_WALL)
		return (interface->tiles_index.door_two_wall);
	else if (id == TILE_EMPTY)
		return (interface->tiles_index.empty);
	return (NULL);
}

t_tile  get_tile(char cell, t_vec2i coord, t_map *map, t_interface *interface)
{
	t_tiles_id			tile_id;
	t_cardinal_tiles	cardinal_tile;
	t_tile				tile;

	tile_id = chk_cell(cell);
	if (tile_id == TILE_WALL)
	{
		tile = (t_tile){.tile_ptr = interface->tiles_index.empty, .pos = coord, .increm = 0};
		return (tile);
	}
	cardinal_tile = chk_cardinal_cell(cell, coord, map);

	
	
}