/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:37:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/16 18:05:55 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
		exit_code = minimap_setup(data.mlx, &data.minimap, &data.map);
	if (exit_code == SUCCESS)
	{
		event_setup(&data);
		chrono(START);
		render(&data);
		mlx_loop(data.mlx);
	}
	minimap_destroy(&data.minimap);
	data_clean(&data);
	return (EXIT_SUCCESS);
}
