/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:30:55 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/22 19:08:16 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "window.h"

int	window_setup(t_window *win, void *mlx)
{
	win->win = mlx_new_window(mlx, WIN_W, WIN_H, "cub3d");
	if (win->win == NULL)
	{
		printf("window_setup failed\n");
		return (FAIL);	
	}	
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
