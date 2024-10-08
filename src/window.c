/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:30:55 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/08 02:38:06 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "window.h"

int	window_setup(t_window *win, void *mlx)
{
	win->win = mlx_new_window(mlx, WIN_W, WIN_H, "cub3d");
	if (win->win == NULL)
		return (ft_return(ERROR, FAIL, "Error window setup"));	
    win->mlx = mlx;
    win->width = WIN_W;
	win->height = WIN_H;
	return (chk_box(SUCCESS, EQ, SUCCESS, "window setup"));	
}

void	window_clean(t_window *win)
{
    if (win->win)
	    mlx_destroy_window(win->mlx, win->win);
}
