/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:54:45 by aska              #+#    #+#             */
/*   Updated: 2024/10/11 03:47:47 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_process.h"
#include "lst_map.h"
#include "map.h"
#include "player.h"

int	map_setup(void *mlx, t_lstmap **lst_map, t_map *map)
{
	if (file_process(mlx, &map->textures, lst_map) == 1)
		return (ft_return(ERROR, FAIL, "Error to discovery asset"));
	if (init_map_process(map, lst_map) == 1)
		return (ft_return(ERROR, FAIL, "Error on Initialization Map"));
	if (map_creation(map, lst_map) == 1)
		return (ft_return(ERROR, FAIL, "Error on Map Creation"));
	delete_all_lstmap(lst_map);
	print_tab(map->grid);
	map->grid = ft_tab_f(map->grid);
	ft_exit(INFO, 0, "END OF PROGRAM");
	// if (map_checker(&data->map, &data->player) == 1)
	// return (ft_return(ERROR, FAIL, "Map Invalid"));
	return (SUCCESS);
}

int	check_line(char *line)
{
	if (line == NULL)
		return (ERROR);
	if (is_empty_line(line) == TRUE || is_map_valid(line) == FALSE)
		return (ft_return(ERROR, ERROR, "Invalid map"));
	return (SUCCESS);
}

int	set_map_info(t_map *map, char *line)
{
	int				x;
	int				i;
	static t_bool	player_valid = FALSE;

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
	x = (int)ft_strlen(line);
	if (x > map->width)
		map->width = x;
	map->height++;
	return (SUCCESS);
}

int	init_map_process(t_map *map, t_lstmap **lst_map)
{
	t_lstmap	*tmp;

	tmp = *lst_map;
	while (tmp != NULL && is_empty_line(tmp->line) == TRUE)
		tmp = tmp->next;
	while (tmp != NULL)
	{
		if (check_line(tmp->line) == SUCCESS)
			set_map_info(map, tmp->line);
		else
		{
			delete_all_lstmap(lst_map);
			return (ft_return(ERROR, ERROR, "Map Invalid"));
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}

int	map_creation(t_map *map, t_lstmap **lst_map)
{
	int	y;
	t_lstmap	*tmp;

	y = 0;
	tmp = *lst_map;
	map->grid = ft_calloc(map->height + 1, sizeof(char *));
	if (map->grid == NULL)
		return (ft_return(ERROR, ERROR, "Error on Map Creation"));
	while (y != map->height)
	{
		map->grid[y] = ft_strdup(tmp->line);
		if (map->grid[y] == NULL)
		{
			map->grid = ft_tab_f(map->grid);
			return (ft_return(ERROR, ERROR, "Error on Map Creation"));
		}
		tmp = tmp->next;
		y++;
	}
	return (SUCCESS);
}
