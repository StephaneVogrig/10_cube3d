/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:15:02 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/08 02:37:56 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minimap_bonus.h"

int	minimap_scale(t_map *map, t_minimap *minimap)
{
	t_vec2i	scale;

	scale.x = minimap->screen.width / map->width;
	scale.y = minimap->screen.height / map->height;
	if (scale.y < scale.x)
		return (scale.y);
	return (scale.x);
}

int	minimap_setup(void *mlx, t_minimap *minimap, t_map *map)
{
	(void)mlx;
	minimap->screen.win = mlx_new_window(mlx, MINIMAP_W, MINIMAP_H, "minimap");
	if (minimap->screen.win == NULL)
		return (ft_return(ERROR, FAIL, "Error minimap setup"));
	if (screen_init(&minimap->screen, mlx, MINIMAP_W, MINIMAP_H) == ERROR)
		return (FAIL);
	minimap->scale = minimap_scale(map, minimap);
	return (chk_box(SUCCESS, EQ, SUCCESS, "Minimap initialization"));
}

void	minimap_draw_ray(t_minimap *minimap, t_player *player, double raylen, \
																t_vec2d raydir)
{
	t_vec2i	player_pos;
	t_vec2i	intersect;
	
	player_pos.x = minimap->scale * (player->grid.x + player->box.x);
	player_pos.y = minimap->scale * (player->grid.y + player->box.y);
	if (raylen < 0)
		raylen = fabs(raylen);
	intersect.x = player_pos.x + raydir.x * raylen * minimap->scale;
	intersect.y = player_pos.y + raydir.y * raylen * minimap->scale;
	draw_line(&minimap->screen, player_pos, intersect, 0xFFFF0000);
}
