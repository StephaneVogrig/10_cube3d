/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:38:38 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/12/11 02:51:31 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_load.h"

int	open_file(int *fd, char *file)
{
	*fd = ft_open(file, O_RDONLY);
	if (*fd == FAIL)
		return (ft_return(ERROR, 5, MSG_OPEN_ERROR));
	return (SUCCESS);
}

int	close_file(int *fd)
{
	*fd = ft_close(*fd);
	if (*fd == FAIL)
		return (ft_return(ERROR, 7, MSG_CLOSE_ERROR));
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
			return (ft_return(ERROR, 6, "L.53:file_to_lst_map: Error to insert in lst_map"));
		}
		line = get_next_line(fd);
	}
	return (SUCCESS);
}

int	file_load(char *path, t_lstmap **lst_map)
{
	int fd;
	int exit_code;
	exit_code = open_file(&fd, path);
	if (exit_code != SUCCESS)
		return (exit_code);
	exit_code = file_to_lst_map(fd, lst_map);
	exit_code |= close_file(&fd);
	return (exit_code);
}