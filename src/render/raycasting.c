/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/12 23:18:02 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "raycasting.h"

inline int color_darkened(int color, int dark)
{
	if (dark)
		return (color >> 5) & 0xFF070707;
	return (color);
}

inline int	texture_get_color(t_texture *t, int x, int y, int dark)
{
	return (color_darkened(t->buffer[(x * t->height) + y], dark));
}

void	texture_init_hit(t_textures * textures, t_ray *ray, t_draw_texture *draw)
{
	if (ray->hit_side == 'n')
	{
		draw->img = &textures->north;
		draw->pixel.x = (1 - ray->hit_pos.x.box) * draw->img->width;
	}
	else if (ray->hit_side == 's')
	{
		draw->img = &textures->south;
		draw->pixel.x = ray->hit_pos.x.box * draw->img->width;
	}
	else if (ray->hit_side == 'e')
	{
		draw->img = &textures->east;
		draw->pixel.x = (1 - ray->hit_pos.y.box) * draw->img->width;
	}
	else
	{
		draw->img = &textures->west;
		draw->pixel.x = ray->hit_pos.y.box * draw->img->width;
	}
}

void	draw_wall_smaller_win(t_window *win, int x, t_ray *ray, t_textures *textures)
{
	t_draw_texture	texture;
	int 			color;
	int				y;
	int				wall_h;
	int				y_max;

	texture_init_hit(textures, ray, &texture);
	wall_h = win->height / ray->len;
	texture.dy = (double)texture.img->height / wall_h;
	texture.y = 0;
	y = (win->height - wall_h) / 2;
	y_max = y + wall_h;
	while (y < y_max)
	{
		texture.pixel.y = (int)texture.y;
		color = texture_get_color(texture.img, texture.pixel.x, texture.pixel.y, ray->dark);
		mlx_pixel_put(win->mlx, win->win, x, y, color);
		texture.y += texture.dy;
		y++;
	}
}

void	draw_wall_bigger_win(t_window *win, int x, t_ray *ray, t_textures *textures)
{
	t_draw_texture	texture;
	int 			color;
	int				y;
	int				wall_h;

	texture_init_hit(textures, ray, &texture);
	wall_h = win->height / ray->len;
	texture.dy = (double)texture.img->height / wall_h;
	texture.y = (double)((wall_h - win->height) / 2) * texture.dy;
	texture.pixel.y = (int)texture.y;
	texture.y -= texture.pixel.y;
	y = 0;
	color = texture_get_color(texture.img, texture.pixel.x, texture.pixel.y, ray->dark);
	while (y < WIN_H)
	{
		if (texture.y >= 1.0)
		{
			texture.pixel.y++;
			texture.y -= 1.0;
			color = texture_get_color(texture.img, texture.pixel.x, texture.pixel.y, ray->dark);
		}
		mlx_pixel_put(win->mlx, win->win, x, y, color);
		texture.y += texture.dy;
		y++;
	}
}

void	draw_wall(t_window *win, int x, t_ray *ray, t_textures *textures)
{
	if (ray->len > 1.0)
		draw_wall_smaller_win(win, x, ray, textures);
	else
		draw_wall_bigger_win(win, x, ray, textures);
}

void	raycasting(t_window *win, t_map *map, t_player *player, t_ray *rays)
{
	t_vec2d	player_vdir;
	t_vec2d	step_cam;
	t_vec2d cam;
	double	step_camera;
	int		x;

	player_vdir.x = cos(player->dir);
	player_vdir.y = sin(player->dir);
	step_camera = 2.0 / WIN_W;
	step_cam.x = player_vdir.y * step_camera;
	step_cam.y = player_vdir.x * step_camera;
	cam.x = -player_vdir.y;
	cam.y = -player_vdir.x;
	x = 0;
	while (x < WIN_W)
	{
		rays->vdir.x = player_vdir.x - cam.x;
		rays->vdir.y = player_vdir.y + cam.y;
		dda(rays, map, player, win->height);
		draw_wall(win, x, rays, &map->textures);
		cam.x += step_cam.x;
		cam.y += step_cam.y;
		rays++;
		x++;
	}
}
