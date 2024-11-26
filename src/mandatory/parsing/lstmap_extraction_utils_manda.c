/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils_manda.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:28:35 by aska              #+#    #+#             */
/*   Updated: 2024/11/26 16:40:17 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstmap_extraction_utils_manda.h"

t_color	*set_color(char *value)
{
	char	**arg;
	t_color	*argb;

	argb = NULL;
	arg = ft_split(value, ',');
	if (arg == NULL || ft_tablen(arg) != 3)
		return (NULL);
	if (check_arg_color(arg) == FAIL)
		return (NULL);
	argb->a = (unsigned char)255;
	argb->r = (unsigned char)ft_atoi(arg[0]);
	argb->g = (unsigned char)ft_atoi(arg[1]);
	argb->b = (unsigned char)ft_atoi(arg[2]);
	ft_tab_f(arg);
	return (argb);
}

int	set_path_and_color(t_assets *tex, t_dictionaries *kv, char *root_path)
{
	int	exit_code;
	int	fd;

	if (kv->key[0] == 'C' || kv->key[0] == 'F')
	{
		exit_code = dict_insert(&tex->textures, kv->key,
				(t_color *)set_color(kv->value));
		if (exit_code == FAIL)
			return (ft_return(ERROR, 268, "Color Invalid"));
	}
	else
	{
		if (root_path != NULL)
			kv->value = ft_strjoin(root_path, kv->value);
		fd = ft_open(kv->value, O_RDONLY);
		if (fd == FAIL)
			return (ft_return(ERROR, 268, "Texture File Invalid"));
		ft_close(fd);
		exit_code = dict_insert(&tex->textures, kv->key, (char *)kv->value);
		kv->value = ft_char_f(kv->value);
	}
	return (exit_code);
}

int	set_dict_key_value(t_dictionaries *kv, char *line, t_fs *fs)
{
	int	exit_code;

	exit_code = !ft_isthis(line[0], "NSEWFC");
	if (exit_code != SUCCESS)
		return (ft_return(ERROR, 263, "Invalid Key"));
	exit_code = setup_key_value_separate_by_space(&(kv->key), (char**)&(kv->value),
			line);
	if (exit_code != SUCCESS)
		return (exit_code);
	remove_root_value(kv->value);
	exit_code = file_switch_select(fs, kv->key);
	return (exit_code);
}
