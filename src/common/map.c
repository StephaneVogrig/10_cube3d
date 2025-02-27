/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:54:45 by aska              #+#    #+#             */
/*   Updated: 2025/02/04 22:36:43 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	set_map_info(t_map *map, char *line)
{
	int				i;
	static t_bool	player_valid = FALSE;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isthis(line[i], "NSWE"))
		{
			if (player_valid == TRUE)
				return (ft_return(ERROR, FAIL, "Two Player on map", line));
			player_valid = TRUE;
		}
		if (i++ == INT_MAX)
			return (ft_return(ERROR, FAIL, "Map width too large", NULL));
	}
	if (i > map->width)
		map->width = i;
	if (map->height == INT_MAX)
		return (ft_return(ERROR, FAIL, "Map height too large", NULL));
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
		return (ft_return(ERROR, FAIL, "No player on map", NULL));
	return (SUCCESS);
}

inline
int	is_outside_map(const t_map *map, t_position *p)
{
	return (p->x.grid < 0 || p->y.grid < 0 || p->x.grid >= map->width
		|| p->y.grid >= map->height);
}

inline
char	map_get_cell(const t_map *map, t_position *p)
{
	if (is_outside_map(map, p))
		return (OUTSIDE);
	return (map->grid[p->y.grid][p->x.grid]);
}
