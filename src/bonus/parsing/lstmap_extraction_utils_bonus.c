/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:28:35 by aska              #+#    #+#             */
/*   Updated: 2024/12/19 16:21:52 by aska             ###   ########.fr       */
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

int	set_asset_lst(t_key_value *kv, char *root_path, t_asset_lst **asset_lst, int id)
{
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
