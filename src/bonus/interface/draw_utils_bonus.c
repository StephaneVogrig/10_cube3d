/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:58:42 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/09 13:58:41 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_utils_bonus.h"

void	draw_rectangle(t_interface *minimap, t_vec2i begin, t_vec2i end,
		int color)
{
	int	x;
	int	y;

	y = begin.y;
	while (y <= end.y)
	{
		x = begin.x;
		while (x <= end.x)
		{
			mlx_pixel_put(minimap->mlx, minimap->win, x, y, color);
			x++;
		}
		y++;
	}
}
