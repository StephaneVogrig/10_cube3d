/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:54:45 by aska              #+#    #+#             */
/*   Updated: 2024/09/30 19:17:32 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "file_process.h"
#include "lst_map.h"
#include "map.h"
#include "player.h"

int	check_line(t_map *map, char *line)
{
	int				x;
	int				i;
	static t_bool	player_valid = FALSE;

	if (line == NULL)
		return (ERROR);
	if (is_empty_line(line) == TRUE || is_map_valid(line) == FALSE)
		return (ft_return(ERROR, ERROR, "Invalid map"));
	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isthis(line[i++], "NSWE"))
		{
			if (player_valid == TRUE)
				return (ft_return(ERROR, ERROR, "Player on map Invalid"));
			player_valid = TRUE;
		}
	}
	x = ft_strlen_endc(line, '\n'); // -1 to remove the '\n' character
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
		line = gnl_f(fd, line);
	while (line != NULL)
	{
		if (is_valid == TRUE)
		{
			if (check_line(map, line) == SUCCESS)
				insert_end_lstmap(lst_map, ft_substr(line, 0,
						ft_strlen_endc(line, '\n')));
			else
				is_valid = FALSE;
		}
		line = gnl_f(fd, line);
	}
	if (is_valid == FALSE)
		return (ERROR);
	return (SUCCESS);
}

int	set_var_creation_map(t_map *map)
{
	int	y;

	y = 0;
	printf("map->height = %d\n", map->height);
	printf("map->width = %d\n", map->width);
	map->grid = ft_calloc(map->height + 1, sizeof(char *));
	if (map->grid == NULL)
		return (ERROR);
	while (y != map->height)
	{
		map->grid[y] = ft_calloc(map->width + 1, sizeof(char));
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
		printf("tmp->line = %s\n", tmp->line);
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

void	player_finder(t_map *map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map->grid[++y] != NULL)
	{
		while (map->grid[y][x] != 0)
		{
			if (ft_isthis(map->grid[y][x], "NSWE"))
			{
				player_set_dir(player, map->grid[y][x]);
				player->grid.x = x;
				player->grid.y = y;
			}
			x++;
		}
		x = 0;
	}
}

