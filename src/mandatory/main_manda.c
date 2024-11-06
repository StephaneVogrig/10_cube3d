/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:16:47 by aska              #+#    #+#             */
/*   Updated: 2024/11/06 01:59:56 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "check_arg.h"
#include "chrono.h"
#include "data.h"
#include "event.h"
#include "file_process.h"
#include "render.h"
#include "floor_ceil_mlx_img.h"

int	main(int argc, char **argv)
{
	int		exit_code;
	t_data	data;

	title();
	exit_code = check_entry_arg(argc, argv);
	if (exit_code == FAIL)
		return (EXIT_FAILURE);
	data_init(&data);
	exit_code = data_setup(&data, argv[1]);
	if (exit_code == SUCCESS)
		exit_code = window_setup(&data.win, data.mlx);
	if (exit_code == SUCCESS)
		floor_ceil_init(&data.win, data.map.textures.ceil_rgb.integer, data.map.textures.floor_rgb.integer);
	if (exit_code == SUCCESS)
	{
		event_setup(&data);
		chrono(START);
		render(&data);
		mlx_loop(data.mlx);
	}
	floor_ceil_destroy();
	data_clean(&data);
	return (EXIT_SUCCESS);
}
