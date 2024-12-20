/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 03:06:27 by aska              #+#    #+#             */
/*   Updated: 2024/12/20 21:44:20 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "lstmap_utils.h"

int	lstmap_to_grid(t_map *map, t_lstmap **lst_map)
{
	int			y;
	t_lstmap	*tmp;

	y = 0;
	tmp = *lst_map;
	map->grid = ft_calloc(map->height + 1, sizeof(char *));
	if (map->grid == NULL)
		return (ft_return(ERROR, 273, "Error on Map Creation"));
	while (y != map->height)
	{
		map->grid[y] = ft_calloc(map->width + 1, sizeof(char));
		if (map->grid[y] == NULL)
			return (ft_return(ERROR, 274, "Error on Map Creation"));
		ft_strcpy(map->grid[y], tmp->line);
		tmp = tmp->next;
		y++;
	}
	return (SUCCESS);
}
