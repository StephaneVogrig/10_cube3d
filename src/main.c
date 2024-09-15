/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:16:47 by aska              #+#    #+#             */
/*   Updated: 2024/09/15 17:00:55 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "vec2i.h"
#include "event.h"
#include "render.h"
#include "mlx.h"

int	map_load(char *path, t_map *map)
{
	printf("map_load\n");
	(void)path;
	
	map->grid = malloc(9 * sizeof(map));
	if (map == NULL)
		return (FAIL);
    map->grid[0] = "1111111111111111";
    map->grid[1] = "1000000000000001";
    map->grid[2] = "1001000000000111";
    map->grid[3] = "1000000000000001";
    map->grid[4] = "1000000000000001";
    map->grid[5] = "1000000010000001";
    map->grid[6] = "1000000000010001";
    map->grid[7] = "1000100000000001";
    map->grid[8] = "1111111111111111";
	map->width = 16;
	map->height = 9;
	
    int i = 0;
    while (i < 9)
	{
	int j = 0;
		while (map->grid[i][j])
			printf("%c", map->grid[i][j++]);
		printf("\n");
		i++;
    }
	printf("width: %i Height: %i\n", map->width, map->height);	
	return (SUCCESS);
}

int main(int argc, char **argv)
{
    t_cub *cub;
	t_data	data;

    // title();
    (void)argc;
    (void)argv;
    // check_entry_arg(argc, argv);
    // if (check_entry_arg(ac, av) == FAIL)
    //     return (OK);
    cub = ft_calloc(1, sizeof(t_cub));
	if (cub == NULL)
		ft_exit(ERROR, 1, "Allocation For Struct 'cub'");
    // init_organizer(cub, argv[1]);
    // debug(cub);
	data_init(&data);
	printf("key down: %i\n", data.key.down);
	printf("player x: %f y:%f\n", data.player.pos.x, data.player.pos.y);
	
	if (map_load(argv[1], &data.map) == SUCCESS && mlx_setup(&data) == SUCCESS)
    {
		printf("mlx_loop\n");
		event_setup(&data);
		render(&data);
		mlx_loop(data.mlx); 
    }
    helltrain(cub, INFO, 0, "END OF PROGRAM");
	data_clean(&data);
    return (EXIT_SUCCESS);
}
