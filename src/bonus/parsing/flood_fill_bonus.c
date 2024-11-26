/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/11/26 01:17:09 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill_bonus.h"
// #include "debug.h" // debug

t_map *copy_map(t_map *map)
{
	t_map *map_copy;
	int i;

	map_copy = malloc(sizeof(t_map));
	if (map_copy == NULL)
		return (NULL);
	map_copy = ft_memcpy(map_copy, map, sizeof(t_map));
	map_copy->grid = malloc(sizeof(char *) * map->height);
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
	map_copy->grid[i] = NULL;
	return (map_copy);
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
	// map_print(map_copy); //debug
	// map_print(map); //debug
	ff_ok = chk_flood_fill(map_copy, player->x.grid, player->y.grid);
	map->grid[player->y.grid][player->x.grid] = '0';
	// map_print(map_copy); //debug
	// map_print(map); //debug
	map_copy->grid = ft_tab_f(map_copy->grid);
	if (ff_ok == FALSE)
		return (ft_return(ERROR, 275, "Error on Map"));
	return (SUCCESS);
}

int	chk_border(int x, int y, t_map *map)
{
	if (x == 0 || y == 0 || x == map->width - 1 || y == map->height - 1)
		return (FAIL);
	return (SUCCESS);
}
int	chk_cell(int x, int y, t_map *map)
{
	if (ft_isthis(map->grid[y][x], "123456789") == TRUE)
		return (FAIL);
	else if (map->grid[y][x] == AREA)
		return (FAIL);
	return (SUCCESS);
}

t_bool	chk_flood_fill(t_map *map_copy, int x, int y)
{
	t_stack	stack;
	t_cell	cell;

	if (create_stack(map_copy->width * map_copy->height, &stack) == FAIL)
		return (FALSE);
	push(&stack, (t_cell){x, y});
	while (is_stack_empty(&stack) == FALSE)
	{
		cell = pop(&stack);
		if (chk_border(cell.x, cell.y, map_copy) == FAIL
			|| map_copy->grid[cell.y][cell.x] == ' ')
			return (FALSE);
		map_copy->grid[cell.y][cell.x] = AREA;
		if (chk_cell(cell.x + 1, cell.y, map_copy) == SUCCESS)
			push(&stack, (t_cell){cell.x + 1, cell.y});
		if (chk_cell(cell.x - 1, cell.y, map_copy) == SUCCESS)
			push(&stack, (t_cell){cell.x - 1, cell.y});
		if (chk_cell(cell.x, cell.y + 1, map_copy) == SUCCESS)
			push(&stack, (t_cell){cell.x, cell.y + 1});
		if (chk_cell(cell.x, cell.y - 1, map_copy) == SUCCESS)
			push(&stack, (t_cell){cell.x, cell.y - 1});
	}
	free(stack.data);
	return (TRUE);
}
