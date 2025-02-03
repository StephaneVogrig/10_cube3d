/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_mlx_img_manda.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:36:01 by stephane          #+#    #+#             */
/*   Updated: 2025/02/03 18:59:27 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "floor_ceil_mlx_img_manda.h"

static
void	draw_ceil_floor(t_window *win, void *img, int color_ceil,
						int color_floor)
{
	int	x;
	int	y;
	int	win_h_2;

	win_h_2 = win->height / 2;
	y = 0;
	while (y < win_h_2)
	{
		x = 0;
		while (x < win->width)
		{
			mlx_set_image_pixel(win->mlx, img, x, y, color_ceil);
			mlx_set_image_pixel(win->mlx, img, x, y + win_h_2, color_floor);
			x++;
		}
		y++;
	}
}

int	floor_ceil_init(t_window *win, int color_ceil, int color_floor,
					t_floor_ceil *mlx_imgs)
{
	mlx_imgs->normal = mlx_new_image(win->mlx, win->width, win->height);
	if (mlx_imgs->normal == NULL)
		return (ft_return(ERROR, FAIL, "Floor_ceil", "normal image fail"));
	mlx_imgs->dark = mlx_new_image(win->mlx, win->width, win->height);
	if (mlx_imgs->dark == NULL)
		return (ft_return(ERROR, FAIL, "Floor_ceil", "dark image fail"));
	draw_ceil_floor(win, mlx_imgs->normal, color_ceil, color_floor);
	color_darkened(&color_ceil, TRUE);
	color_darkened(&color_floor, TRUE);
	draw_ceil_floor(win, mlx_imgs->dark, color_ceil, color_floor);
	return (SUCCESS);
}

void	floor_ceil_put_to_window(t_window *win, int dark,
									t_floor_ceil *mlx_imgs)
{
	if (dark)
		window_put_image(win, mlx_imgs->dark, 0, 0);
	else
		window_put_image(win, mlx_imgs->normal, 0, 0);
}

void	floor_ceil_destroy(void *mlx, t_floor_ceil *mlx_imgs)
{
	if (mlx_imgs->normal)
		mlx_destroy_image(mlx, mlx_imgs->normal);
	if (mlx_imgs->dark)
		mlx_destroy_image(mlx, mlx_imgs->dark);
}
