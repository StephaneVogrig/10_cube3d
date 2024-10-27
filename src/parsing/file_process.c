/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:28:35 by aska              #+#    #+#             */
/*   Updated: 2024/10/27 15:12:32 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../debug.h"
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

void	replace_eol_to_nul(char *str)
{
	while (*str != 0)
	{
		if (*str == '\n')
			*str = 0;
		str++;
	}
}

int	file_to_lst_map(int fd, t_lstmap **lst_map)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		replace_eol_to_nul(line);
		if (insert_end_lstmap(lst_map, line) == NULL)
		{
			delete_all_lstmap(lst_map);
			line = ft_char_f(line);
			chk_box(1, EQ, 0, "Reading File");
			return (ft_return(ERROR, FAIL, MSG_LSTMAP_ERROR));
		}
		line = get_next_line(fd);
	}
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

int	attrib_path(t_textures *tex, char *key, char *value, char *root_path)
{
	int	ok;
	int	fd;

	ok = SUCCESS;
	if (key[0] == 'C')
		ok = attrib_rgb(&tex->ceil_rgb, value);
	else if (key[0] == 'F')
		ok = attrib_rgb(&tex->floor_rgb, value);
	else
	{
		if (root_path != NULL)
			value = ft_strjoin(root_path, value);
		fd = ft_open(value, O_RDONLY);
		if (fd == FAIL)
			return (FAIL);
		ok = texture_selector(tex, key, value);
		ft_close(fd);
	}
	chk_box(ok, NE, FAIL, value);
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
	if (is_empty(line) == TRUE)
		return (FAIL);
	if (!ft_isthis(line[0], "NSEWFC"))
		return (FAIL);
	if (setup_key_value(key, value, line, ' ') == FAIL)
		return (FAIL);
	if (file_switch_checker(fs, key) == 0)
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

int	lstmap_to_textures(t_textures *tex, t_lstmap **lst_map, char *root_path)
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
			if (attrib_path(tex, key, value, root_path) == SUCCESS)
				file_switch_key(&fs, &key);
		}
		tmp->line = ft_char_f(tmp->line);
		delete_node_lstmap(lst_map, tmp);
		tmp = *lst_map;
		if (fs.file_ok == 0)
			return (SUCCESS);
	}
	return (ft_return(ERROR, FAIL, "File Invalid 1"));
}
