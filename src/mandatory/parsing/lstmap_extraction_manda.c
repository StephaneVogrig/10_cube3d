/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_manda.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:17:56 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/11/27 02:58:00 by aska             ###   ########.fr       */
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

int	lstmap_to_path_and_color(t_assets *assets, t_lstmap **current,
		char *root_path)
{
	t_fs			fs;
	t_dictionarie	kv;
	int				exit_code;

	fs.file_ok = 0x3F;
	while (*current != NULL)
	{
		while (is_empty((*current)->line) == TRUE)
			current = &(*current)->next;
		exit_code = set_dict_key_value(&kv, (*current)->line, &fs);
		if (exit_code == SUCCESS)
			exit_code = set_path_and_color(assets, &kv, root_path);
		else
			break ;
		if (exit_code == SUCCESS)
			file_switch_key(&fs, &kv.key);
		current = &(*current)->next;
		if (fs.file_ok == 0)
			return (exit_code);
	}
	return (exit_code);
}

int	lstmap_extract_info(t_assets *assets, t_map *map, t_lstmap **head, char *map_path)
{
	
	t_lstmap	*current;
	char		*root_path;
	int			exit_code;


	root_path = get_root_path(map_path);
	current = *head;
	exit_code = lstmap_to_path_and_color(assets, &current, root_path);
	root_path = ft_char_f(root_path);
	if (exit_code != SUCCESS)
		return (exit_code);
	exit_code = check_all_validity_line(map, &current);
	if (exit_code == SUCCESS)
		exit_code = lstmap_to_grid(map, &current);
	return (exit_code);
}
