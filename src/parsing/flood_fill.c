/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:01:25 by aska              #+#    #+#             */
/*   Updated: 2024/10/22 09:24:42 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

int	map_checker(t_map *map, t_player *player)
{
	static t_bool	ff_ok = TRUE;

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
	// printf("x: %i y: %i\n", x, y);
	if (ff_ok == FALSE)
		return ;
	if (x == 0 || y == 0 || x > map->width + 1 || y > map->height + 1)
	{
		ff_ok = FALSE;
		printf(HRED "x: %i |\ty: %i\t| %c\n" CRESET, x, y, map->grid[y][x]);
		return ;
	}
	if (map->grid[y][x] == 'X' || map->grid[y][x] == '1')
		return ;
	if (map->grid[y][x] == ' ')
	{
		ff_ok = FALSE;
		printf(HBLU "x: %i |\ty: %i\t| %c\n" CRESET, x, y, map->grid[y][x]);
		return ;
	}
	map->grid[y][x] = 'X';
	chk_flood_fill(map, x + 1, y, ff_ok);
	chk_flood_fill(map, x - 1, y, ff_ok);
	chk_flood_fill(map, x, y + 1, ff_ok);
	chk_flood_fill(map, x, y - 1, ff_ok);
}

void	print_map_highlight_error(t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < map->height + 2)
	{
		j = 0;
		while (j < map->width + 2)
		{
			if (i == y && j == x)
				printf(HRED "%c" CRESET, map->grid[i][j]);
			else
				printf("%c", map->grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}