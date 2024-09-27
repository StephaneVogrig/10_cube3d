/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:54:45 by aska              #+#    #+#             */
/*   Updated: 2024/09/27 04:32:46 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"
#include "lst_map.h"
#include "map.h"

int	init_map_process(t_map *map, int fd)
{
	t_lstmap	*tmp;
	char		*line;

	tmp = map->lst_map;
	line = get_next_line(fd);
	while (line != NULL)
	{
		insert_end_lstmap(&map->lst_map, line);
		line = ft_char_f(line);
		line = get_next_line(fd);
	}
	while (is_empty_line(tmp->line) == TRUE && tmp != NULL)
	{
		tmp = tmp->next;
		delete_lstmap(&map->lst_map, tmp->prev);
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (is_map_valid(tmp->line) == FALSE
			|| is_empty_line(tmp->line) == TRUE)
			return (ERROR);
	}
	return (SUCCESS);
}

int	set_var_creation_map(t_map *map)
{
	int	y;

	y = 0;
	map->map_tab = ft_calloc(map->map_max_y + 1, sizeof(char *));
	if (map->map_tab == NULL)
		return (ERROR);
	while (y != map->map_max_y)
	{
		map->map_tab[y] = ft_calloc(map->map_max_x, sizeof(char));
		if (map->map_tab[y++] == NULL)
			return (ERROR);
	}
	return (SUCCESS);
}

int	map_creation(t_cub *cube)
{
	int x;
	int y;
	int i;
	t_lstmap *tmp;

	y = 0;
	tmp = cube->map;
	while (y != cube->map_max_y)
	{
		x = 0;
		i = 0;
		while (x != cube->map_max_x - 2)
		{
			if (tmp->line[i] != '\0')
			{
				cube->map_tab[y][x] = tmp->line[i];
				i = ++x;
			}
			else
				cube->map_tab[y][x++] = MEDIUM_BLOK;
		}
		tmp = tmp->next;
		y++;
	}
	return (SUCCESS);
}