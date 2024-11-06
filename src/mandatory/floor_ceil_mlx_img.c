/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_mlx_img.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:36:01 by stephane          #+#    #+#             */
/*   Updated: 2024/11/06 01:49:28 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "texture.h"
#include "window.h"

static void	draw_ceil_floor(t_window *win, void *img, int color_ceil, int color_floor)
{
	int x;
	int	y_ceil;
	int y_floor;
	int lim;
	
	lim = win->height / 2;
	y_ceil = 0;
	y_floor = lim;
	while (y_ceil < lim)
	{
		x = 0;
		while (x < win->width)
		{
			mlx_set_image_pixel(win->mlx, img, x, y_ceil, color_ceil);
			mlx_set_image_pixel(win->mlx, img, x, y_floor, color_floor);
			x++;
		}
		y_ceil++;
		y_floor++;
	}
}

void	*floor_ceil_get_ptr_img(void)
{
	static t_texture mlx_img;
	
	return (&mlx_img);
}

void	*floor_ceil_get_ptr_img_dark(void)
{
	static t_texture mlx_img_dark;
	
	return (&mlx_img_dark);
}

int	floor_ceil_init(t_window *win, int color_ceil, int color_floor)
{
	t_texture *mlx_img;
	t_texture *mlx_img_dark;
	
	mlx_img = floor_ceil_get_ptr_img();
	mlx_img->img = mlx_new_image(win->mlx, win->width, win->height);
	if (mlx_img->img == NULL)
		return (FAIL);
	mlx_img_dark = floor_ceil_get_ptr_img_dark();
	mlx_img_dark->img = mlx_new_image(win->mlx, win->width, win->height);
	if (mlx_img_dark->img == NULL)
		return (FAIL);
	mlx_img->mlx = win->mlx;
	mlx_img->width = win->width;
	mlx_img->height = win->height;
	mlx_img_dark->mlx = win->mlx;
	mlx_img_dark->width = win->width;
	mlx_img_dark->height = win->height;
	draw_ceil_floor(win, mlx_img->img, color_ceil, color_floor);
	color_ceil = (color_ceil >> 5) & 0xFF070707;
	color_floor = (color_floor >> 5) & 0xFF070707;
	draw_ceil_floor(win, mlx_img_dark->img, color_ceil, color_floor);
	return (SUCCESS);
}

void	floor_ceil_destroy(void)
{
	t_texture *mlx_img;
	t_texture *mlx_img_dark;
	
	mlx_img = floor_ceil_get_ptr_img();
	if (mlx_img)
		mlx_destroy_image(mlx_img->mlx, mlx_img->img);
	mlx_img_dark = floor_ceil_get_ptr_img_dark();
	if (mlx_img_dark)
		mlx_destroy_image(mlx_img_dark->mlx, mlx_img_dark->img);
	
}
