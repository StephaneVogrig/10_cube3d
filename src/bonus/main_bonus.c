/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:37:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/24 23:37:03 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_arg.h"
#include "chrono.h"
#include "data.h"
#include "event.h"
#include "file_process.h"
#include "render.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		exit_code;

	title();
	if (check_entry_arg(argc, argv) == FAIL)
		return (EXIT_SUCCESS);
	data_init(&data);
	exit_code = data_setup(&data, argv[1]);
	if (exit_code == SUCCESS)
		exit_code = minimap_setup(data.mlx, &data.minimap, &data.map);
	if (exit_code == SUCCESS)
	{
		event_setup(&data);
		chrono(START);
		render(&data);
		mlx_loop(data.mlx);
	}
	if (data.minimap.screen.img)
		mlx_destroy_image(data.mlx, data.minimap.screen.img);
	if (data.minimap.screen.win)
		mlx_destroy_window(data.mlx, data.minimap.screen.win);
	data_clean(&data);
	return (EXIT_SUCCESS);
}
