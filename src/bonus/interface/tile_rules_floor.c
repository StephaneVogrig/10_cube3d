/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_rules_floor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:08:09 by aska              #+#    #+#             */
/*   Updated: 2025/01/19 20:55:28 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tile_rules.h"

void tile_rule(t_interface *interface ,t_tile *tile)
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
	else if (tile->cell == 'T')
		tile->tile_ptr = interface->tiles_index.twin;
	else if (tile->cell == 'L')
		tile->tile_ptr = interface->tiles_index.left_door;
	else if (tile->cell == 'R')
		tile->tile_ptr = interface->tiles_index.right_door;
	else
		tile->tile_ptr = interface->tiles_index.empty;
}
