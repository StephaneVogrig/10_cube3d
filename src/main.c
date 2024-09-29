/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:16:47 by aska              #+#    #+#             */
/*   Updated: 2024/09/29 00:50:55 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"
#include "event.h"
#include "lst_map.h"
#include "map.h"
#include "mlx.h"
#include "render.h"
#include "vec2i.h"

int	map_load(t_data *data, char *path)
{
	int			fd;
	t_lstmap	*lst_map;

	lst_map = NULL;
	if (chk_box(open_file(&fd, path), EQ, SUCCESS, path) == 1)
		return (ft_return(ERROR, FAIL, "Error to open file"));
	if (chk_box(file_process(data->mlx, &data->map.textures, &fd), EQ, SUCCESS,
			"File Processing") == 1)
		return (ft_return(ERROR, FAIL, "Error to discovery asset"));
	if (chk_box(init_map_process(&data->map, &lst_map, fd), EQ, SUCCESS,
			"Initialize temporary map") == 1)
		return (ft_return(ERROR, FAIL, "Error on Initialization Map"));
	if (chk_box(set_var_creation_map(&data->map), EQ, SUCCESS,
			"Setting Map Variables") == 1)
		return (ft_return(ERROR, FAIL, "Error on Allocation Map"));
	if (chk_box(map_creation(&data->map, &lst_map), EQ, SUCCESS,
			"Creating Map") == 1)
		return (ft_return(ERROR, FAIL, "Error on Map Creation"));
	// ok = map_checker(cub);
	// if (chk_box(ok, EQ, SUCCESS, "Check Map") == 1)
	// 	helltrain(cub, ERROR, 1, "Error on Initialization Map");
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	title();
	if (check_entry_arg(argc, argv) == FAIL)
		return (EXIT_SUCCESS);
	data_init(&data);
	if (data_setup(&data, argv[1]) == SUCCESS)
	{
		printf("mlx_loop\n"); // debug
		event_setup(&data);
		chrono(START);
		render(&data);
		// test_texture(data.tex_north, data.win);
		mlx_loop(data.mlx);
	}
	data_clean(&data);
	return (EXIT_SUCCESS);
}
