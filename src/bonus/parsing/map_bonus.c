/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:08:25 by aska              #+#    #+#             */
/*   Updated: 2025/02/04 17:24:34 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

static
void	map_copy_free(t_map *map_copy)
{
	map_copy->grid = ft_tab_f(map_copy->grid);
	free(map_copy);
}

static
int	fill_map_grid(t_map *map, t_map *map_copy)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		map_copy->grid[y] = ft_calloc(map->width + 1, sizeof(char));
		if (map_copy->grid[y] == NULL)
		{
			map_copy->grid = ft_tab_f(map_copy->grid);
			return (ft_return(ERROR, FAIL, "malloc failed", "fill_map_grid"));
		}
		ft_memcpy(map_copy->grid[y], map->grid[y], map->width + 1);
		y++;
	}
	return (SUCCESS);
}

static
t_map	*copy_map(t_map *map)
{
	t_map	*map_copy;

	map_copy = malloc(sizeof(t_map));
	if (map_copy == NULL)
	{
		ft_display(ERROR, "copy_map: malloc failed");
		return (NULL);
	}
	map_copy->width = map->width;
	map_copy->height = map->height;
	map_copy->grid = ft_calloc(sizeof(char *), map->height + 1);
	if (map_copy->grid == NULL)
	{
		free(map_copy);
		ft_display(ERROR, "copy_map: malloc failed");
		return (NULL);
	}
	if (fill_map_grid(map, map_copy) != SUCCESS)
	{
		free(map_copy);
		return (NULL);
	}
	return (map_copy);
}

inline	__attribute__((always_inline, hot))
void	check_cell(int x, int y,
		t_map *map, t_stack *stack)
{
	if (ft_isthis(map->grid[y][x], "123456789") == TRUE
		|| map->grid[y][x] == AREA)
		return ;
	push(stack, (t_cell){x, y});
}

int	map_setup(t_map *map, t_player *player)
{
	t_bool	ff_ok;
	t_map	*map_copy;
	int		exit_code;

	exit_code = map_player_finder(map, player);
	if (exit_code != SUCCESS)
		return (exit_code);
	map->grid[player->y.grid][player->x.grid] = '0';
	map_copy = copy_map(map);
	if (map_copy == NULL)
		return (FAIL);
	ff_ok = check_border_map(map_copy);
	map_copy_free(map_copy);
	if (ff_ok == FALSE)
		return (FAIL);
	return (SUCCESS);
}
