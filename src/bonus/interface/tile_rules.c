/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:25:48 by aska              #+#    #+#             */
/*   Updated: 2025/01/19 20:58:40 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile_rules.h"


void print_tile(t_tile tile)
{
	printf("#---------------------#\n");
	printf("tile_ptr: %d\n", *tile.tile_ptr);
	printf("pos.x: %d\tpos.y: %d\n", tile.pos.x, tile.pos.y);
	printf("#---------------------#\n\n");
}

void	tile_init(t_interface *interface, t_tile *tile, t_vec2i coord)
{
	tile->tile_ptr = interface->tiles_index.empty;
	tile->pos.x = coord.x * TILES_W;
	tile->pos.y = coord.y * TILES_H;
}

t_tile  get_tile(char cell, t_vec2i coord, t_interface *interface)
{
	t_tile				tile;

	tile_init(interface, &tile, coord);
	tile.cell = cell;
	tile_rule(interface, &tile);
	return (tile);
}