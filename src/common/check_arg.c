/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 04:12:46 by aska              #+#    #+#             */
/*   Updated: 2025/02/03 15:26:45 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_arg.h"

int	check_entry_arg(int ac, char **av)
{
	char	*map_path;

	if (ac < 2)
		return (ft_return(ERROR, FAIL, "Cub3D", "too few arguments"));
	if (ac > 2)
		return (ft_return(ERROR, FAIL, "Cub3D", "too many arguments"));
	map_path = ft_strrchr(av[1], '/');
	if (map_path != NULL)
		map_path++;
	else
		map_path = av[1];
	if (map_path[0] == '.')
		map_path++;
	map_path = ft_strrchr(map_path, '.');
	if (map_path == NULL || ft_strcmp(map_path, ".cub") != 0)
		return (ft_return(ERROR, FAIL, "No \".cub\" extension file", av[1]));
	return (SUCCESS);
}

int	check_line(char *line)
{
	if (is_empty(line) == TRUE || is_map_valid(line) == FALSE)
		return (ft_return(ERROR, FAIL, "Invalid character on map", line));
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
