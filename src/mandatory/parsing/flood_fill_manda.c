/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_manda.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:18:49 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/02/04 14:38:46 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

inline __attribute__((always_inline, hot))
void	check_cell(int x, int y, t_map *map, t_stack *stack)
{
	if (map->grid[y][x] == WALL || map->grid[y][x] == AREA)
		return ;
	push(stack, (t_cell){x, y});
}

int	map_setup(t_map *map, t_player *player)
{
	t_bool	ff_ok;
	int		exit_code;

	exit_code = map_player_finder(map, player);
	if (exit_code != SUCCESS)
		return (exit_code);
	map->grid[player->y.grid][player->x.grid] = '0';
	ff_ok = check_border_map(map);
	if (ff_ok == FALSE)
		return (FAIL);
	return (SUCCESS);
}
