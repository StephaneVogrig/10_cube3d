/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:01:25 by aska              #+#    #+#             */
/*   Updated: 2024/10/12 01:49:30 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

int	map_checker(t_map *map, t_player *player)
{
	t_bool	ff_ok;

	ff_ok = TRUE;
	
	if (player_finder(map, player) == -1)
		return (FAIL);
	map->grid[player->grid.y][player->grid.x] = '0';
	chk_flood_fill(map, player->grid.x, player->grid.y, &ff_ok);
	chk_box(ff_ok, EQ, TRUE, "Valid Map");
	if (ff_ok == FALSE)
		return (ft_return(ERROR, FAIL, "Map Invalid"));
	return (SUCCESS);
}



void	chk_flood_fill(t_map *map, int x, int y, t_bool *ff_ok)
{
	if (map->grid[y][x] == 'X' || map->grid[y][x] == '1')
		return ;
	if (map->grid[y][x] == ' ')
	{
		ff_ok = FALSE;
		printf("x: %i y: %i\n", x, y);
		return ;
	}
	if (x == 0 || y == 0 || x == map->width || y == map->height)
	{
		ff_ok = FALSE;
		printf("x: %i y: %i\n", x, y);
		return ;
	}
	map->grid[y][x] = 'X';
	chk_flood_fill(map, x + 1, y, ff_ok);
	chk_flood_fill(map, x - 1, y, ff_ok);
	chk_flood_fill(map, x, y + 1, ff_ok);
	chk_flood_fill(map, x, y - 1, ff_ok);
}
