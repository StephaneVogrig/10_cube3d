/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:54:45 by aska              #+#    #+#             */
/*   Updated: 2024/10/30 12:17:59 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "map.h"
#include "player.h"

char	*get_root_path(char *path)
{
	char	*root_path;

	root_path = ft_strrchr(path, '/');
	if (root_path == NULL)
		return (NULL);
	return (ft_substr(path, 0, root_path - path + 1));
}

int	lstmap_extraction_info(t_lstmap **lst_map, t_map *map, char *path)
{
	char	*root_path;

	root_path = get_root_path(path);
	if (lstmap_to_textures(&map->textures, lst_map, root_path) == FAIL)
		return (FAIL);
	if (check_all_validity_line(map, lst_map) == FAIL)
		return (FAIL);
	if (lstmap_to_grid(map, lst_map) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	check_line(char *line)
{
	if (line == NULL)
		return (ERROR);
	if (is_empty(line) == TRUE || is_map_valid(line) == FALSE)
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
	x = 0;
	while (line[x])
		if (x++ == INT_MAX)
			return (FAIL);
	if (x > map->width)
		map->width = x;
	if (map->height == INT_MAX)
		return (FAIL);
	map->height++;
	return (SUCCESS);
}

int	check_all_validity_line(t_map *map, t_lstmap **lst_map)
{
	t_lstmap	*tmp;

	tmp = *lst_map;
	while (tmp != NULL && is_empty(tmp->line) == TRUE)
	{
		tmp->line = ft_char_f(tmp->line);
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

int	lstmap_to_grid(t_map *map, t_lstmap **lst_map)
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
		map->grid[y] = tmp->line;
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
