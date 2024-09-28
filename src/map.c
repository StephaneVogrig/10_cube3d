/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:54:45 by aska              #+#    #+#             */
/*   Updated: 2024/09/28 16:36:40 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "lst_map.h"
#include "map.h"

int	check_line(t_map *map, char *line)
{
	int	x;

	if (line == NULL)
		return (ERROR);
	if (is_empty_line(line) == TRUE || is_map_valid(line) == FALSE)
		return (ERROR);
	x = (int)ft_strlen(line) - 1; // -1 to remove the '\n' character
	if (x > map->width)
		map->width = x;
	map->height++;
	return (SUCCESS);
}

int	init_map_process(t_map *map, t_lstmap **lst_map, int fd)
{
	char	*line;
	t_bool	is_valid;

	is_valid = TRUE;
	line = get_next_line(fd);
	while (line != NULL && is_empty_line(line) == TRUE)
	{
		line = ft_char_f(line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		if (is_valid == TRUE)
		{
			if (check_line(map, line) == SUCCESS)
				insert_end_lstmap(lst_map, line);
			else
				is_valid = FALSE;
		}
		line = ft_char_f(line);
		line = get_next_line(fd);
	}
	return (SUCCESS);
}

int	set_var_creation_map(t_map *map)
{
	int	y;

	y = 0;
	map->grid = ft_calloc(map->width + 1, sizeof(char *));
	if (map->grid == NULL)
		return (ERROR);
	while (y != map->height)
	{
		map->grid[y] = ft_calloc(map->width, sizeof(char));
		if (map->grid[y++] == NULL)
			return (ERROR);
	}
	return (SUCCESS);
}

int	map_creation(t_map *map, t_lstmap **lst_map)
{
	int			x;
	int			y;
	int			i;
	t_lstmap	*tmp;

	y = 0;
	tmp = *lst_map;
	while (y != map->height)
	{
		x = 0;
		i = 0;
		while (x != map->width)
		{
			if (tmp->line[i] != '\0')
			{
				map->grid[y][x] = tmp->line[i];
				i = ++x;
			}
			else
				x++;
		}
		tmp = tmp->next;
		y++;
	}
	return (SUCCESS);
}
