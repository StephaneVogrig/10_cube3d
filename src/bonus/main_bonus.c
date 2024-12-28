/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:37:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/28 14:20:01 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "main_bonus.h"

int program_init(t_data *data, t_option *option, int argc, char **argv)
{
	int exit_code;

	exit_code = check_entry_arg(argc, argv);
	if (exit_code != SUCCESS)
		return (exit_code);
	exit_code = option_init(option, argc, argv);
	if (exit_code != SUCCESS)
		return (exit_code);
	data_init(data);
	data->win.width = option->win_width;
	data->win.height = option->win_height;
	return (exit_code);
}

int program_setup(t_data *data, t_option *option, char *map_path)
{
	int exit_code;

	(void)option;
	exit_code = data_setup(data, map_path);
	if (exit_code == SUCCESS)
		exit_code = minimap_setup(&data->minimap, data->mlx, &data->win, &data->map);
	return (exit_code);
}

int	main(int argc, char **argv)
{
	int		exit_code;
	t_data	data;
	t_option option;

	title();
	exit_code = program_init(&data, &option, argc, argv);
	if (exit_code == SUCCESS)
		exit_code = program_setup(&data, &option, argv[1]);
	if (exit_code == SUCCESS)
	{
		event_setup(&data);
		minimap_event_setup(&data.minimap, &data);
		render(&data);
		mlx_loop(data.mlx);
	}
	minimap_destroy(&data.minimap);
	data_clean(&data);
	return (exit_code);
}
