/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:54:45 by aska              #+#    #+#             */
/*   Updated: 2024/09/27 18:01:08 by ygaiffie         ###   ########.fr       */
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
	if (x > map->max_x)
		map->max_x = x;
	map->max_y++;
	return (SUCCESS);
}

int	init_map_process(t_map *map, int fd)
{
	t_lstmap	*tmp;
	char		*line;
	t_bool		is_valid;

	is_valid = TRUE;
	tmp = map->lst_map;
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
				insert_end_lstmap(&map->lst_map, line);
			else
				is_valid = FALSE;
		}
		line = ft_char_f(line);
		line = get_next_line(fd);
	}
	return (SUCCESS);
}

int	set_var_creation_map(t_map *map_t)
{
	int	y;

	y = 0;
	map_t->map = ft_calloc(map_t->max_y + 1, sizeof(char *));
	if (map_t->map == NULL)
		return (ERROR);
	while (y != map_t->max_y)
	{
		map_t->map[y] = ft_calloc(map_t->max_x, sizeof(char));
		if (map_t->map[y++] == NULL)
			return (ERROR);
	}
	return (SUCCESS);
}

int	map_creation(t_map *map_t)
{
	int			x;
	int			y;
	int			i;
	t_lstmap	*tmp;

	y = 0;
	tmp = map_t->lst_map;
	while (y != map_t->max_y)
	{
		x = 0;
		i = 0;
		while (x != map_t->max_x)
		{
			if (tmp->line[i] != '\0')
			{
				map_t->map[y][x] = tmp->line[i];
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
