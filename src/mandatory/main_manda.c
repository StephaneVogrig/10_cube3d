/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:16:47 by aska              #+#    #+#             */
/*   Updated: 2024/10/26 18:06:33 by aska             ###   ########.fr       */
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

	title();
	if (check_entry_arg(argc, argv) == FAIL)
		return (EXIT_SUCCESS);
	data_init(&data);
	if (data_setup(&data, argv[1]) == SUCCESS)
	{
		event_setup(&data);
		chrono(START);
		render(&data);
		mlx_loop(data.mlx);
	}
	data_clean(&data);
	return (EXIT_SUCCESS);
}
