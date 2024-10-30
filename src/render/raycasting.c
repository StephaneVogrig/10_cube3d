/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/30 23:12:56 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	texture_init_hit(t_textures * textures, t_ray *ray, t_draw *d)
{
	if (ray->hit_side == 'n')
	{
		d->texture = &textures->north;
		d->texture_pixel.x = (1 - ray->hit_pos.box.x) * d->texture->width;
	}
	else if (ray->hit_side == 's')
	{
		d->texture = &textures->south;
		d->texture_pixel.x = ray->hit_pos.box.x * d->texture->width;
	}
	else if (ray->hit_side == 'e')
	{
		d->texture = &textures->east;
		d->texture_pixel.x = (1 - ray->hit_pos.box.y) * d->texture->width;
	}
	else
	{
		d->texture = &textures->west;
		d->texture_pixel.x = ray->hit_pos.box.y * d->texture->width;
	}
}

void	draw_texture_reduced(t_window *win, t_draw *d, double texture_dy, \
														double texture_y)
{
	int color;
	
	while (d->pix.y < d->y_max)
	{
		d->texture_pixel.y = (int)texture_y;
		color = mlx_get_image_pixel(win->mlx, d->texture->img, \
									d->texture_pixel.x, d->texture_pixel.y);
 		mlx_pixel_put(win->mlx, win->win, d->pix.x, d->pix.y, color);
		texture_y += texture_dy;
		d->pix.y++;
	}
}

void	draw_texture_enlarged(t_window *win, t_draw *d, double texture_dy, \
														double texture_y)
{
	int color;
	
	d->texture_pixel.y = (int)texture_y;
	texture_y -= d->texture_pixel.y;
	color = mlx_get_image_pixel(win->mlx, d->texture->img, d->texture_pixel.x, 
														d->texture_pixel.y);
	while (d->pix.y < d->y_max)
	{
		if (texture_y >= 1.0)
		{
			d->texture_pixel.y++;
			texture_y -= 1.0;
			color = mlx_get_image_pixel(win->mlx, d->texture->img, \
									d->texture_pixel.x, d->texture_pixel.y);
		}
 		mlx_pixel_put(win->mlx, win->win, d->pix.x, d->pix.y, color);
		texture_y += texture_dy;
		d->pix.y++;
	}
}

void	draw_wall(t_window *win, t_draw *d, int wall_y, int wall_h)
{
	double	texture_dy;
	double	texture_y;

	texture_dy = (double)d->texture->height / wall_h;
	texture_y = (double)wall_y * texture_dy;
	if (d->texture->height >= wall_h)
		draw_texture_reduced(win, d, texture_dy, texture_y);
	else
		draw_texture_enlarged(win, d, texture_dy, texture_y);
}

void	draw_ceil_wall_floor(t_window *win, t_textures *textures, \
													t_draw *d, int wall_h)
{
	int ceil_h;

	ceil_h = (win->height - wall_h) / 2;
	while (d->pix.y < ceil_h)
	{
		mlx_pixel_put(win->mlx, win->win, d->pix.x, d->pix.y, \
												textures->ceil_rgb.integer);
		d->pix.y++;
	}
	d->y_max = wall_h + ceil_h;
	draw_wall(win, d, 0, wall_h);
	d->pix.y = d->y_max;
	while (d->pix.y < win->height)
	{
		mlx_pixel_put(win->mlx, win->win, d->pix.x, d->pix.y, \
												textures->floor_rgb.integer);
		d->pix.y++;
	}
}

void	draw_column(t_window *win, int col, t_ray *ray, t_textures *textures)
{
	t_draw	d;
	int		wall_y;
	int		wall_h;

	texture_init_hit(textures, ray, &d);
	d.pix.x = col;
	d.pix.y = 0;
	wall_h = win->height / ray->len;
	if (ray->len > 1)
		draw_ceil_wall_floor(win, textures, &d, wall_h);
	else
	{
		d.y_max = win->height;
		wall_y = (wall_h - win->height) / 2;
		draw_wall(win, &d, wall_y, wall_h);
	}
}

void	raycasting(t_window *win, t_minimap *minimap, t_map *map, \
															t_player *player)
{
	t_vec2d	dir;
	t_vec2d raydir;
	t_ray ray;
	double camera;
	int	i;
	
	(void)minimap; // Makefile
	dir.x = cos(player->dir);
	dir.y = sin(player->dir);
	i = 0;
	camera = -1;
	double step_camera = 2.0 / WIN_W;
	while (i < WIN_W)
	{
		raydir.x = dir.x - dir.y * camera;
		raydir.y = dir.y + dir.x * camera;
		ray = dda(&raydir, map, player, win->height);
		draw_column(win, i, &ray, &map->textures);
		camera += step_camera;
		// minimap_draw_ray(minimap, player, ray.len, raydir); // Makefile
		i++;
	}
}
