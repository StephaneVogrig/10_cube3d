/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:16:47 by aska              #+#    #+#             */
/*   Updated: 2024/09/14 15:17:18 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "vec2i.h"
#include "event.h"
#include "render.h"
#include "mlx.h"

int	map_load(char *path, char **map)
{
	(void)path;
	(void)map;
	
	printf("map_load\n");
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
	char **map;
	map = malloc(9 * sizeof(map));
	if (map == NULL)
		return (EXIT_FAILURE);
	printf("malloc\n");
    map[0] = "1111111111111111";
    map[1] = "1000000000000001";
    map[2] = "1001000000000111";
    map[3] = "1000000000000001";
    map[4] = "1000000000000001";
    map[5] = "1000000010000001";
    map[6] = "1000000000010001";
    map[7] = "1000100000000001";
    map[8] = "1111111111111111";
	printf("map: %p\n", map);
	// data.map.grid = map;
	printf("player x: %f y:%f\n", data.player.pos.x, data.player.pos.y);
	data.map.width = 16;
	data.map.height = 9;
	printf("player x: %f y:%f\n", data.player.pos.x, data.player.pos.y);
	printf("key down: %i\n", data.key.down);
    // int i = 0;
    // while (i < 9)
	// {
	// int j = 0;
	// 	while (data.map.grid[i][j])
	// 		printf("%c", data.map.grid[i][j++]);
	// 	printf("\n");
	// 	i++;
    // }
	// printf("map w: %i H:%i\n", data.map.width, data.map.height);
	// printf("keydown:%x\n", data.key.down);
	
	if (map_load(argv[1], data.map.grid) == SUCCESS && mlx_setup(&data) == SUCCESS)
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
