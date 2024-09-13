/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:28:35 by aska              #+#    #+#             */
/*   Updated: 2024/09/13 16:38:56 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	open_cub(int *fd, char *file, char *root_path)
{
	*fd = ft_open(file, O_RDONLY);
	if (*fd == FAIL)
		return (FAIL);
	root_path = ft_substr(file, 0, ft_strrchr(file, '/') - file + 1);
	if (root_path == NULL)
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

int	attrib_rgb(t_cub *cub, char *key, char *data)
{
	char	**rgb;

	rgb = ft_split(data, ',');
	if (rgb == NULL || ft_tablen(rgb) != 3)
		cub->err = FAIL;
	if (cub->err != FAIL && check_arg_color(rgb) == FAIL)
		cub->err = FAIL;
	if (cub->err != FAIL && ft_strcmp(key, "C") == 0)
	{
		cub->img->c_rgb.r = ft_atoi(rgb[0]);
		cub->img->c_rgb.g = ft_atoi(rgb[1]);
		cub->img->c_rgb.b = ft_atoi(rgb[2]);
	}
	else if (cub->err != FAIL && ft_strcmp(key, "F") == 0)
	{
		cub->img->f_rgb.r = ft_atoi(rgb[0]);
		cub->img->f_rgb.g = ft_atoi(rgb[1]);
		cub->img->f_rgb.b = ft_atoi(rgb[2]);
	}
	ft_tab_f(rgb);
	return (cub->err);
}

int	attrib_path(t_texture *tex, char *key, char *value)
{
	int		fd;
	char	*data;

	fd = ft_open(value, O_RDONLY);
	if (fd != FAIL)
		path_seletor(cub, key, value);
	else
	{
		data = ft_strdup(value + ft_strlen(cub->root_path));
		cub->err = attrib_rgb(cub, key, data);
		data = ft_char_f(data);
	}
	ft_close(fd);
	chk_box(cub->err, NE, FAIL, value + ft_strlen(cub->root_path));
	if (cub->err == FAIL)
		return (FAIL);
	cub->img->path_ok++;
	return (SUCCESS);
}

int	img_path_process(t_textures *tex, char *line, int *sum_of_path)
{
	char	*key;
	char	*value;
	int		ok;

	ok = 0;
	if (ft_isthis(line[0], " 10\n\t"))
		return ;
	key = NULL;
	value = NULL;
	return_key(line, &key);
	return_value(line, key, &value);
	ok = attrib_path(key, value, tex);
	if (ok == SUCCESS)
		*sum_of_path++;
	value = ft_char_f(value);
	key = ft_char_f(key);
	return (ok);
}

int	asset_discovery(t_textures *tex, int *fd)
{
	char	*line;
	int		ok;
	int		sum_of_path;

	ok = 0;
	sum_of_path = 0;
	line = get_next_line(fd);
	while (line != NULL && sum_of_path < 6)
	{
		ok = img_path_process(tex, line, &sum_of_path);
		line = ft_char_f(line);
		if (ok == FAIL)
			return (ft_return(ERROR, FAIL, "Error on asset discovery"));
		line = get_next_line(fd);
	}
	if (sum_of_path != 6)
		return (FAIL);
	return (SUCCESS);
}
