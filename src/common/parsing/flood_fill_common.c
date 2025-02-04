/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_common.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:47:13 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/02/04 17:25:36 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

static inline	__attribute__((always_inline, hot))
int	chk_border(int x, int y,
		t_map *map)
{
	if (x == 0 || y == 0 || x == map->width - 1 || y == map->height - 1)
		return (FAIL);
	return (SUCCESS);
}

static
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
			|| map->grid[cell.y][cell.x] == ' '
			|| map->grid[cell.y][cell.x] == '\0')
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

static
bool	check_line(int y, t_map *map)
{
	int	x;

	x = 0;
	while (x < map->width)
	{
		if (map->grid[y][x] == '0' && chk_flood_fill(map, x, y) == FALSE)
			return (FALSE);
		x++;
	}
	return (TRUE);
}

bool	check_border_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		if (check_line(y, map) == FALSE)
			return (FALSE);
		y++;
	}
	return (TRUE);
}
