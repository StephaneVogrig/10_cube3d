/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/16 22:34:03 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

double dda_loop(t_dda *dda,  char **map, t_vec2i mapcheck)
{
	// printf("dda_loop\n");
	double	raylen;
	int		hit;

	hit = FALSE;
	while (hit == FALSE)
	{
		if (dda->len_side.x < dda->len_side.y)
		{
			mapcheck.x += dda->step.x;
			raylen = dda->len_side.x;
			dda->len_side.x += dda->len_unit.x;
		}
		else
		{
			mapcheck.y += dda->step.y;
			raylen = dda->len_side.y;
			dda->len_side.y += dda->len_unit.y;
		}
		if (map[mapcheck.y][mapcheck.x] == '1')
			hit = TRUE;
	}
	return (raylen);
}

double	dda(t_vec2d *raydir, char **map, t_player *player)
{
	t_dda	dda;
	
	dda.len_unit.x = fabs(1 / raydir->x);
	dda.len_unit.y = fabs(1 / raydir->y);
	if (raydir->x < 0)
	{
		dda.step.x = -1;
		dda.len_side.x = player->box.x * dda.len_unit.x;
	}
	else
	{
		dda.step.x = 1;
		dda.len_side.x = (1 - player->box.x) * dda.len_unit.x;
	}
	if (raydir->y < 0)
	{
		dda.step.y = -1;
		dda.len_side.y = player->box.y * dda.len_unit.y;
	}
	else
	{
		dda.step.y = 1;
		dda.len_side.y = (1 - player->box.y) * dda.len_unit.y;
	}
	return (dda_loop(&dda, map, player->grid));
}

void	raycasting(t_minimap *minimap, t_map *map, t_player *player)
{
	printf("raycasting\n");
	t_vec2d raydir;
	t_vec2d	intersect;
	double	raylen;
	t_vec2d	dir;
	int	x;
	double camera;
	t_vec2d	plane;
	
	dir.x = cos(player->dir);
	dir.y = sin(player->dir);
	plane.x = -dir.y;
	plane.y = dir.x;
	x = 0;
	while (x < CUB_W)
	{
		camera = 2.0 * x / CUB_W - 1;
		x += 20;
		raydir.x = dir.x + plane.x * camera;
		raydir.y = dir.y + plane.y * camera;
		raylen = dda(&raydir, map->grid, player);
		
		intersect.x = (double)player->grid.x + player->box.x + raydir.x * raylen;
		intersect.y = (double)player->grid.y + player->box.y + raydir.y * raylen;
		// printf("raylen: %f intersect x: %f y: %f\n", raylen, intersect.x, intersect.y);
		// printf("x: %i camera: %f\n", x, camera);
		
		t_vec2i	begin;
		t_vec2i	end;
		begin.x = minimap->scale * (player->grid.x + player->box.x);
		begin.y = minimap->scale * (player->grid.y + player->box.y);
		end.x = minimap->scale * intersect.x;
		end.y = minimap->scale * intersect.y;
		// printf("begin x: %i y:%i end x: %i y:%i\n", begin.x, begin.y, end.x, end.y);
		draw_line(&minimap->screen, begin, end, 0xFFFF0000);
		// draw_line(&minimap->screen, vector2i(0, 0), vector2i(100, 100), 0xFFFF0000);
	}
}
