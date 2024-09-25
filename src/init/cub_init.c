/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:28:35 by aska              #+#    #+#             */
/*   Updated: 2024/09/25 14:36:55 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../include/cub3d.h"

int	open_cub(int *fd, char *file)
{
	*fd = ft_open(file, O_RDONLY);
	if (*fd == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	check_arg_color(char **rgb)
{
	int	i;
	int	j;
	int	rgb_len;
	int	rgb_i;

	i = 0;
	while (rgb[i])
	{
		rgb_len = ft_strlen(rgb[i]);
		if (rgb_len > 10)
			return (FAIL);
		j = 0;
		while (rgb[i][j])
			if (ft_isdigit(rgb[i][j++] == 0))
				return (FAIL);
		rgb_i = ft_atoi(rgb[i]);
		if (rgb_len != ft_intlen(rgb_i, 0))
			return (FAIL);
		if (rgb_i < 0 || rgb_i > 255)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	attrib_rgb(t_rgb rgb, char *key, char *value)
{
	char	**arg;
	int ok;

	arg = ft_split(value, ',');
	if (arg == NULL || ft_tablen(arg) != 3)
		ok = FAIL;
	if (ok != FAIL && check_arg_color(arg) == FAIL)
		ok = FAIL;
	if (ok != FAIL)
	{
		rgb.r = ft_atoi(arg[0]);
		rgb.g = ft_atoi(arg[1]);
		rgb.b = ft_atoi(arg[2]);
	}
	ft_tab_f(arg);
	return (ok);
}

int	attrib_path(t_textures *tex, char *key, char *value)
{
	int ok;
	int		fd;

	fd = ft_open(value, O_RDONLY);
	if (fd != FAIL)
		ok = path_seletor(tex, key, value);
	else if (key[0] == 'C')
		ok = attrib_rgb(tex->ceil_rgb, key, value);
	else if (key[0] == 'F')
		ok = attrib_rgb(tex->floor_rgb, key, value);
	ft_close(fd);
	chk_box(ok, NE, FAIL, key);
	if (ok == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	img_path_process(char *key, char *value, char *line)
{
	int		ok;

	if (line == NULL)
		return (FAIL);
	if (ft_isthis(line[0], " 10\n\t"))
		return ;
	if (return_key(line, &key) == FAIL)
		return (FAIL);
	if (return_value(line, key, &value) == FAIL)
		return (FAIL);
	return (ok);
}

int	asset_discovery(void *mlx, t_textures *tex, int *fd)
{
	char	*line;
	int		sum_of_path;
	char	key;
	char	value;

	sum_of_path = 0;
	line = get_next_line(fd);
	while (line != NULL && sum_of_path < 6)
	{
		if (img_path_process(&key, &value, line) == FAIL)
			return (ft_return(ERROR, FAIL, "Error on path processing"));
		if (attrib_path(tex, &key, &value) == FAIL)
			return (ft_return(ERROR, FAIL, "Error on path Attribution"));
		line = ft_char_f(line);
		sum_of_path++;
		line = get_next_line(fd);
	}
	if (sum_of_path != 6)
		return (FAIL);
	return (SUCCESS);
}
