/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:25:48 by aska              #+#    #+#             */
/*   Updated: 2025/02/05 18:55:54 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile_rules.h"

static
void	tile_rule_numbers(t_interface *interface, t_tile *tile)
{
	if (tile->cell == '0')
		tile->tile_ptr = interface->tiles_index.floor;
	else if (tile->cell == '1')
		tile->tile_ptr = interface->tiles_index.one;
	else if (tile->cell == '2')
		tile->tile_ptr = interface->tiles_index.two;
	else if (tile->cell == '3')
		tile->tile_ptr = interface->tiles_index.three;
	else if (tile->cell == '4')
		tile->tile_ptr = interface->tiles_index.four;
	else if (tile->cell == '5')
		tile->tile_ptr = interface->tiles_index.five;
	else if (tile->cell == '6')
		tile->tile_ptr = interface->tiles_index.six;
	else if (tile->cell == '7')
		tile->tile_ptr = interface->tiles_index.seven;
	else if (tile->cell == '8')
		tile->tile_ptr = interface->tiles_index.height;
	else if (tile->cell == '9')
		tile->tile_ptr = interface->tiles_index.nine;
}

static
void	tile_rule_doors(t_interface *interface, t_tile *tile)
{
	if (tile->cell == 'T')
		tile->tile_ptr = interface->tiles_index.twin;
	else if (tile->cell == 'L')
		tile->tile_ptr = interface->tiles_index.left_door;
	else if (tile->cell == 'R')
		tile->tile_ptr = interface->tiles_index.right_door;
}

static
void	tile_rule(t_interface *interface, t_tile *tile)
{
	if (ft_strchr("0123456789", tile->cell))
		tile_rule_numbers(interface, tile);
	else if (ft_strchr("TLR", tile->cell))
		tile_rule_doors(interface, tile);
}

int	*get_tile(char cell, t_interface *interface)
{
	t_tile	tile;

	if (cell == OUTSIDE || cell == '\0' || cell == ' ')
		return (NULL);
	tile.cell = cell;
	tile_rule(interface, &tile);
	return (tile.tile_ptr);
}
