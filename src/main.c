/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 02:16:47 by aska              #+#    #+#             */
/*   Updated: 2024/09/22 20:36:16 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub3d.h"
#include "vec2i.h"
#include "event.h"
#include "render.h"
#include "mlx.h"

void	test_texture(t_texture texture, t_window win)
{
	printf("texture img:%p width:%i height:%i\n", texture.img, texture.width, texture.height);

	printf("window win:%p width:%i height:%i\n", win.win, win.width, win.height);
	int y;
	int x;
	int	color;
	
	y = 0;
	while (y < texture.height)
	{
		x = 0;
		while (x < texture.width)
		{
			color = mlx_get_image_pixel(win.mlx, texture.img, x, y);
			mlx_pixel_put(win.mlx, win.win, x, y, color);
			x++;
		}
		y++;
	}
}

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
