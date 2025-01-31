/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:17:56 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/31 13:33:50 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstmap_extraction_bonus.h"

int	is_map_valid_bonus(char *line)
{
	int	i;

	if (line == NULL)
		return (FALSE);
	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isthis(line[i], "0123456789 NSEWTRL\n") == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	check_line_remain(t_map *map, t_asset_lst **lst_asset,
		t_lstmap *lst_map)
{
	int	exit_code;

	while (lst_map != NULL)
	{
		exit_code = is_empty(lst_map->line);
		if (exit_code != SUCCESS)
			return (ft_return(ERROR, 6, "Line is empty after",
					lst_map->prev->line));
		exit_code = !is_map_valid_bonus(lst_map->line);
		if (exit_code != SUCCESS)
			return (ft_return(ERROR, 6, "Line is invalid", lst_map->line));
		if (cmp_cell_line_to_asset_key(lst_map->line, *lst_asset) == FAIL)
			return (FAIL);
		exit_code = set_map_info(map, lst_map->line);
		if (exit_code != SUCCESS)
			break ;
		lst_map = lst_map->next;
	}
	return (exit_code);
}

int	lstmap_extract_info(t_map *map, char *map_path, t_asset_lst **asset_lst,
		t_sprite_lst **sprite_lst)
{
	t_lstmap	*tmp;
	t_lstmap	*lst_map;
	char		*root_path;
	int			exit_code;

	root_path = NULL;
	lst_map = NULL;
	exit_code = file_load(map_path, &lst_map);
	tmp = lst_map;
	if (exit_code == SUCCESS)
		exit_code = get_root_path(map_path, &root_path);
	if (exit_code == SUCCESS)
		exit_code = lstmap_to_asset(&tmp, root_path, asset_lst, sprite_lst);
	if (exit_code == SUCCESS)
		exit_code = check_line_remain(map, asset_lst, tmp);
	if (exit_code == SUCCESS)
		exit_code = lstmap_to_grid(map, &tmp);
	free(root_path);
	delete_all_lstmap(&lst_map);
	return (exit_code);
}
