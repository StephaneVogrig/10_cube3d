/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:16:47 by aska              #+#    #+#             */
/*   Updated: 2024/09/28 16:38:21 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "vec2i.h"
#include "event.h"
#include "render.h"
#include "mlx.h"

int main(int argc, char **argv)
{
	t_data	data;

    title();
	(void)argc;
    // if (check_entry_arg(ac, av) == FAIL)
    //     return (EXIT_SUCCESS);
    // init_organizer(cub, argv[1]);
    // debug(cub);
	data_init(&data);
	// printf("key down: %i\n", data.key.down); //debug
	if (data_setup(&data, argv[1]) == SUCCESS)
    {
		printf("mlx_loop\n"); //debug
		event_setup(&data);
		chrono(START);
		render(&data);
		// test_texture(data.tex_north, data.win);
		mlx_loop(data.mlx); 
    }
	data_clean(&data);
    return (EXIT_SUCCESS);
}
