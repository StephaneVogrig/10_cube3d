/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:58:42 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/16 17:51:11 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "draw_utils_bonus.h"

void	draw_rectangle(t_minimap *minimap, t_vec2i begin, t_vec2i end, int color)
{
	int x;
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
