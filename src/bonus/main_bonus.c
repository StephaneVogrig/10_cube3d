/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:37:20 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/30 17:07:24 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	program_init(t_data *data, int argc, char **argv)
{
	int		exit_code;

	exit_code = check_entry_arg(argc, argv);
	if (exit_code != SUCCESS)
		return (exit_code);
	data_init(data);
	data->win.width = WIN_W;
	data->win.height = WIN_H;
	return (exit_code);
}

int	program_setup(t_data *data, char *map_path)
{
	int	exit_code;

	exit_code = data_setup(data, map_path);
	return (exit_code);
}

int	main(int argc, char **argv)
{
	int			exit_code;
	t_data		data;

	// title();
	exit_code = program_init(&data, argc, argv);
	if (exit_code == SUCCESS)
		exit_code = program_setup(&data, argv[1]);
	if (exit_code == SUCCESS)
	{
		event_setup(&data);
		interface_event_setup(&data.minimap, &data);
		render(&data);
		mlx_loop(data.mlx);
	}
	data_clean(&data);
	return (exit_code);
}
