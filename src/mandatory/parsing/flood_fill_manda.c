/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_manda.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:18:49 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/11/26 15:00:28 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	check_cell(int x, int y, t_map *map, t_stack *stack)
{
	if (map->grid[y][x] == WALL || map->grid[y][x] == AREA)
		return ;
	push(stack, (t_cell){x, y});
}

int	map_checker(t_map *map, t_player *player)
{
	t_bool	ff_ok;
	int		exit_code;

	exit_code = map_player_finder(map, player);
	if (exit_code != SUCCESS)
		return (exit_code);
	ff_ok = chk_flood_fill(map, player->x.grid, player->y.grid);
	if (ff_ok == FALSE)
		return (ft_return(ERROR, 275, "Error on Map"));
	return (SUCCESS);
}