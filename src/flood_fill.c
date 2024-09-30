/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:01:25 by aska              #+#    #+#             */
/*   Updated: 2024/09/30 19:28:16 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "flood_fill.h"

int	map_checker(t_map *map, t_player *player)
{
	char **map_ff;

	player_finder(map, player);
	if (chk_box(set_var_creation_map_ff(map, map_ff), EQ, SUCCESS, "Set Check Map") == 1)
		return(ft_return(ERROR, ERROR, "Error on Initialization Map"));
	chk_flood_fill(map, player->grid.x, player->grid.y);
	chk_box(0, EQ, SUCCESS, "Flood Fill");
    ft_tab_f(map_ff);
	return (SUCCESS);
}

int	set_var_creation_map_ff(t_map *map, char **map_ff)
{
	int	y;
	int	x;

	y = 0;
	map_ff = ft_calloc(map->height + 3, sizeof(char *));
	if (map_ff == NULL)
		return (ERROR);
	while (y != map->height + 2)
	{
		map_ff[y] = ft_calloc(map->width + 3, sizeof(char));
		if (map_ff[y] == NULL)
			return (ERROR);
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
	return (SUCCESS);
}

void	chk_flood_fill(t_cub *cub, int x, int y)
{
	if (cub->map_ff[y][x] == BLOK || cub->map_ff[y][x] == 'X')
		return ;
	if (cub->map_ff[y][x] == 0)
		helltrain(cub, ERROR, 1, "Map Invalid");
	cub->map_ff[y][x] = 'X';
	chk_flood_fill(cub, x + 1, y);
	chk_flood_fill(cub, x - 1, y);
	chk_flood_fill(cub, x, y + 1);
	chk_flood_fill(cub, x, y - 1);
}