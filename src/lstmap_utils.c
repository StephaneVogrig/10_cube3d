/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 03:06:27 by aska              #+#    #+#             */
/*   Updated: 2024/09/27 16:17:18 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
