/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:25:48 by aska              #+#    #+#             */
/*   Updated: 2025/02/05 00:39:54 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile_rules.h"

void	tile_init(t_interface *interface, t_tile *tile, t_vec2i coord)
{
	tile->tile_ptr = interface->tiles_index.empty;
	tile->pos.x = coord.x * TILES_W;
	tile->pos.y = coord.y * TILES_H;
}

t_tile	get_tile(char cell, t_vec2i coord, t_interface *interface)
{
	t_tile	tile;

	tile_init(interface, &tile, coord);
	tile.cell = cell;
	tile_rule(interface, &tile);
	return (tile);
}
