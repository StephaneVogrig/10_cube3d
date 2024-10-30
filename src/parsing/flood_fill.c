/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:01:25 by aska              #+#    #+#             */
/*   Updated: 2024/10/30 12:03:05 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

int	map_checker(t_map *map, t_player *player)
{
	t_bool	ff_ok;

	ff_ok = TRUE;
	if (player_finder(map, player) == -1)
		return (FAIL);
	map->grid[player->grid.y][player->grid.x] = '0';
	chk_flood_fill(map, player->grid.x, player->grid.y, &ff_ok);
	chk_box(ff_ok, EQ, TRUE, "Valid Map");
	if (ff_ok == FALSE)
		return (FAIL);
	return (SUCCESS);
}

int	chk_border(t_cell cell, t_map *map)
{
	// Check change variable int to unsigned int
	if (cell.x <= 0 || cell.y <= 0 || cell.x > map->width || cell.y > map->height)
	{
		return (FAIL);
	}
	return (SUCCESS);
}
int	chk_cell(t_cell cell, t_map *map)
{
	if (map->grid[cell.y][cell.x] == WALL)
		return (FAIL);
	else if (map->grid[cell.y][cell.x] == AREA)
		return (FAIL);
	return (SUCCESS);
}



void	chk_flood_fill(t_map *map, int x, int y, t_bool *ff_ok)
{
	t_stack	*stack;
	t_cell	cell;

	stack = create_stack(map->width * map->height, malloc(sizeof(t_stack)));
	push(stack, (t_cell){x, y});
	while (is_stack_empty(stack) == FALSE)
	{
		cell = pop(stack);
		if (chk_border((t_cell){cell.x, cell.y}, map) == FAIL)
			if (map->grid[cell.y][cell.x] != WALL)
			{
				*ff_ok = FALSE;
				printf(RED "Invalid Map\n" CRESET);
				break ;
			}
		if (map->grid[cell.y][cell.x] == ' ')
		{
			*ff_ok = FALSE;
			printf(RED "Invalid Map\n" CRESET);
			break ;
		}
		map->grid[cell.y][cell.x] = AREA;
		if (chk_cell((t_cell){cell.x + 1, cell.y}, map) == SUCCESS)
			push(stack, (t_cell){cell.x + 1, cell.y});
		if (chk_cell((t_cell){cell.x - 1, cell.y}, map) == SUCCESS)
			push(stack, (t_cell){cell.x - 1, cell.y});
		if (chk_cell((t_cell){cell.x, cell.y + 1}, map) == SUCCESS)
			push(stack, (t_cell){cell.x, cell.y + 1});
		if (chk_cell((t_cell){cell.x, cell.y - 1}, map) == SUCCESS)
			push(stack, (t_cell){cell.x, cell.y - 1});
	}
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