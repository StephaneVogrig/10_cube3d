/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:17:56 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/11/01 19:09:50 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstmap_extraction.h"

char	*get_root_path(char *path)
{
	char	*root_path;

	root_path = ft_strrchr(path, '/');
	if (root_path == NULL)
		return (NULL);
	return (ft_substr(path, 0, root_path - path + 1));
}


int	check_all_validity_line(t_map *map, t_lstmap **lst_map)
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
			return (ft_return(ERROR, FAIL, "Error on Map Creation"));
		tmp->line = NULL;
		tmp = tmp->next;
		y++;
	}
	return (SUCCESS);
}

int	lstmap_to_path_and_color(t_textures *tex, t_lstmap **lst_map, char *root_path)
{
	t_fs		fs;
	t_key_value kv;
	int			exit_code;

	fs.file_ok = 0x3F;

	while (*lst_map != NULL)
	{
		if (is_empty((*lst_map)->line) == TRUE)
		{
			delete_node_lstmap(lst_map, *lst_map);
			continue ;
		}
		exit_code = set_key_value(&kv, (*lst_map)->line, &fs);
		if (exit_code == SUCCESS)
			exit_code = attrib_path(tex, &kv, root_path);
		if (exit_code != SUCCESS)
			break ;
		file_switch_key(&fs, &kv.key);
		delete_node_lstmap(lst_map, *lst_map);
		if (fs.file_ok == 0)
			return (exit_code);
	}
	return (exit_code);
}

int	lstmap_extraction_info(t_lstmap **lst_map, t_map *map, char *map_path)
{
	char	*root_path;
	int	exit_code;

	root_path = get_root_path(map_path);
	exit_code = lstmap_to_path_and_color(&map->textures, lst_map, root_path);
	if (exit_code != SUCCESS)
		return (exit_code);
	if (check_all_validity_line(map, lst_map) == FAIL)
		return (FAIL);
	if (lstmap_to_grid(map, lst_map) == FAIL)
		return (FAIL);
	return (SUCCESS);
}