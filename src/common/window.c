/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:30:55 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 02:48:40 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "window.h"

int	window_setup(t_window *win, void *mlx)
{
	win->win = mlx_new_window(mlx, WIN_W, WIN_H, "cub3d");
	if (win->win == NULL)
		return (ft_return(ERROR, 275, "Error window setup"));	
    win->mlx = mlx;
    win->width = WIN_W;
	win->height = WIN_H;
	return (SUCCESS);	
}

void	window_destroy(t_window *win)
{
    if (win->win)
	    mlx_destroy_window(win->mlx, win->win);
}

inline void	window_clear(t_window *win)
{
	mlx_clear_window(win->mlx, win->win);
}

inline void	window_put_pixel(t_window *win, int x, int y, int color)
{
	mlx_pixel_put(win->mlx, win->win, x, y, color);
}

inline void	window_put_image(t_window *win, void *img, int x, int y)
{
	mlx_put_image_to_window(win->mlx, win->win, img, x, y);
}
