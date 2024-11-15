/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_mlx_img.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:36:01 by stephane          #+#    #+#             */
/*   Updated: 2024/11/15 03:14:55 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "floor_ceil_mlx_img.h"

static void	draw_ceil_floor(void *mlx, void *img, int color_ceil, int color_floor)
{
	int x;
	int	y;
	int win_h_2;

	win_h_2 = WIN_H / 2;
	y = 0;
	while (y < win_h_2)
	{
		x = 0;
		while (x < WIN_W)
		{
			mlx_set_image_pixel(mlx, img, x, y, color_ceil);
			mlx_set_image_pixel(mlx, img, x, y + win_h_2, color_floor);
			x++;
		}
		y++;
	}
}

static void	*floor_ceil_get_ptr(void)
{
	static t_floor_ceil	mlx_imgs;

	return (&mlx_imgs);
}

int	floor_ceil_init(t_window *win, int color_ceil, int color_floor)
{
	t_floor_ceil *mlx_img;

	mlx_img = floor_ceil_get_ptr();
	mlx_img->normal = mlx_new_image(win->mlx, win->width, win->height);
	if (mlx_img->normal == NULL)
		return (FAIL);
	mlx_img->dark = mlx_new_image(win->mlx, win->width, win->height);
	if (mlx_img->dark == NULL)
		return (FAIL);
	draw_ceil_floor(win->mlx, mlx_img->normal, color_ceil, color_floor);
	color_ceil = color_darkened(color_ceil, TRUE);
	color_floor = color_darkened(color_floor, TRUE);
	draw_ceil_floor(win->mlx, mlx_img->dark, color_ceil, color_floor);
	return (SUCCESS);
}

void	floor_ceil_put_to_window(t_window *win, int dark)
{
	t_floor_ceil	*mlx_img;

	mlx_img = floor_ceil_get_ptr();
	if (dark)
		mlx_put_image_to_window(win->mlx, win->win, mlx_img->dark, 0, 0);
	else
		mlx_put_image_to_window(win->mlx, win->win, mlx_img->normal, 0, 0);
}

void	floor_ceil_destroy(void *mlx)
{
	t_floor_ceil *mlx_img;

	mlx_img = floor_ceil_get_ptr();
	if (mlx_img->normal)
		mlx_destroy_image(mlx, mlx_img->normal);
	if (mlx_img->dark)
		mlx_destroy_image(mlx, mlx_img->dark);
}
