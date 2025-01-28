/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:28:35 by aska              #+#    #+#             */
/*   Updated: 2025/01/28 14:53:36 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstmap_extraction_utils_bonus.h"

int	get_root_path(char *map_path, char **root_path)
{
	*root_path = ft_strrchr(map_path, '/');
	if (*root_path != NULL)
	{
		*root_path = ft_substr(map_path, 0, *root_path - map_path + 1);
		if (*root_path == NULL)
			return (ft_return(ERROR, 3, "get_root_path: malloc error"));
	}
	else
	{
		*root_path = ft_strdup("./");
		if (*root_path == NULL)
			return (ft_return(ERROR, 3, "get_root_path: malloc error"));
	}
	return (SUCCESS);
}

static int	open_failed_freed(char *value)
{
	ft_putstr_fd(BRED "ERROR" CRESET, 2);
	ft_putstr_fd("\t: open failure: " YEL, 2);
	ft_putstr_fd(value, 2);
	ft_putstr_fd(CRESET "\n", 2);
	return (8);
}

int	set_asset_lst(t_key_value *kv, char *root_path, t_asset_lst **asset_lst,
		int id)
{
	int	fd;

	kv->value = ft_strtrim(kv->value, " ");
	if (kv->value != NULL && ft_strrchr(kv->value, '.') == NULL)
	{
		if (insert_asset_lst(asset_lst, kv->key, ft_strdup(kv->value),
				id) == NULL)
			return (ft_return(ERROR, 8, "set_asset_lst: Malloc asset failed"));
		return (SUCCESS);
	}
	if (kv->value != NULL && root_path != NULL)
		kv->value = ft_strjoin_f2(root_path, kv->value);
	if (kv->value == NULL)
		return (ft_return(ERROR, 8, "set_asset_lst: Malloc asset path failed"));
	fd = open(kv->value, O_RDONLY);
	if (fd == FAIL)
	{
		kv->value = ft_char_f(kv->value);
		return (open_failed_freed(kv->key));
	}
	close(fd);
	if (insert_asset_lst(asset_lst, kv->key, kv->value, id) == NULL)
		return (ft_return(ERROR, 8, "set_asset_lst: Insert asset failed"));
	return (SUCCESS);
}

int	chk_key(char *key)
{
	if (key[0] == 'N' && ft_strcmp(key, "NO") != 0)
		return (ft_return(ERROR, FAIL, "chk_key: invalid key NO"));
	else if (key[0] == 'S')
	{
		if (ft_strcmp(key, "SO") != 0 && ft_strcmp(key, "SP") != 0)
			return (ft_return(ERROR, FAIL, "chk_key: invalid key SO or SP"));
	}
	else if (key[0] == 'E' && ft_strcmp(key, "EA") != 0)
		return (ft_return(ERROR, FAIL, "chk_key: invalid key EA"));
	else if (ft_isthis(key[0], "FC") == TRUE && key[1] != '\0')
		return (ft_return(ERROR, FAIL, "chk_key: invalid key Floor or Ceil"));
	else if (ft_isthis(key[0], "RLT") == TRUE)
	{
		if (key[1] == '\0' || key[1] == 'E')
			return (SUCCESS);
		return (ft_return(ERROR, FAIL, "chk_key: invalid key Door RLT"));
	}
	else if (key[0] == 'W' && ft_isthis(key[1], "E123456789") != TRUE)
		return (ft_return(ERROR, FAIL, "chk_key: invalid key W"));
	return (SUCCESS);
}

int	set_key_value(t_key_value *kv, char *line, t_asset_lst **asset_lst)
{
	if (setup_key_value_separate_by_space(&(kv->key), &(kv->value),
			line) != SUCCESS)
		return (FAIL);
	if (chk_key(kv->key) == FAIL)
		return (FAIL);
	if (ft_strcmp(kv->key, "SP") != 0 && asset_lst_key_in_list(*asset_lst,
			kv->key) == TRUE)
		return (ft_return(ERROR, FAIL, "set_key_value: key already exist"));
	remove_root_value(kv->value);
	return (SUCCESS);
}
