/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:54:45 by aska              #+#    #+#             */
/*   Updated: 2024/11/23 18:09:16 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "debug.h" //debug
#include "map.h"

int	set_map_info(t_map *map, char *line)
{
	int				x;
	int				i;
	static t_bool	player_valid = FALSE;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isthis(line[i++], "NSWE"))
		{
			if (player_valid == TRUE)
				return (ft_return(ERROR, 273, "Player on map Invalid"));
			player_valid = TRUE;
		}
	}
	x = 0;
	while (line[x])
		if (x++ == INT_MAX)
			return (ft_return(ERROR, 274, "Map width too large"));
	if (x > map->width)
		map->width = x;
	if (map->height == INT_MAX)
		return (ft_return(ERROR, 274, "Map height too large"));
	map->height++;
	return (SUCCESS);
}

int	map_player_finder(t_map *map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (map->grid[++y] != NULL)
	{
		x = 0;
		while (map->grid[y][x] != 0)
		{
			if (ft_isthis(map->grid[y][x], "NSWE"))
			{
				player_set_dir(player, map->grid[y][x]);
				player->x.grid = x;
				player->y.grid = y;
				player->x.box = 0.5;
				player->y.box = 0.5;
			}
			x++;
		}
	}
	if (player->x.grid == 0 && player->y.grid == 0)
		return (ft_return(ERROR, FAIL, "No player on map"));
	return (SUCCESS);
}
