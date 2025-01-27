/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:45:02 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 23:34:39 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse_utils_bonus.h"

void	mouse_set_on_center(t_window *win)
{
	mlx_mouse_move(win->mlx, win->win, win->width / 2, win->height / 2);
}

void	mouse_mode_switch(t_window *win, int *mouse_mode)
{
	*mouse_mode = *mouse_mode == 0;
	if (*mouse_mode == 1)
	{
		mouse_set_on_center(win);
		mlx_mouse_hide();
	}
	else
		mlx_mouse_show();
}
