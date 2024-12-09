/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/12/09 16:36:57 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"
// #include "debug.h" // debug

static t_map *copy_map(t_map *map)
{
	t_map *map_copy;
	int i;

	map_copy = malloc(sizeof(t_map));
	if (map_copy == NULL)
		return (NULL);
	map_copy = ft_memcpy(map_copy, map, sizeof(t_map));
	map_copy->grid = ft_calloc(sizeof(char *), map->height + 1);
	if (map_copy->grid == NULL)
	{
		free(map_copy);
		return (NULL);
	}
	i = 0;
	while (i < map->height)
	{
		map_copy->grid[i] = ft_strdup(map->grid[i]);
		if (map_copy->grid[i] == NULL)
		{
			map_copy->grid = ft_tab_f(map_copy->grid);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	return (map_copy);
}

void	check_cell(int x, int y, t_map *map, t_stack *stack)
{
	if (ft_isthis(map->grid[y][x], "123456789") == TRUE
		|| map->grid[y][x] == AREA)
		return ;
	push(stack, (t_cell){x, y});
}

int	map_checker(t_map *map, t_player *player)
{
	t_bool	ff_ok;
	t_map	*map_copy;
	int exit_code;

	exit_code = map_player_finder(map, player);
	if (exit_code != SUCCESS)
		return (exit_code);
	map_copy = copy_map(map);
	if(map_copy == NULL)
		return (FAIL);
	ff_ok = chk_flood_fill(map_copy, player->x.grid, player->y.grid);
	map->grid[player->y.grid][player->x.grid] = '0';
	map_copy->grid = ft_tab_f(map_copy->grid);
	if (ff_ok == FALSE)
		return (ft_return(ERROR, 275, "Error on Map"));
	return (SUCCESS);
}
