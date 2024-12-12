/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:28:35 by aska              #+#    #+#             */
/*   Updated: 2024/12/12 22:39:21 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstmap_extraction_utils_bonus.h"

int	attrib_rgb(t_rgb *rgb, char *value)
{
	char	**arg;
	int		ok;

	ok = SUCCESS;
	arg = ft_split(value, ',');
	if (arg == NULL || ft_tablen(arg) != 3)
		ok = FAIL;
	if (ok != FAIL && check_arg_color(arg) == FAIL)
		ok = FAIL;
	if (ok != FAIL)
	{
		rgb->a = (unsigned char)255;
		rgb->r = (unsigned char)ft_atoi(arg[0]);
		rgb->g = (unsigned char)ft_atoi(arg[1]);
		rgb->b = (unsigned char)ft_atoi(arg[2]);
	}
	ft_tab_f(arg);
	return (ok);
}

int	add_to_asset_lst(t_key_value *kv, t_asset_lst *asset_lst, int id)
{
	(void)asset_lst;
	// traitements asset
	
	if (key != FAIL)
	{
		tex_path->path[key] = ft_strdup(kv->value);
		if (tex_path->path[key] == NULL)
			return (ft_return(ERROR, 9, "L.46:add_to_asset_lst: Malloc Error"));
	}
	else
		return (ft_return(ERROR, 10, "L.49:add_to_asset_lst: Invalid Key"));
	return (SUCCESS);
}

int	set_asset_lst(t_key_value *kv, char *root_path, t_asset_lst *asset_lst,
		int id)
{
	int	exit_code;
	int	fd;

	if (root_path != NULL)
		kv->value = ft_strjoin(root_path, kv->value);
	fd = ft_open(kv->value, O_RDONLY);
	if (fd == FAIL)
	{
		kv->value = ft_char_f(kv->value);
		return (ft_return(ERROR, 8, "L.67:set_asset_lst: open failed"));
	}
	ft_close(fd);
	exit_code = add_to_asset_lst(kv, asset_lst, id);
	kv->value = ft_char_f(kv->value);
	return (exit_code);
}

int	set_key_value(t_key_value *kv, char *line)
{
	if (setup_key_value_separate_by_space(&(kv->key), &(kv->value),
			line) != SUCCESS)
		return (FAIL);
	remove_root_value(kv->value);
	return (SUCCESS);
}
