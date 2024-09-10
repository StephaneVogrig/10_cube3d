/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:28:35 by aska              #+#    #+#             */
/*   Updated: 2024/09/07 14:58:04 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../include/cub3d.h"

int	open_cub(t_cub *cub, char *file)
{
	cub->fd = ft_open(file, O_RDONLY);
	if (cub->fd == FAIL)
		return (FAIL);
	cub->root_path = ft_substr(file, 0, ft_strrchr(file, '/') - file + 1);
	if (cub->root_path == NULL)
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

int	attrib_path(t_cub *cub, char *key, char *value)
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

void	img_path_process(t_cub *cub, char *line)
{
	char	*key;
	char	*value;

	if (ft_isthis(line[0], " 10\n"))
		return ;
	key = NULL;
	value = NULL;
	return_key(cub, line, &key);
	return_value(cub, line, key, &value);
	cub->err = attrib_path(cub, key, value);
	value = ft_char_f(value);
	key = ft_char_f(key);
	if (cub->err == FAIL)
		return ;
}

int	asset_discovery(t_cub *cub)
{
	char	*line;

	cub->img = ft_calloc(1, sizeof(t_img));
	if (cub->img == NULL)
		return (FAIL);
	line = get_next_line(cub->fd);
	while (line != NULL)
	{
		if (cub->err != FAIL && cub->img->path_ok <= 5)
			img_path_process(cub, line);
		else if (cub->err != FAIL)
			insert_end_lstmap(&cub->map, ft_strdup(line));
		line = ft_char_f(line);
		line = get_next_line(cub->fd);
	}
	if (cub->err == FAIL)
		helltrain(cub, ERROR, 1, "Problem with asset");
	if (cub->img->path_ok < 6)
		return (FAIL);
	return (SUCCESS);
}
