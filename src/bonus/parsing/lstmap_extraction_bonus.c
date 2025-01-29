/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:17:56 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/29 15:24:16 by ygaiffie         ###   ########.fr       */
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

int	check_line_remain(t_map *map, t_asset_lst **lst_asset, t_lstmap **lst_map)
{
	t_lstmap	*tmp;
	int			exit_code;

	tmp = *lst_map;
	while (tmp != NULL)
	{
		exit_code = is_empty(tmp->line);
		if (exit_code != SUCCESS)
			return (ft_return(ERROR, 6, "Line is empty"));
		exit_code = !is_map_valid_bonus(tmp->line);
		if (exit_code != SUCCESS)
			return (ft_return(ERROR, 6, tmp->line));
		if (cmp_cell_line_to_asset_key(tmp->line, *lst_asset) == FAIL)
			return (FAIL);
		exit_code = set_map_info(map, tmp->line);
		if (exit_code != SUCCESS)
			break ;
		tmp = tmp->next;
	}
	return (exit_code);
}

static int	is_line_valid(t_lstmap **tmp)
{
	while (*tmp != NULL && is_empty((*tmp)->line) == TRUE)
		*tmp = (*tmp)->next;
	if (*tmp == NULL)
		return (FAIL);
	if (!ft_isthis((*tmp)->line[0], "NWESFCTLR"))
		return (FAIL);
	if (!ft_isthis((*tmp)->line[1], "EAOP 123456789"))
		return (FAIL);
	if (ft_strlen_endc((*tmp)->line, ' ') > 2)
		return (FAIL);
	return (SUCCESS);
}

static int	lstmap_to_asset(t_lstmap **tmp, char *root_path,
		t_asset_lst **asset_lst, t_sprite_lst **sprite_lst)
{
	t_key_value	kv;
	int			exit_code;
	int			id;

	id = 0;
	exit_code = SUCCESS;
	while (tmp != NULL && exit_code == SUCCESS && is_line_valid(tmp) != FAIL)
	{
		exit_code = set_key_value(&kv, (*tmp)->line, asset_lst);
		if (exit_code == SUCCESS)
			exit_code = set_asset_lst(&kv, root_path, asset_lst, id);
		if (exit_code != SUCCESS)
			break ;
		(*tmp)->line = NULL;
		if (kv.key != NULL && ft_strcmp(kv.key, "SP") == 0)
			exit_code = extract_coordinate_sprite(sprite_lst, tmp, id);
		else if (exit_code == SUCCESS)
			*tmp = (*tmp)->next;
		id++;
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
	if (exit_code == SUCCESS)
		exit_code = get_root_path(map_path, &root_path);
	if (exit_code == SUCCESS)
	{
		tmp = lst_map;
		exit_code = lstmap_to_asset(&tmp, root_path, asset_lst, sprite_lst);
	}
	if (exit_code == SUCCESS)
		exit_code = check_line_remain(map, asset_lst, &tmp);
	if (exit_code == SUCCESS)
		exit_code = lstmap_to_grid(map, &tmp);
	free(root_path);
	delete_all_lstmap(&lst_map);
	return (exit_code);
}
