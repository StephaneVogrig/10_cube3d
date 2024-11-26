/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:21:52 by aska              #+#    #+#             */
/*   Updated: 2024/11/26 15:01:20 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

// # include "check_cell.h"
// # include "lstmap_extraction_utils_manda.h"
# include "map.h"
# include "player.h"
# include "stack.h"

int		map_checker(t_map *map, t_player *player);

t_bool	chk_flood_fill(t_map *map, int x, int y);
void	check_cell(int x, int y, t_map *map, t_stack *stack);

#endif