/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/11/12 03:24:21 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "flood_fill.h"

int	map_checker(t_map *map, t_player *player)
{
	t_bool	ff_ok;
	int exit_code;

	exit_code = player_finder(map, player);
	if (exit_code != SUCCESS)
		return (exit_code);
	ff_ok = chk_flood_fill(map, player->x.grid, player->y.grid);
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
	if (map->grid[y][x] == WALL)
		return (FAIL);
	else if (map->grid[y][x] == AREA)
		return (FAIL);
	return (SUCCESS);
}

t_bool	chk_flood_fill(t_map *map, int x, int y)
{
	t_stack	stack;
	t_cell	cell;

	if (create_stack(map->width * map->height, &stack) == FAIL)
		return (FALSE);
	push(&stack, (t_cell){x, y});
	while (is_stack_empty(&stack) == FALSE)
	{
		cell = pop(&stack);
		if (chk_border(cell.x, cell.y, map) == FAIL
			|| map->grid[cell.y][cell.x] == ' ')
			return (FALSE);
		map->grid[cell.y][cell.x] = AREA;
		if (chk_cell(cell.x + 1, cell.y, map) == SUCCESS)
			push(&stack, (t_cell){cell.x + 1, cell.y});
		if (chk_cell(cell.x - 1, cell.y, map) == SUCCESS)
			push(&stack, (t_cell){cell.x - 1, cell.y});
		if (chk_cell(cell.x, cell.y + 1, map) == SUCCESS)
			push(&stack, (t_cell){cell.x, cell.y + 1});
		if (chk_cell(cell.x, cell.y - 1, map) == SUCCESS)
			push(&stack, (t_cell){cell.x, cell.y - 1});
	}
	free(stack.data);
	return (TRUE);
}