/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_path_manda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:05:27 by aska              #+#    #+#             */
/*   Updated: 2025/02/04 16:55:59 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tex_path_manda.h"

void	tex_path_clean(t_tex_path *tex_path)
{
	tex_path->no = ft_char_f(tex_path->no);
	tex_path->so = ft_char_f(tex_path->so);
	tex_path->we = ft_char_f(tex_path->we);
	tex_path->ea = ft_char_f(tex_path->ea);
}

static int	set_path_to_tex(char **tex_path_dest, char *value)
{
	*tex_path_dest = ft_strdup(value);
	if (*tex_path_dest == NULL)
		return (ft_return(ERROR, FAIL, "malloc failed", "set_path_to_tex"));
	return (SUCCESS);
}

static int	set_path_by_key(t_tex_path *tex_path, t_key_value *kv)
{
	if (ft_strcmp(kv->key, "NO") == 0)
		return (set_path_to_tex(&tex_path->no, kv->value));
	if (ft_strcmp(kv->key, "SO") == 0)
		return (set_path_to_tex(&tex_path->so, kv->value));
	if (ft_strcmp(kv->key, "WE") == 0)
		return (set_path_to_tex(&tex_path->we, kv->value));
	if (ft_strcmp(kv->key, "EA") == 0)
		return (set_path_to_tex(&tex_path->ea, kv->value));
	return (ft_return(ERROR, FAIL, "Invalid Key", kv->key));
}

int	set_path(char *root_path, t_key_value *kv, t_tex_path *tex_path)
{
	int		exit_code;
	bool	is_malloc;

	exit_code = SUCCESS;
	is_malloc = false;
	kv->value = spacetrim(kv->value);
	if (root_path != NULL)
	{
		kv->value = ft_strjoin(root_path, kv->value);
		is_malloc = true;
	}
	if (kv->value == NULL)
		return (ft_return(ERROR, FAIL, "malloc failed", "set_path"));
	if (is_folder(kv->value) == TRUE)
		exit_code = ft_return(ERROR, FAIL, kv->value, "is a folder");
	if (exit_code == SUCCESS && chk_open(kv->value) == FAIL)
		exit_code = ft_return(ERROR, FAIL, "failed to open asset", kv->key);
	if (exit_code != FAIL)
		exit_code = set_path_by_key(tex_path, kv);
	if (is_malloc)
		kv->value = ft_char_f(kv->value);
	return (exit_code);
}
