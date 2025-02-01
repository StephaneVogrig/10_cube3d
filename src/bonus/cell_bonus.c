/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:23:40 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/01 12:03:36 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cell_bonus.h"

inline int	cell_is_wall(char *cell)
{
	if (cell == NULL)
		return (FALSE);
	if (*cell > '0' && *cell <= '9')
		return (TRUE);
	return (FALSE);
}

inline int	cell_is_wall_or_door(char *cell)
{
	if (cell == NULL)
		return (FALSE);
	if (cell_is_wall(cell) || cell_is_door(cell))
		return (TRUE);
	return (FALSE);
}

int	cell_is_door(char *cell)
{
	if (cell == NULL)
		return (FALSE);
	if (*cell == 'R' || *cell == 'L' || *cell == 'T')
		return (TRUE);
	return (FALSE);
}

inline char	*map_get_cell_ptr(const t_map *map, t_position *p)
{
	if (is_outside_map(map, p))
		return (NULL);
	return (&(map->grid[p->y.grid][p->x.grid]));
}
