/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:01:25 by aska              #+#    #+#             */
/*   Updated: 2024/09/25 17:19:34 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_map_process(t_cub *cube)
{
	t_lstmap	*tmp;

	if (cube->map == NULL)
		return (ERROR);
	tmp = cube->map;
	while (is_empty_line(tmp->line) == TRUE && tmp != NULL)
	{
		tmp = tmp->next;
		delete_lstmap(&cube->map, tmp->prev);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (is_empty_line(tmp->line) == TRUE && tmp != NULL)
	{
		tmp = tmp->prev;
		delete_lstmap(&cube->map, tmp->next);
	}
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
		if (is_map_valid(tmp->line) == FALSE
			|| is_empty_line(tmp->line) == TRUE)
			return (ERROR);
	}
	return (SUCCESS);
}

int	set_var_creation_map(t_cub *cube)
{
	int	y;

	y = 0;
	// get_max_map_size(cube);
	cube->map_tab = ft_calloc(cube->map_max_y + 1, sizeof(char *));
	if (cube->map_tab == NULL)
		return (ERROR);
	while (y != cube->map_max_y)
	{
		cube->map_tab[y] = ft_calloc(cube->map_max_x, sizeof(char));
		if (cube->map_tab[y++] == NULL)
			return (ERROR);
	}
	return (SUCCESS);
}

int	map_creation(t_cub *cube)
{
	int			x;
	int			y;
	int			i;
	t_lstmap	*tmp;

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
				cube->map_tab[y][x] = get_blok_type(cube, tmp->line[i], x, y);
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
