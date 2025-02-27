/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:21:52 by aska              #+#    #+#             */
/*   Updated: 2025/02/04 14:39:14 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

# include "map.h"
# include "player.h"
# include "stack.h"
# include "stdbool.h"

void	check_cell(int x, int y, t_map *map, t_stack *stack);
int		map_setup(t_map *map, t_player *player);
bool	check_border_map(t_map *map);

#endif