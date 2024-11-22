/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:54:45 by aska              #+#    #+#             */
/*   Updated: 2024/11/21 23:02:52 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "map.h"
#include "player.h"

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