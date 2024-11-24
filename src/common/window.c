/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:30:55 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 02:05:34 by svogrig          ###   ########.fr       */
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

void	window_clean(t_window *win)
{
    if (win->win)
	    mlx_destroy_window(win->mlx, win->win);
}

inline void	window_pixel_put(t_window *win, int x, int y, int color)
{
	mlx_pixel_put(win->mlx, win->win, x, y, color);
}

inline void	window_clear(t_window *win)
{
	mlx_clear_window(win->mlx, win->win);
}
