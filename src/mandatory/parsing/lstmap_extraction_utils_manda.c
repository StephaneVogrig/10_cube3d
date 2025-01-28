/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils_manda.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:28:35 by aska              #+#    #+#             */
/*   Updated: 2025/01/28 14:25:48 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstmap_extraction_utils_manda.h"

int	set_rgb(t_rgb *rgb, char *value)
{
	char	**arg;

	arg = ft_split(value, ',');
	if (arg == NULL || ft_tablen(arg) != 3)
	{
		ft_tab_f(arg);
		return (ft_return(ERROR, 266, "Invalid Color"));
	}
	if (is_valid_color(arg[0]) == FALSE || is_valid_color(arg[1]) == FALSE
		|| is_valid_color(arg[2]) == FALSE)
	{
		ft_tab_f(arg);
		return (ft_return(ERROR, 266, "Invalid Color"));
	}
	rgb->r = (unsigned char)ft_atoi(arg[0]);
	rgb->g = (unsigned char)ft_atoi(arg[1]);
	rgb->b = (unsigned char)ft_atoi(arg[2]);
	rgb->a = (unsigned char)255;
	ft_tab_f(arg);
	return (SUCCESS);
}

int	set_path_by_key(t_tex_path *tex_path, t_key_value *kv)
{
	if (ft_strcmp(kv->key, "NO") == 0)
		tex_path->no = ft_strdup(kv->value);
	else if (ft_strcmp(kv->key, "SO") == 0)
		tex_path->so = ft_strdup(kv->value);
	else if (ft_strcmp(kv->key, "WE") == 0)
		tex_path->we = ft_strdup(kv->value);
	else if (ft_strcmp(kv->key, "EA") == 0)
		tex_path->ea = ft_strdup(kv->value);
	else
		return (ft_return(ERROR, 267, "Invalid Key"));
	if (tex_path->no == NULL || tex_path->so == NULL || tex_path->we == NULL
		|| tex_path->ea == NULL)
		return (ft_return(ERROR, 268, "Texture path malloc failed"));
	return (SUCCESS);
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
		exit_code = set_rgb(&tex->ceil_rgb, kv->value);
	else if (kv->key[0] == 'F')
		exit_code = set_rgb(&tex->floor_rgb, kv->value);
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
