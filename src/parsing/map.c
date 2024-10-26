/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:54:45 by aska              #+#    #+#             */
/*   Updated: 2024/10/26 14:31:42 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "file_process.h"
#include "lst_map.h"
#include "map.h"
#include "player.h"

int	map_setup(void *mlx, t_lstmap **lst_map, t_map *map)
{
	if (lstmap_to_textures(mlx, &map->textures, lst_map) == FAIL)
		return (FAIL);
	if (lstmap_to_grid(map, lst_map) == FAIL)
		return (FAIL);
	if (map_creation(map, lst_map) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	check_line(char *line)
{
	if (line == NULL)
		return (ERROR);
	if (is_empty_line(line) == TRUE || is_map_valid(line) == FALSE)
		return (ft_return(ERROR, FAIL, "Invalid map"));
	return (SUCCESS);
}

int	set_map_info(t_map *map, char *line)
{
	int				x;
	int				i;
	static t_bool	player_valid = FALSE;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isthis(line[i++], "NSWE"))
		{
			if (player_valid == TRUE)
				return (ft_return(ERROR, FAIL, "Player on map Invalid"));
			player_valid = TRUE;
		}
	}
	x = (int)ft_strlen(line);
	if (x > map->width)
		map->width = x;
	map->height++;
	return (SUCCESS);
}

int	lstmap_to_grid(t_map *map, t_lstmap **lst_map)
{
	t_lstmap	*tmp;

	tmp = *lst_map;
	while (tmp != NULL && is_empty(tmp->line) == TRUE)
	{
		delete_node_lstmap(lst_map, tmp);
		tmp = *lst_map;
	}
	while (tmp != NULL)
	{
		if (check_line(tmp->line) == FAIL)
			return (FAIL);
		if (set_map_info(map, tmp->line) == FAIL)
			return (FAIL);
		tmp = tmp->next;
	}
	return (SUCCESS);
}

int	map_creation(t_map *map, t_lstmap **lst_map)
{
	int			y;
	t_lstmap	*tmp;

	y = 0;
	tmp = *lst_map;
	map->grid = ft_calloc(map->height + 1, sizeof(char *));
	if (map->grid == NULL)
		return (ft_return(ERROR, FAIL, "Error on Map Creation"));
	while (y != map->height)
	{
		map->grid[y] = ft_strdup(tmp->line);
		if (map->grid[y] == NULL)
		{
			map->grid = ft_tab_f(map->grid);
			return (ft_return(ERROR, FAIL, "Error on Map Creation"));
		}
		tmp = tmp->next;
		y++;
	}
	return (SUCCESS);
}
