/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:54:45 by aska              #+#    #+#             */
/*   Updated: 2024/09/29 10:05:47 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "file_process.h"
#include "lst_map.h"
#include "map.h"


int	check_line(t_map *map, char *line)
{
	int	x;
	int i;
	static t_bool player_valid = FALSE;

	if (line == NULL)
		return (ERROR);
	if (is_empty_line(line) == TRUE || is_map_valid(line) == FALSE)
		return (ft_return(ERROR, ERROR, "Invalid map"));
	i =0;
	while (line[i] != '\0')
	{
		if (ft_isthis(line[i++], "NSWE"))
		{
			if (player_valid == TRUE)
				return (ft_return(ERROR, ERROR, "Player on map Invalid"));
			player_valid = TRUE;
		}
	}
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
				insert_end_lstmap(lst_map, ft_substr(line, 0, ft_strlen(line) - 1));
			else
				is_valid = FALSE;
		}
		line = ft_char_f(line);
		line = get_next_line(fd);
	}
	if (is_valid == FALSE)
		return (ERROR);
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
	print_tab(map->grid);
	return (SUCCESS);
}

// int	map_setup(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	map->grid = malloc(9 * sizeof(map));
// 	if (map == NULL)
// 	{
// 		printf("map_setup failed\n");
// 		return (FAIL);
// 	}
// 	map->grid[0] = "1111111111111111";
// 	map->grid[1] = "1000000000000001";
// 	map->grid[2] = "1001000000000111";
// 	map->grid[3] = "1000000000000001";
// 	map->grid[4] = "1000000100000001";
// 	map->grid[5] = "1000000010000001";
// 	map->grid[6] = "1000000000010001";
// 	map->grid[7] = "1000100000000001";
// 	map->grid[8] = "1111111111111111";
// 	map->width = 16;
// 	map->height = 9;
// 	// print map
// 	i = 0;
// 	while (i < 9)
// 	{
// 		j = 0;
// 		while (map->grid[i][j])
// 			printf("%c", map->grid[i][j++]);
// 		printf("\n");
// 		i++;
// 	}
// 	return (SUCCESS);
// }