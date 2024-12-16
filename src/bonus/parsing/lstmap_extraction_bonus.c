/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:17:56 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/12/12 22:19:00 by aska             ###   ########.fr       */
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
		if (ft_isthis(line[i], " WNSEWTRL\n") == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_line_remain(t_map *map, t_lstmap **lst_map)
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
		exit_code = is_empty(tmp->line);
		if (exit_code != SUCCESS)
			break ;
		exit_code = !is_map_valid_bonus(tmp->line);
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
		map->grid[y] = tmp->line;
		if (map->grid[y] == NULL)
			return (ft_return(ERROR, 274, "Error on Map Creation"));
		tmp->line = NULL;
		tmp = tmp->next;
		y++;
	}
	return (SUCCESS);
}

int	extract_coordinate_sprite(t_sprite_lst **sprite_lst, t_lstmap **tmp, int id)
{
	*tmp = (*tmp)->next;
	while (tmp != NULL && (*tmp)->line[0] == '[')
	{
		if (set_sprite_coordinate((*tmp)->line, sprite_lst, id) == SUCCESS)
			*tmp = (*tmp)->next;
	}
	return (SUCCESS);
}

static int	is_newline_valid(t_lstmap **tmp)
{
	while (*tmp != NULL && is_empty((*tmp)->line) == TRUE)
		*tmp = (*tmp)->next;
	if (*tmp == NULL)
		return (FAIL);
	if (!ft_isthis((*tmp)->line[0], "NWESFCTLRH"))
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
	while (tmp != NULL)
	{
		if (is_newline_valid(tmp) == FAIL)
			break ;
		exit_code = set_key_value(&kv, (*tmp)->line);
		if (exit_code == SUCCESS)
			exit_code = set_asset_lst(&kv, root_path, asset_lst, id);
		else
			break ;
		if (ft_strcmp(kv.key, "SP") == 0)
			exit_code = extract_coordinate_sprite(sprite_lst, tmp, id);
		if (exit_code == SUCCESS)
		{
			(*tmp)->line = NULL;
			*tmp = (*tmp)->next;
		}
		id++;
	}
	return (exit_code);
}

int	lstmap_extract_info(t_map *map, char *map_path, t_asset_lst **asset_lst, t_sprite_lst **sprite_lst)
{
	t_lstmap	*tmp;
	t_lstmap	*lst_map;
	char		*root_path;
	int			exit_code;

	lst_map = NULL;
	exit_code = file_load(map_path, &lst_map);
	if (exit_code != SUCCESS)
		return (exit_code);
	tmp = lst_map;
	root_path = get_root_path(map_path);
	exit_code = lstmap_to_asset(&tmp, root_path, asset_lst, sprite_lst);
	root_path = ft_char_f(root_path);
	if (exit_code == SUCCESS)
		exit_code = check_line_remain(map, &tmp);
	if (exit_code == SUCCESS)
		exit_code = lstmap_to_grid(map, &tmp);
	delete_all_lstmap(&tmp);
	return (exit_code);
}
