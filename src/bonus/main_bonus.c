/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:37:20 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/22 14:00:39 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"
#include "option_bonus.h"

int	main(int argc, char **argv)
{
	int		exit_code;
	t_data	data;
	t_option *option;

	option = option_get_ptr();
	title();
	exit_code = check_entry_arg(argc, argv);
	if (exit_code != SUCCESS)
		return (exit_code);
	option_init(option, argc, argv);
	data_init(&data);
	exit_code = data_setup(&data, argv[1]);
	if (exit_code == SUCCESS && option->minimap == TRUE)
		exit_code = minimap_setup(data.mlx, &data.map, &data);
	if (exit_code == SUCCESS)
	{
		event_setup(&data);
		render(&data);
		mlx_loop(data.mlx);
	}
	minimap_destroy();
	data_clean(&data);
	return (EXIT_SUCCESS);
}
