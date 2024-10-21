/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:28:35 by aska              #+#    #+#             */
/*   Updated: 2024/10/21 12:31:20 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_process.h"

int	open_file(int *fd, char *file)
{
	*fd = ft_open(file, O_RDONLY);
	chk_box(*fd, NE, FAIL, file);
	if (*fd == FAIL)
		return (ft_return(ERROR, FAIL, MSG_OPEN_ERROR));
	return (SUCCESS);
}

int	close_file(int *fd)
{
	*fd = ft_close(*fd);
	chk_box(*fd, EQ, SUCCESS, "Close File");
	if (*fd == FAIL)
		return (ft_return(ERROR, FAIL, MSG_CLOSE_ERROR));
	return (SUCCESS);
}

int	file_to_lst_map(int fd, t_lstmap **lst_map)
{
	char		*line;
	t_lstmap	*tmp;

	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = insert_end_lstmap(lst_map, ft_substr(line, 0, ft_strlen_endc(line,
						'\n')));
		if (tmp == NULL)
		{
			delete_all_lstmap(lst_map);
			line = ft_char_f(line);
			chk_box(1, EQ, 0, "Reading File");
			return (ft_return(ERROR, FAIL, MSG_LSTMAP_ERROR));
		}
		line = gnl_f(fd, line);
	}
	line = ft_char_f(line);
	chk_box(0, EQ, 0, "Reading File");
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

int	attrib_path(void *mlx, t_textures *tex, char *key, char *value)
{
	int	ok;
	int	fd;

	ok = SUCCESS;
	fd = ft_open(value, O_RDONLY);
	if (key[0] == 'C')
		ok = attrib_rgb(&tex->ceil_rgb, value);
	else if (key[0] == 'F')
		ok = attrib_rgb(&tex->floor_rgb, value);
	else if (fd != FAIL)
		ok = path_seletor(mlx, tex, key, value);
	ft_close(fd);
	chk_box(ok, NE, FAIL, value);
	value = ft_char_f(value);
	if (ok == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	file_switch_checker(t_fs *fs, char **key)
{
	if (ft_strcmp(*key, "NO") == 0)
		return (fs->no);
	else if (ft_strcmp(*key, "SO") == 0)
		return (fs->so);
	else if (ft_strcmp(*key, "WE") == 0)
		return (fs->we);
	else if (ft_strcmp(*key, "EA") == 0)
		return (fs->ea);
	else if (ft_strcmp(*key, "F") == 0)
		return (fs->f);
	else if (ft_strcmp(*key, "C") == 0)
		return (fs->c);
	return (FAIL);
}

int	get_key_value(char **key, char **value, char *line, t_fs *fs)
{
	if (line == NULL)
		return (FAIL);
	if (is_empty_line(line) == TRUE)
		return (FAIL);
	if (!ft_isthis(line[0], "NSEWFC"))
		return (FAIL);
	if (setup_key(line, key) == FAIL)
		return (FAIL);
	if (file_switch_checker(fs, key) == 0)
		return (FAIL);
	if (setup_value(line, *key, value) == FAIL)
		return (FAIL);
	*value = ft_strtrim_f(*value, " ");
	if (*value == NULL)
		return (FAIL);
	return (SUCCESS);
}

void	file_switch_key(t_fs *fs, char **key)
{
	if (ft_strcmp(*key, "NO") == 0)
		fs->no = 0;
	else if (ft_strcmp(*key, "SO") == 0)
		fs->so = 0;
	else if (ft_strcmp(*key, "WE") == 0)
		fs->we = 0;
	else if (ft_strcmp(*key, "EA") == 0)
		fs->ea = 0;
	else if (ft_strcmp(*key, "F") == 0)
		fs->f = 0;
	else if (ft_strcmp(*key, "C") == 0)
		fs->c = 0;
}

int	file_process(void *mlx, t_textures *tex, t_lstmap **lst_map)
{
	t_fs		fs;
	char		*key;
	char		*value;
	t_lstmap	*tmp;

	fs.file_ok = 0x3F;
	key = NULL;
	value = NULL;
	tmp = *lst_map;
	while (tmp != NULL)
	{
		if (get_key_value(&key, &value, tmp->line, &fs) == SUCCESS)
		{
			attrib_path(mlx, tex, key, value);
			file_switch_key(&fs, &key);
		}
		key = ft_char_f(key);
		delete_lstmap(lst_map, tmp);
		tmp = *lst_map;
		if (fs.file_ok == 0)
			return (SUCCESS);
	}
	return (ft_return(ERROR, FAIL, "File Invalid"));
}
