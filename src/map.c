/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:54:15 by stephane          #+#    #+#             */
/*   Updated: 2024/09/22 18:41:17 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "map.h"

int	map_setup(t_map *map)
{
	map->grid = malloc(9 * sizeof(map));
	if (map == NULL)
	{
		printf("map_setup failed\n");
		return (FAIL);	
	}	
    map->grid[0] = "1111111111111111";
    map->grid[1] = "1000000000000001";
    map->grid[2] = "1001000000000111";
    map->grid[3] = "1000000000000001";
    map->grid[4] = "1000000100000001";
    map->grid[5] = "1000000010000001";
    map->grid[6] = "1000000000010001";
    map->grid[7] = "1000100000000001";
    map->grid[8] = "1111111111111111";
	map->width = 16;
	map->height = 9;

	// print map

    int i = 0;
    while (i < 9)
	{
	int j = 0;
		while (map->grid[i][j])
			printf("%c", map->grid[i][j++]);
		printf("\n");
		i++;
    }
	
	return (SUCCESS);
}

