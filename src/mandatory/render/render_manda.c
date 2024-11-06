/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:16:27 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/06 02:02:48 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "render.h"
#include "floor_ceil_mlx_img.h"

void	render_draw_floor_ceil(t_window *win, t_map *map, t_player *player)
{
	t_texture	*mlx_img;

	mlx_clear_window(win->mlx, win->win);
	if (map_get_grid(map, &player->position) == AREA)
	{
		mlx_img = floor_ceil_get_ptr_img();
		mlx_put_image_to_window(win->mlx, win->win, mlx_img->img, 0, 0);
	}
	else
	{
		mlx_img = floor_ceil_get_ptr_img_dark();
		mlx_put_image_to_window(win->mlx, win->win, mlx_img->img, 0, 0);
	}
}

void	render(t_data *data)
{
	t_ray	rays[data->win.width];

	ft_bzero(rays, sizeof(rays));
	raycasting(&data->win, &data->map, &data->player, &rays[0]);
	render_draw_floor_ceil(&data->win, &data->map, &data->player);
	render_draw_wall(&data->win, &data->map, &rays[0]);
	fps_print(chrono(STOP));
}
