/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/22 19:08:03 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "raycasting.h"

void	draw_cub3d_line(t_window *cub, int x, double raylen, t_vec2d raydir)
{
	int	y;
	int wall_h;
	int cell_h;
	int color;
	int side;

		if (raylen < 0)
		{
			raylen = -raylen;
			if (raydir.y < 0)
				side = 's';
			else
				side = 'n';
		}
		else
		{
			if (raydir.x < 0)
				side = 'e';
			else
				side = 'w';
		}
	wall_h = cub->height / raylen;
	if (wall_h > cub->height)
		wall_h = cub->height;
	cell_h = (cub->height - wall_h) / 2;
	if (cell_h < 0)
		cell_h = 0;
	
	y = 0;
	if (side == 'n')
		color = 0xff3f0000;
	if (side == 'w')
		color = 0xff7f0000;
	if (side == 'e')
		color = 0xffbf0000;
	if (side == 's')
		color = 0xffff0000;
	while (y < cell_h)
	{
		mlx_pixel_put(cub->mlx, cub->win, x, y, 0xFF0000FF);
		y++;
	}
	wall_h += cell_h;
	while (y < wall_h)
	{
		mlx_pixel_put(cub->mlx, cub->win, x, y, color);
		y++;
	}
	while (y < cub->height)
	{
		mlx_pixel_put(cub->mlx, cub->win, x, y, 0xFF00FF00);
		y++;
	}	
}

void	draw_ray_minimap(t_minimap *minimap, t_player *player, double raylen, t_vec2d raydir)
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

void	raycasting(t_window *cub, t_minimap *minimap, t_map *map, t_player *player)
{
	t_vec2d	dir;
	t_vec2d raydir;
	double	raylen;
	double camera;
	int	i;
	
	dir.x = cos(player->dir);
	dir.y = sin(player->dir);
	i = 0;
	while (i < WIN_W)
	{
		camera = 2.0 * i / WIN_W - 1;
		raydir.x = dir.x - dir.y * camera;
		raydir.y = dir.y + dir.x * camera;
		raylen = dda(&raydir, map, player);
		draw_cub3d_line(cub, i, raylen, raydir);
		draw_ray_minimap(minimap, player, raylen, raydir);
		i++;
	}
}
