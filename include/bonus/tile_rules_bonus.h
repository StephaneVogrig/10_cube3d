/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_rules_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:26:13 by aska              #+#    #+#             */
/*   Updated: 2025/02/05 22:27:26 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TILE_RULES_BONUS_H
# define TILE_RULES_BONUS_H

# include "interface_utils_bonus.h"
# include "vector.h"
# include "map.h"

typedef struct s_tile
{
	int		*tile_ptr;
	char	cell;
	t_vec2i	pos;
}			t_tile;

int			*get_tile(char cell, t_interface *interface);

#endif