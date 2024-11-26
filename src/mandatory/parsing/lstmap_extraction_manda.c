/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_manda.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:17:56 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/11/26 15:36:15 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstmap_extraction_manda.h"

int	check_all_validity_line(t_map *map, t_lstmap **lst_map)
{
	t_lstmap	*tmp;
	int			exit_code;

	tmp = *lst_map;
	while (tmp != NULL && is_empty(tmp->line) == TRUE)
	{
		delete_node_lstmap(lst_map, tmp);
		tmp = *lst_map;
	}
	while (tmp != NULL)
	{
		exit_code = check_line(tmp->line);
		if (exit_code != SUCCESS)
			break ;
		exit_code = set_map_info(map, tmp->line);
		if (exit_code != SUCCESS)
			break ;
		tmp = tmp->next;
	}
	return (exit_code);
}

int	lstmap_to_grid(t_map *map, t_lstmap **lst_map)
{
	int			y;
	t_lstmap	*tmp;

	y = 0;
	tmp = *lst_map;
	map->grid = ft_calloc(map->height + 1, sizeof(char *));
	if (map->grid == NULL)
		return (ft_return(ERROR, 273, "Error on Map Creation"));
	while (y != map->height)
	{
		map->grid[y] = ft_calloc(map->width + 1, sizeof(char));
		if (map->grid[y] == NULL)
			return (ft_return(ERROR, 274, "Error on Map Creation"));
		ft_strcpy(map->grid[y], tmp->line);
		tmp->line = NULL;
		tmp = tmp->next;
		y++;
	}
	return (SUCCESS);
}

int	lstmap_to_path_and_color(t_assets *tex, t_lstmap **lst_map,
		char *root_path)
{
	t_fs			fs;
	t_dictionaries	kv;
	int				exit_code;

	fs.file_ok = 0x3F;
	while (*lst_map != NULL)
	{
		while (is_empty((*lst_map)->line) == TRUE)
			delete_node_lstmap(lst_map, *lst_map);
		exit_code = set_dict_key_value(&kv, (*lst_map)->line, &fs);
		if (exit_code == SUCCESS)
			exit_code = set_path_and_color(tex, &kv, root_path);
		else
			break ;
		if (exit_code == SUCCESS)
			file_switch_key(&fs, &kv.key);
		delete_node_lstmap(lst_map, *lst_map);
		if (fs.file_ok == 0)
			return (exit_code);
	}
	return (exit_code);
}

int	lstmap_extract_info(t_assets *textures, t_map *map, char *map_path)
{
	t_lstmap	*lst_map;
	char		*root_path;
	int			exit_code;

	lst_map = NULL;
	exit_code = file_load(map_path, &lst_map);
	if (exit_code != SUCCESS)
		return (exit_code);
	root_path = get_root_path(map_path);
	exit_code = lstmap_to_path_and_color(textures, &lst_map, root_path);
	root_path = ft_char_f(root_path);
	if (exit_code != SUCCESS)
		return (exit_code);
	exit_code = check_all_validity_line(map, &lst_map);
	if (exit_code == SUCCESS)
		exit_code = lstmap_to_grid(map, &lst_map);
	delete_all_lstmap(&lst_map);
	return (exit_code);
}
