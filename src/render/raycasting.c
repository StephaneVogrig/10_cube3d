/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/03 01:24:30 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "texture.h"

t_texture	*texture_hit(t_textures * textures, t_dda2 *ray)
{
	if (ray->hit_side == 'n')
		return (&textures->north);
	else if (ray->hit_side == 's')
		return (&textures->south);
	else if (ray->hit_side == 'e')
		return (&textures->east);
	return (&textures->west);
}

int	texture_hit_column(t_texture *texture, t_dda2 *ray)
{
	if (ray->hit_side == 'n')
		return ((1 - ray->hit_pos.box.x) * texture->width);
	else if (ray->hit_side == 's')
		return (ray->hit_pos.box.x * texture->width);
	else if (ray->hit_side == 'e')
		return ((1 - ray->hit_pos.box.y) * texture->width);
	return (ray->hit_pos.box.y * texture->width);
}

void	draw_wall(t_window *win, t_vec2i pix, t_dda2 *ray, t_texture *texture, int wall_h, int y_max, int y_wall)
{
	int color;
	t_vec2i texture_pix;
	double	texture_dy;
	double	texture_y;
	int		texture_pix_y_current;
	
	texture_dy = (double)texture->height / wall_h;
	texture_y = (double)y_wall * texture_dy;
	texture_pix.x = texture_hit_column(texture, ray);
	texture_pix_y_current = (int)texture_y;
	while (pix.y < y_max)
	{
		texture_pix.y = (int)texture_y;
		if (texture_pix_y_current != texture_pix.y)
		{
			texture_pix_y_current = texture_pix.y;
			color = mlx_get_image_pixel(win->mlx, texture->img, texture_pix.x, texture_pix.y);
		}
 		mlx_pixel_put(win->mlx, win->win, pix.x, pix.y, color);
		texture_y += texture_dy;
		pix.y++;
	}
}

void	draw_wall_only(t_window *win, t_vec2i pix, t_dda2 *ray, t_textures *textures)
{
	int wall_h;
	int y_max;
	int y_wall;
	t_texture	*texture;
	
	texture = texture_hit(textures, ray);	
	wall_h = win->height / ray->len;
	
	y_wall = (wall_h - win->height) / 2;
	y_max = win->height;
	
	int color;
	t_vec2i texture_pix;
	double	texture_dy;
	double	texture_y;
	
	texture_dy = (double)texture->height / wall_h;
	
	texture_y = (double)y_wall * texture_dy;
	texture_pix.x = texture_hit_column(texture, ray);
	texture_pix.y = (int)texture_y;
	texture_y -= texture_pix.y;
	color = mlx_get_image_pixel(win->mlx, texture->img, texture_pix.x, texture_pix.y);
	while (pix.y < y_max)
	{
		if (texture_y >= 1.0)
		{
			texture_pix.y++;
			texture_y -= 1.0;
			color = mlx_get_image_pixel(win->mlx, texture->img, texture_pix.x, texture_pix.y);
		}
 		mlx_pixel_put(win->mlx, win->win, pix.x, pix.y, color);
		texture_y += texture_dy;
		pix.y++;
	}
}

void	draw_ceil_wall_floor(t_window *win, t_vec2i pix, t_dda2 *ray, t_textures *textures)
{
	int cell_h;
	int wall_h;
	int y_max;
	int y_wall;
	t_texture	*texture;

	texture = texture_hit(textures, ray);
	wall_h = win->height / ray->len;
	cell_h = (win->height - wall_h) / 2;
	y_wall = 0;
	y_max = wall_h + cell_h;
	while (pix.y < cell_h)
	{
		mlx_pixel_put(win->mlx, win->win, pix.x, pix.y, textures->ceil_rgb.integer);
		pix.y++;
	}
	draw_wall(win, pix, ray, texture, wall_h, y_max, y_wall);
	pix.y = y_max;
	while (pix.y < win->height)
	{
		mlx_pixel_put(win->mlx, win->win, pix.x, pix.y, textures->floor_rgb.integer);
		pix.y++;
	}
}

void	draw_column(t_window *win, int col, t_dda2 *ray, t_textures *textures)
{
	t_vec2i	pixel;

	pixel.x = col;
	pixel.y = 0;
	
	if (ray->len > 1)
		draw_ceil_wall_floor(win, pixel, ray, textures);
	else
		draw_wall_only(win, pixel, ray, textures);
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
	// printf("intersect    x:   %f y:   %f\n", player->grid.x + player->box.x + raydir.x * raylen, player->grid.y + player->box.y + raydir.y * raylen);
	draw_line(&minimap->screen, player_pos, intersect, 0xFFFF0000);
}

void	raycasting(t_window *win, t_minimap *minimap, t_map *map, t_player *player)
{
	t_vec2d	dir;
	t_vec2d raydir;
	t_dda2 ray;
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
		ray = dda(&raydir, map, player);
		draw_column(win, i, &ray, &map->textures);
		draw_ray_minimap(minimap, player, ray.len, raydir);
		i++;
	}
}