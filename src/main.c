/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:16:47 by aska              #+#    #+#             */
/*   Updated: 2024/09/25 17:39:55 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "event.h"
#include "mlx.h"
#include "render.h"
#include "vec2i.h"

int	map_load(t_data *data, char *path)
{
	int	fd;

	if (chk_box(open_cub(&fd, path), EQ, SUCCESS, path) == 1)
		return (ft_return(ERROR, FAIL, "Error to open file"));
	if (chk_box(file_process(&data->mlx, &data->textures, &fd), EQ, SUCCESS,
			"File Processing") == 1)
		return (ft_return(ERROR, FAIL, "Error to discovery asset"));
	// ok = init_map_process(cub);
	// if (chk_box(ok, EQ, SUCCESS, "Initialize Map") == 1)
	// 	helltrain(cub, ERROR, 1, "Error on Initialization Map");
	// ok = set_var_creation_map(cub);
	// if (chk_box(ok, EQ, SUCCESS, "Setting Map Variables") == 1)
	// 	helltrain(cub, ERROR, 1, "Error on Allocation Map");
	// ok = map_creation(cub);
	// if (chk_box(ok, EQ, SUCCESS, "Creating Map") == 1)
	// 	helltrain(cub, ERROR, 1, "Error on Initialization Map");
	// ok = map_checker(cub);
	// if (chk_box(ok, EQ, SUCCESS, "Check Map") == 1)
	// 	helltrain(cub, ERROR, 1, "Error on Initialization Map");
	printf("map_load\n");
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	// t_cub	*cub;
	title();
	if (check_entry_arg(argc, argv) == FAIL)
		return (EXIT_SUCCESS);
	data_init(&data);
	if (mlx_setup(&data) == SUCCESS && map_load(&data, argv[1]) == SUCCESS)
	{
		printf("mlx_loop\n");
		event_setup(&data);
		render(&data);
		mlx_loop(data.mlx);
	}
	// helltrain(cub, INFO, 0, "END OF PROGRAM");
	data_clean(&data);
	return (EXIT_SUCCESS);
}
