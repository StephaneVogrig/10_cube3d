/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:01:25 by aska              #+#    #+#             */
/*   Updated: 2024/11/01 02:03:08 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

int	map_checker(t_map *map, t_player *player)
{
	t_bool	ff_ok;

	// print_tab(map->grid);
	if (player_finder(map, player) == -1)
		return (FAIL);
	// map->grid[player->y.grid][player->x.grid] = '0';
	ff_ok = chk_flood_fill(map, player->x.grid, player->y.grid);
	chk_box(ff_ok, EQ, TRUE, "Valid Map");
	if (ff_ok == FALSE)
		return (FAIL);
	return (SUCCESS);
}

int	chk_border(int x, int y, t_map *map)
{
	// printf("x: %i, y: %i", x, y);
	// printf(" | map->width: %i, map->height: %i\n", map->width, map->height);
	if (x == 0 || y == 0 || x == map->width - 1 || y == map->height - 1)
	{
		// printf(RED "FAIL\n" CRESET);
		return (FAIL);
	}
	// printf(GRN "SUCCESS\n" CRESET);
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
