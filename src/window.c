/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:30:55 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/12 02:52:23 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
