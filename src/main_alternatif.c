/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alternatif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:50:31 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/13 12:46:48 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2i.h"
#include "event.h"
#include "render.h"

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (argc != 2)
	{
		ft_printf("usage: ./fdf <map_file>\n");
		return (SUCCESS);
	}
	data_init(&data);
	if (map_load(argv[1], data.map) == SUCCESS && mlx_setup(&data) == SUCCESS)
	{
		printf("mlx_loop\n");
		event_setup(&data);
		render(&data);
		mlx_loop(data.mlx);
	}
	data_clean(&data);
	return (SUCCESS);
}
