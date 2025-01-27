/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:21:52 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 16:04:34 by aska             ###   ########.fr       */
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