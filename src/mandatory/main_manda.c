/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:16:47 by aska              #+#    #+#             */
/*   Updated: 2025/02/03 21:36:28 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_manda.h"

int	main(int argc, char **argv)
{
	int		exit_code;
	t_data	data;

	exit_code = check_entry_arg(argc, argv);
	if (exit_code != SUCCESS)
		return (exit_code);
	data_init(&data);
	exit_code = data_setup(&data, argv[1]);
	if (exit_code == SUCCESS)
		exit_code = floor_ceil_init(&data.win, data.textures.ceil_rgb,
				data.textures.floor_rgb, &data.floorceil_imgs);
	// title();
	if (exit_code == SUCCESS)
	{
		event_setup(&data);
		render(&data);
		mlx_loop(data.mlx);
	}
	floor_ceil_destroy(data.mlx, &data.floorceil_imgs);
	data_clean(&data);
	return (exit_code);
}
