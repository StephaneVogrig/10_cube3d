/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:30:55 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/04 23:45:13 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	window_setup(t_window *win, void *mlx)
{
	win->win = mlx_new_window(mlx, win->width, win->height, "cub3d");
	if (win->win == NULL)
		return (ft_return(ERROR, FAIL, "mlx_new_window failed", NULL));
	win->mlx = mlx;
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
