/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:01:25 by aska              #+#    #+#             */
/*   Updated: 2024/10/04 13:13:01 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

int	map_checker(t_map *map, t_player *player)
{
	char	**map_ff;
	t_bool	ff_ok;

	ff_ok = TRUE;
	map_ff = set_var_creation_map_ff(map);
	if (map_ff == NULL)
		return (ft_return(ERROR, ERROR, "Error on Initialization Map"));
	if (chk_box(player_finder(map, player), EQ, SUCCESS, "Find player") == -1)
		return (ft_return(ERROR, ERROR, "No player on map"));
	map_ff[player->grid.y][player->grid.x] = '0';
	map->grid[player->grid.y][player->grid.x] = '0';
	chk_flood_fill(map_ff, player->grid.x, player->grid.y, &ff_ok);
	if (ff_ok == FALSE)
		return (ft_return(ERROR, ERROR, "Map Invalid"));
	ft_tab_f(map_ff);
	return (SUCCESS);
}

char	**set_var_creation_map_ff(t_map *map)
{
	int		y;
	int		x;
	char	**map_ff;

	y = 0;
	map_ff = ft_calloc(map->height + 3, sizeof(char *));
	if (map_ff == NULL)
		return (NULL);
	while (y != map->height + 2)
	{
		map_ff[y] = ft_calloc(map->width + 3, sizeof(char));
		if (map_ff[y] == NULL)
			return (NULL);
		if (y != 0 && y != map->height + 1)
		{
			x = 1;
			while (x != map->width + 1)
			{
				map_ff[y][x] = map->grid[y - 1][x - 1];
				x++;
			}
		}
		y++;
	}
	return (map_ff);
}

void	chk_flood_fill(char **map_ff, int x, int y, t_bool *ff_ok)
{
	// printf("x: %i y: %i\n", x, y);
	if (map_ff[y][x] == 'X' || map_ff[y][x] == '1')
		return ;
	if (map_ff[y][x] == ' ' || map_ff[y][x] == 0)
	{
		ff_ok = FALSE;
		return ;
	}
	map_ff[y][x] = 'X';
	chk_flood_fill(map_ff, x + 1, y, ff_ok);
	chk_flood_fill(map_ff, x - 1, y, ff_ok);
	chk_flood_fill(map_ff, x, y + 1, ff_ok);
	chk_flood_fill(map_ff, x, y - 1, ff_ok);
}
