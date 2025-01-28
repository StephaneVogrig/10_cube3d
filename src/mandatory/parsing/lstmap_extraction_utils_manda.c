/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils_manda.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:28:35 by aska              #+#    #+#             */
/*   Updated: 2025/01/28 16:12:01 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstmap_extraction_utils_manda.h"

static int	set_path_to_tex(char **tex_path_dest, char *value)
{
	*tex_path_dest = ft_strdup(value);
	if (*tex_path_dest == NULL)
		return (ft_return(ERROR, 268, "Texture path malloc failed"));
	return (SUCCESS);
}

int	set_path_by_key(t_tex_path *tex_path, t_key_value *kv)
{
	if (ft_strcmp(kv->key, "NO") == 0)
		return (set_path_to_tex(&tex_path->no, kv->value));
	if (ft_strcmp(kv->key, "SO") == 0)
		return (set_path_to_tex(&tex_path->so, kv->value));
	if (ft_strcmp(kv->key, "WE") == 0)
		return (set_path_to_tex(&tex_path->we, kv->value));
	if (ft_strcmp(kv->key, "EA") == 0)
		return (set_path_to_tex(&tex_path->ea, kv->value));
	return (ft_return(ERROR, 267, "Invalid Key"));
}

static int	set_path(char *root_path, t_key_value *kv, t_tex_path *tex_path)
{
	int	exit_code;
	int	fd;

	kv->value = ft_strtrim(kv->value, " ");
	if (kv->value != NULL && root_path != NULL)
		kv->value = ft_strjoin_f2(root_path, kv->value);
	if (kv->value == NULL)
		return (ft_return(ERROR, 268, "Texture path malloc failed"));
	fd = ft_open(kv->value, O_RDONLY);
	if (fd != FAIL)
		exit_code = set_path_by_key(tex_path, kv);
	else
		exit_code = ft_return(ERROR, 268, "Texture File Invalid");
	ft_close(fd);
	kv->value = ft_char_f(kv->value);
	return (exit_code);
}

int	set_path_and_color(t_tex_path *tex_path, t_textures *tex, t_key_value *kv,
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

int	set_key_value(t_key_value *kv, char *line, t_fs *fs)
{
	int		exit_code;

	exit_code = !ft_isthis(line[0], "NSEWFC");
	if (exit_code != SUCCESS)
		return (ft_return(ERROR, 263, "Invalid Key"));
	exit_code = setup_key_value_separate_by_space(&(kv->key), &(kv->value),
			line);
	if (exit_code != SUCCESS)
		return (exit_code);
	remove_root_value(kv->value);
	exit_code = file_switch_select(fs, kv->key);
	return (exit_code);
}
