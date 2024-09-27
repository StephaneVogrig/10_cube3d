/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 03:06:27 by aska              #+#    #+#             */
/*   Updated: 2024/09/27 02:52:44 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"
#include "lst_map.h"
#include "map.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (FALSE);
	while (line[i] != '\n')
	{
		if (line[i] != ' ')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_map_valid(char *line)
{
	int	i;

	if (line == NULL)
		return (FALSE);
	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isthis(line[i], " 012NSEW\n") == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	get_max_map_size(t_map *map)
{
	t_lstmap	*tmp;
	int			x;
	int			y;

	tmp = map->lst_map;
	y = 0;
	x = 0;
	while (tmp != NULL)
	{
		if (x < (int)ft_strlen(tmp->line))
			x = ft_strlen(tmp->line);
		tmp = tmp->next;
		y++;
	}
	map->max_x = x;
	map->max_y = y;
}

char	get_blok_type(t_map *map, char c, int x, int y)
{
	if (x == map->max_x)
		return ('\0');
	else if (c == '1')
		return (BLOK);
	else if (c == '0')
		return (FLOOR);
	else if (ft_isthis(c, "NSEW") == TRUE)
	{
		/*remplacer par fonction de set player*/
		// map->player.x = x;
		// map->player.y = y;
		return (c);
	}
	else
		return (MEDIUM_BLOK);
}
