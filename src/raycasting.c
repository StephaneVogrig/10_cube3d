/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/29 23:48:28 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "texture.h"

int	pixel_color(char side, t_vec2i pos, void *mlx, t_texture *texture)
{
	int	color;
	
	if (side == 'n')
		color = 0xff3f0000;
	if (side == 'w')
		color = 0xff7f0000;
	if (side == 'e')
		color = 0xffbf0000;
	if (side == 's')
		color = 0xffff0000;

	if (side == 'n')
		color = mlx_get_image_pixel(mlx, texture->img, pos.x, pos.y);
	return (color);
}

void	draw_cub3d_col(t_window *win, int x, t_dda2 *ray, t_textures *textures)
{
	int	y;
	int wall_h;
	int cell_h;
	int color;
	int y_max;
	int y_wall;
	t_texture	*texture;
	

	if (ray->hit_side == 'n')
		texture = &textures->north;
	if (ray->hit_side == 's')
		texture = &textures->south;
	if (ray->hit_side == 'e')
		texture = &textures->east;
	if (ray->hit_side == 'w')
		texture = &textures->west;
	
	wall_h = win->height / ray->len;
	if (ray->len <= 1)
	{
		cell_h = 0;
		y_wall = (wall_h - win->height) / 2;
	}
	else
	{
		cell_h = (win->height - wall_h) / 2;
		y_wall = 0;
	}
	y = 0;
	while (y < cell_h)
	{
		mlx_pixel_put(win->mlx, win->win, x, y, textures->ceil_rgb.integer);
		y++;
	}
	
	t_vec2i texture_pos;
	if (ray->hit_side == 'n')
		texture_pos.x = (1 - ray->hit_pos.box.x) * texture->width;
	else if (ray->hit_side == 's')
		texture_pos.x = ray->hit_pos.box.x * texture->width;
	else if (ray->hit_side == 'e')
		texture_pos.x = (1 - ray->hit_pos.box.y) * texture->width;
	else if (ray->hit_side == 'w')
		texture_pos.x = ray->hit_pos.box.y * texture->width;
	
	y_max = wall_h + cell_h;
	if (y_max > win->height)
		y_max =  win->height;
	texture_pos.y = 0;
	while (y < y_max)
	{
		texture_pos.y = y_wall * texture->height / wall_h;
		// color = pixel_color(ray->hit_side, texture_pos, win->mlx, texture);
		color = mlx_get_image_pixel(win->mlx, texture->img, texture_pos.x, texture_pos.y);
 		mlx_pixel_put(win->mlx, win->win, x, y, color);
		y_wall++;
		y++;
	}
	
	while (y < win->height)
	{
		mlx_pixel_put(win->mlx, win->win, x, y, textures->floor_rgb.integer);
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
		draw_cub3d_col(win, i, &ray, &map->textures);
		draw_ray_minimap(minimap, player, ray.len, raydir);
		i++;
	}
}
