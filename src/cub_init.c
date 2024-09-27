/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:28:35 by aska              #+#    #+#             */
/*   Updated: 2024/09/27 04:17:23 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

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
		rgb->r = ft_atoi(arg[0]);
		rgb->g = ft_atoi(arg[1]);
		rgb->b = ft_atoi(arg[2]);
	}
	ft_tab_f(arg);
	return (ok);
}

int	attrib_path(void *mlx, t_textures *tex, char *key, char *value)
{
	int	ok;
	int	fd;

	ok = SUCCESS;
	fd = ft_open(value, O_RDONLY);
	if (fd != FAIL)
		ok = path_seletor(mlx, tex, key, value);
	else if (key[0] == 'C')
		ok = attrib_rgb(&tex->ceil_rgb, value);
	else if (key[0] == 'F')
		ok = attrib_rgb(&tex->floor_rgb, value);
	ft_close(fd);
	chk_box(ok, NE, FAIL, key);
	if (ok == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	img_path_process(char **key, char **value, char *line)
{
	if (line == NULL)
		return (FAIL);
	if (!ft_isthis(line[0], "NSEWFC"))
		return (FAIL);
	if (setup_key(line, key) == FAIL)
		return (FAIL);
	if (setup_value(line, *key, value) == FAIL)
		return (FAIL);
	*value = ft_strtrim(*value, " ");
	if (*value == NULL)
		return (FAIL);
	return (SUCCESS);
}

int	file_process(void *mlx, t_textures *tex, int *fd)
{
	char	*line;
	int		sum_of_path;
	char	*key;
	char	*value;

	sum_of_path = 0;
	key = NULL;
	value = NULL;
	line = get_next_line(*fd);
	while (line != NULL && sum_of_path < 6)
	{
		if (img_path_process(&key, &value, line) == SUCCESS)
		{
			if (attrib_path(mlx, tex, key, value) == FAIL)
				return (ft_return(ERROR, FAIL, "Error on path Attribution"));
			sum_of_path++;
		}
		line = ft_char_f(line);
		if (sum_of_path != 6)
			line = get_next_line(*fd);
	}
	line = ft_char_f(line);
	if (sum_of_path != 6)
		return (FAIL);
	return (SUCCESS);
}
