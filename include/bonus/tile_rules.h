/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_rules.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:26:13 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 16:04:26 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TILE_RULES_H
# define TILE_RULES_H

# include "interface_utils_bonus.h"
# include "map.h"
# include "vector.h"

typedef struct s_tile
{
	int		*tile_ptr;
	char	cell;
	t_vec2i	pos;
}			t_tile;

t_tile		get_tile(char cell, t_vec2i coord, t_interface *interface);
void		tile_rule(t_interface *interface, t_tile *tile);
void		print_tile(t_tile tile);

#endif