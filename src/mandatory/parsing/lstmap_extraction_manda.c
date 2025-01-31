/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_manda.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:17:56 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/01/31 16:31:00 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstmap_extraction_manda.h"

static int	set_path_and_color(t_tex_path *tex_path, t_textures *tex, t_key_value *kv,
		char *root_path)
{
	int	exit_code;

	if (kv->key[0] == 'C')
		exit_code = color_set_rgb(&tex->ceil_rgb, kv->value);
	else if (kv->key[0] == 'F')
		exit_code = color_set_rgb(&tex->floor_rgb, kv->value);
	else
		exit_code = set_path(root_path, kv, tex_path);
	return (exit_code);
}

static t_status	chk_key_value(t_key_value *kv, char *line, t_fs *fs)
{
	if (!ft_isthis(line[0], "NSEWFC") != SUCCESS)
		return (ft_return(ERROR, 263, "Invalid Key", line));
	remove_root_value(kv->value);
	if (file_switch_select(fs, kv->key) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}

static int	check_line_remain(t_map *map, t_lstmap **lst_map)
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

static int	lstmap_to_textures(t_tex_path *tex_path, t_textures *tex,
		t_lstmap **lst_map, char *root_path)
{
	t_fs		fs;
	t_key_value	kv;
	int			exit_code;

	fs.file_ok = 0x3F;
	while (*lst_map != NULL)
	{
		while (is_empty((*lst_map)->line) == TRUE)
			delete_node_lstmap(lst_map, *lst_map);
		exit_code = set_key_value(&kv, (*lst_map)->line);
		if (exit_code == SUCCESS)
			exit_code = chk_key_value(&kv, (*lst_map)->line, &fs);
		if (exit_code == SUCCESS)
			exit_code = set_path_and_color(tex_path, tex, &kv, root_path);
		if (exit_code != SUCCESS)
			break ;
		file_switch_key(&fs, &kv.key);
		delete_node_lstmap(lst_map, *lst_map);
		if (fs.file_ok == 0)
			return (exit_code);
	}
	return (exit_code);
}

int	lstmap_extract_info(t_textures *textures, t_map *map, t_tex_path *tex_path,
		char *map_path)
{
	t_lstmap	*lst_map;
	int			ok;
	char		*root_path;

	root_path = NULL;
	lst_map = NULL;
	ok = file_load(map_path, &lst_map);
	if (ok == SUCCESS)
	{
		if (lst_map == NULL)
			ok = ft_return(ERROR, FAIL, "No data in map", NULL);
		if (ok == SUCCESS)
			ok = get_root_path(map_path, &root_path);
		if (ok == SUCCESS)
			ok = lstmap_to_textures(tex_path, textures, &lst_map, root_path);
		free(root_path);
		if (ok == SUCCESS)
			ok = check_line_remain(map, &lst_map);
		if (ok == SUCCESS)
			ok = lstmap_to_grid(map, &lst_map);
	}
	delete_all_lstmap(&lst_map);
	return (ok);
}
