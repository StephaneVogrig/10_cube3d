/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_to_border.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:45:36 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/22 19:16:14 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "draw_line_to_border.h"


/*	equation d'une droite a partir d'un point p(px,py) et d'un angle a : y = (x - px) * tan(a) + py
	l'intersection avec une droite verticale x = m a pour courdonnees y = (m - px) * tan(a) + py
	l'intersection avec une droite horizontale y = n a pour courdonnees x = (n - py) / tan(a) + px
*/
void	draw_line_to_border(t_minimap *minimap, t_player *player, int color)
{
	printf("draw_line_to_border\n");
	t_vec2i border;
	t_vec2i begin;
	
	begin.x = player->grid.x * minimap->scale + (player->box.x * minimap->scale);
	begin.y = player->grid.y * minimap->scale + (player->box.y * minimap->scale);
	border.x = begin.x;
	border.y = begin.y;
	if (player->dir == 0)
		border.y = YMIN;
	else if (player->dir == M_PI || player->dir == -M_PI)
		border.y = YMAX;
	else if (player->dir == -M_PI_2)
		border.x = XMIN;
	else if (player->dir == M_PI_2)
		border.x = XMAX;
		
	else if (isless(player->dir, -M_PI_2))
	{
		// intersect y = YMAX
		border.x = begin.x - (YMAX - begin.y) * tan(player->dir);
		if (border.x >= XMIN && border.x <= XMAX)
			border.y = YMAX;
		else // intersect x = XMIN
		{
			border.x = XMIN;
			border.y = begin.y - (XMIN - begin.x) / tan(player->dir);
			if (border.y > YMAX)
				border.y = YMAX;
			if (border.y < YMIN)
				border.y = YMIN;
		}
	}
	else if (isless(player->dir, 0.0))
	{
		// intersect y = YMIN
		border.x = begin.x - (YMIN - begin.y) * tan(player->dir);
		if (border.x >= XMIN)
			border.y = YMIN;
		else // intersect x = XMIN
		{
			border.x = XMIN;
			border.y = begin.y - (XMIN - begin.x) / tan(player->dir);
			if (border.y > YMAX)
				border.y = YMAX;
			if (border.y < YMIN)
				border.y = YMIN;
		}
	}
	else if (isless(player->dir, M_PI_2))
	{
		// intersect y = YMIN
		border.x = begin.x - (YMIN - begin.y) * tan(player->dir);
		if (border.x >= XMIN && border.x <= XMAX)
			border.y = YMIN;
		else // intersect x = XMAX
		{
			border.x = XMAX;
			border.y = begin.y - (XMAX - begin.x) / tan(player->dir);
			if (border.y > YMAX)
				border.y = YMAX;
			if (border.y < YMIN)
				border.y = YMIN;
		}
	}
	else
	{
		// intersect y = YMAX
		border.x = begin.x - (YMAX - begin.y) * tan(player->dir);
		if (border.x >= XMIN && border.x <= XMAX)
			border.y = YMAX;
		else // intersect x = XMAX
		{
			border.x = XMAX;
			border.y = begin.y - (XMAX - begin.x) / tan(player->dir);
			if (border.y > YMAX)
				border.y = YMAX;
			if (border.y < YMIN)
				border.y = YMIN;
		}
	}
	// printf("player dir: %f x: %i y: %i border x: %i y: %i\n", player.dir, begin.x, begin.y, border.x, border.y);
	draw_line(&minimap->screen, begin, border, color);
}
