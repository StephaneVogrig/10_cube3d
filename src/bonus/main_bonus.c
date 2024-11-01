/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:37:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/01 19:31:41 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	int		exit_code;
	t_data	data;

	title();
	exit_code = check_entry_arg(argc, argv);
	if (exit_code != SUCCESS)
		return (exit_code);
	data_init(&data);
	exit_code = data_setup(&data, argv[1]);
	if (exit_code == SUCCESS)
		exit_code = window_setup(&data.win, data.mlx);
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
