/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:28:35 by aska              #+#    #+#             */
/*   Updated: 2024/11/27 02:58:00 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstmap_extraction_utils_bonus.h"

int	set_color(t_color *rgb, char *value)
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

int	set_path_by_key(t_tex_path *tex_path, t_dictionarie *kv)
{
	int	key;

	key = get_index_by_key(kv->key[0]);
	if (key != FAIL)
	{
		tex_path->path[key] = ft_strdup(kv->value);
		if (tex_path->path[key] == NULL)
			return (ft_return(ERROR, 266, "Malloc Error"));
	}
	else
		return (ft_return(ERROR, 267, "Invalid Key"));
	return (SUCCESS);
}

int	set_path_and_color(t_tex_path *tex_path, t_dictionarie *kv, char *root_path)
{
	int	exit_code;
	int	fd;

	if (root_path != NULL)
		kv->value = ft_strjoin(root_path, kv->value);
	fd = ft_open(kv->value, O_RDONLY);
	if (fd == FAIL)
		return (ft_return(ERROR, 268, "Texture File Invalid"));
	ft_close(fd);
	exit_code = set_path_by_key(tex_path, kv);
	kv->value = ft_char_f(kv->value);
	return (exit_code);
}

int	set_dict_key_value(t_dictionarie *kv, char *line)
{
	int	exit_code;

	// printf("line = %s\n", line);
	exit_code = !ft_isthis(line[0], "123456789FCTLRH");
	if (exit_code != SUCCESS)
		return (ft_return(ERROR, 263, "Invalid Key"));
	exit_code = setup_key_value_separate_by_space(&(kv->key), &(kv->value),
			line);
	if (exit_code != SUCCESS)
		return (exit_code);
	remove_root_value(kv->value);
	return (exit_code);
}
