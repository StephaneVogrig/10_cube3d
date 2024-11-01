/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_extraction_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:28:35 by aska              #+#    #+#             */
/*   Updated: 2024/11/01 18:10:37 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../debug.h"
#include "lstmap_extraction_utils.h"

int	check_line(char *line)
{
	if (line == NULL)
		return (ERROR);
	if (is_empty(line) == TRUE || is_map_valid(line) == FALSE)
		return (ft_return(ERROR, FAIL, "Invalid map"));
	return (SUCCESS);
}

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

int	attrib_path(t_textures *tex, t_key_value *kv, char *root_path)
{
	int	exit_code;
	int	fd;

	if (kv->key[0] == 'C')
		exit_code = attrib_rgb(&tex->ceil_rgb, kv->value);
	else if (kv->key[0] == 'F')
		exit_code = attrib_rgb(&tex->floor_rgb, kv->value);
	else
	{
		if (root_path != NULL)
			kv->value = ft_strjoin(root_path, kv->value);
		fd = ft_open(kv->value, O_RDONLY);
		if (fd == FAIL)
			return (ft_return(ERROR, 268, "Texture File Invalid"));
		exit_code = texture_selector(tex, kv->key, kv->value);
		ft_close(fd);
	}
	return (exit_code);
}

int	set_key_value(t_key_value *kv, char *line, t_fs *fs)
{
	int	exit_code;

	if (!ft_isthis(line[0], "NSEWFC"))
		return (ft_return(ERROR, 263, "Invalid Key"));
	exit_code = setup_key_value_separate_by_space(kv->key, kv->value, line);
	if (exit_code != SUCCESS)
		return (exit_code);
	remove_root_value(kv->value);
	exit_code = file_switch_select(fs, kv->key);
	return (exit_code);
}

int	set_map_info(t_map *map, char *line)
{
	int				x;
	int				i;
	static t_bool	player_valid = FALSE;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isthis(line[i++], "NSWE"))
		{
			if (player_valid == TRUE)
				return (ft_return(ERROR, FAIL, "Player on map Invalid"));
			player_valid = TRUE;
		}
	}
	x = 0;
	while (line[x])
		if (x++ == INT_MAX)
			return (FAIL);
	if (x > map->width)
		map->width = x;
	if (map->height == INT_MAX)
		return (FAIL);
	map->height++;
	return (SUCCESS);
}
