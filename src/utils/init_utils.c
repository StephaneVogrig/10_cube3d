/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:35:07 by aska              #+#    #+#             */
/*   Updated: 2024/08/03 19:48:01 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../include/cub3d.h"

char	*path_seletor(t_cub *cub, char *key, char *img_path)
{
	if (ft_strncmp(key, "NO", 2) == 0)
		cub->img->no_path = ft_strdup(img_path);
	else if (ft_strncmp(key, "SO", 2) == 0)
		cub->img->so_path = ft_strdup(img_path);
	else if (ft_strncmp(key, "WE", 2) == 0)
		cub->img->we_path = ft_strdup(img_path);
	else if (ft_strncmp(key, "EA", 2) == 0)
		cub->img->ea_path = ft_strdup(img_path);
	else if (ft_strncmp(key, "F", 1) == 0)
		cub->img->f_path = ft_strdup(img_path);
	else if (ft_strncmp(key, "C", 1) == 0)
		cub->img->c_path = ft_strdup(img_path);
	else if (ft_strncmp(key, "BGM", 3) == 0)
		cub->img->bgm_path = ft_strdup(img_path);
	else
		return (NULL);
	return (img_path);
}

int	return_key(t_cub *cub, char *line, char **key)
{
	*key = ft_substr(line, 0, ft_strlen_endc(line, ' '));
	if (key == NULL)
		helltrain(cub, ERROR, 1, "key");
	return (SUCCESS);
}

int	return_value(t_cub *cub, char *line, char *key, char **value)
{
	int	key_len;

	key_len = ft_strlen(key);
	*value = ft_substr(line, key_len, ft_strlen_endc(line + key_len, '\n'));
	*value = ft_strtrim_f(*value, " ");
	*value = ft_strtrim_f(*value, "./");
	if (*value[0] != '/')
		*value = ft_strjoin_f2(cub->root_path, *value);
	if (value == NULL)
	{
		ft_free(key);
		helltrain(cub, ERROR, 1, "value");
	}
	return (SUCCESS);
}
