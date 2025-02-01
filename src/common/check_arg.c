/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 04:12:46 by aska              #+#    #+#             */
/*   Updated: 2025/02/01 17:14:43 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_arg.h"

int	check_entry_arg(int ac, char **av)
{
	char	*ext;
	char	*root_path;

	if (ac < 2)
		return (ft_return(ERROR, FAIL, "No arguments", NULL));
	ext = ft_strrchr(av[1], '.');
	if (ext == NULL || ft_strcmp(ext, ".cub") != 0)
		return (ft_return(ERROR, FAIL, "No \".cub\" extension file", av[1]));
	root_path = ft_strrchr(av[1], '/');
	if (root_path != NULL && root_path[1] == '.')
		return (ft_return(ERROR, FAIL, "No \".cub\" extension file", av[1]));
	return (SUCCESS);
}

int	check_line(char *line)
{
	if (line == NULL)
		return (ERROR);
	if (is_empty(line) == TRUE || is_map_valid(line) == FALSE)
		return (ft_return(ERROR, 272, "Invalid character on map", line));
	return (SUCCESS);
}

int	chk_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == FAIL)
	{
		close(fd);
		return (FAIL);
	}
	close(fd);
	return (SUCCESS);
}
