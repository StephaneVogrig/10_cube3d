/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_common.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:47:13 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/30 01:21:01 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

static int	chk_border(int x, int y, t_map *map)
{
	if (x == 0 || y == 0 || x == map->width - 1 || y == map->height - 1)
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
		{
			free(stack.data);
			return (ft_return(ERROR, FALSE, "Map Invalid", map->grid[cell.y]));
		}
		map->grid[cell.y][cell.x] = AREA;
		check_cell(cell.x, cell.y + 1, map, &stack);
		check_cell(cell.x, cell.y - 1, map, &stack);
		check_cell(cell.x + 1, cell.y, map, &stack);
		check_cell(cell.x - 1, cell.y, map, &stack);
	}
	free(stack.data);
	return (TRUE);
}
