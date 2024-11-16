/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:15:02 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/16 17:28:18 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minimap_bonus.h"

int	minimap_scale(t_map *map, t_minimap *minimap)
{
	t_vec2i	scale;

	(void)minimap;
	scale.x = MINIMAP_W / map->width;
	scale.y = MINIMAP_H / map->height;
	if (scale.y < scale.x)
		return (scale.y);
	return (scale.x);
}

int window_hook(int event, void* mlx)
{
	if(event == 0)
		mlx_loop_end(mlx);
	return (SUCCESS);
}

int	minimap_setup(void *mlx, t_minimap *minimap, t_map *map)
{
	minimap->win = mlx_new_window(mlx, MINIMAP_W, MINIMAP_H, "minimap");
	if (minimap->win == NULL)
		return (ft_return(ERROR, FAIL, "Error new window in minimap setup"));
	minimap->img = mlx_new_image(mlx, MINIMAP_W, MINIMAP_H);
	if (minimap->img == NULL)
		return (ft_return(ERROR, FAIL, "Error new image in minimap setup"));
	minimap->scale = minimap_scale(map, minimap);
	minimap->mlx = mlx;
	// minimap->width = MINIMAP_W;
	// minimap->height = MINIMAP_H;
    mlx_on_event(mlx, minimap->win, MLX_WINDOW_EVENT, window_hook, mlx);
	return (chk_box(SUCCESS, EQ, SUCCESS, "Minimap setup"));
}

void	minimap_draw_ray(t_minimap *minimap, t_player *player, double raylen,
																t_vec2d raydir)
{
	t_vec2i	player_pos;
	t_vec2i	intersect;

	player_pos.x = minimap->scale * (player->x.grid + player->x.box);
	player_pos.y = minimap->scale * (player->y.grid + player->y.box);
	if (raylen < 0)
		raylen = fabs(raylen);
	intersect.x = player_pos.x + raydir.x * raylen * minimap->scale;
	intersect.y = player_pos.y + raydir.y * raylen * minimap->scale;
	draw_line(minimap, player_pos, intersect, 0xFFFF0000);
}
