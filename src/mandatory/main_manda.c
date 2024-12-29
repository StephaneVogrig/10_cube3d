/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:16:47 by aska              #+#    #+#             */
/*   Updated: 2024/12/29 18:21:05 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_manda.h"
#include "floor_ceil_mlx_img.h"

int	main(int argc, char **argv)
{
	int		exit_code;
	t_data	data;

	if (argc != 2)
		return (ft_return(ERROR, 3, INVALID_NUM_OF_ARG));
	exit_code = check_entry_arg(argc, argv);
	if (exit_code != SUCCESS)
		return (exit_code);
	data_init(&data);
	exit_code = data_setup(&data, argv[1]);
	if (exit_code == SUCCESS)
		exit_code = floor_ceil_init(&data.win,
									data.textures.ceil_rgb.integer,
									data.textures.floor_rgb.integer);
	if (exit_code == SUCCESS)
		title();
	if (exit_code == SUCCESS)
	{
		event_setup(&data);
		render(&data);
		mlx_loop(data.mlx);
	}
	floor_ceil_destroy(data.mlx);
	data_clean(&data);
	return (exit_code);
}
