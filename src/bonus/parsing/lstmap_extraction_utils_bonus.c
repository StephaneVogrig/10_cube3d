/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:28:35 by aska              #+#    #+#             */
/*   Updated: 2025/01/03 15:52:00 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstmap_extraction_utils_bonus.h"

int	set_asset_lst(t_key_value *kv, char *root_path, t_asset_lst **asset_lst, int id)
{
	int	fd;
	char *tmp;

	if (ft_strrchr(kv->value, '.') == NULL)
	{
		tmp = ft_strdup(kv->value);
		if (tmp == NULL)
			return (ft_return(ERROR, 8, "Malloc of path failed"));
		insert_asset_lst(asset_lst, kv->key, tmp, id);
		return (SUCCESS);
	}
	if (root_path != NULL)
		kv->value = ft_strjoin(root_path, kv->value);
	fd = ft_open(kv->value, O_RDONLY);
	if (fd == FAIL)
	{
		kv->key = ft_char_f(kv->key);
		kv->value = ft_char_f(kv->value);
		return (ft_return(ERROR, 8, "L.67:set_asset_lst: open failed"));
	}
	ft_close(fd);
	insert_asset_lst(asset_lst, kv->key, kv->value, id);
	return (SUCCESS);
}

int	set_key_value(t_key_value *kv, char *line)
{
	if (setup_key_value_separate_by_space(&(kv->key), &(kv->value),
			line) != SUCCESS)
		return (FAIL);
	remove_root_value(kv->value);
	return (SUCCESS);
}
