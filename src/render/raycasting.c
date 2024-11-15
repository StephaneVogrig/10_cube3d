/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/15 02:58:25 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "raycasting.h"

inline int	texture_get_color(t_texture *t, int x, int y, int dark)
{
	return (color_darkened(t->buffer[(x * t->height) + y], dark));
}

void	draw_wall_init_loop(int *y, int *y_max, double *texture_y, t_wall *wall)
{
	if (wall->height < WIN_H && wall->height > 0.0)
	{
		*y = (WIN_H - wall->height) / 2;
		*y_max = *y + wall->height;
		*texture_y = 0.0;
	}
	else
	{
		*y = 0;
		*y_max = WIN_H;
		*texture_y = (wall->texture->height - wall->texture_dy * WIN_H) / 2;
	}
}

void	draw_wall_big_pixel(t_window *win, int x, t_wall *wall, int dark)
{
	int		color;
	int		y;
	int		y_max;
	double	texture_y;
	t_vec2i	texture_pixel;

	draw_wall_init_loop(&y, &y_max, &texture_y, wall);
	texture_pixel.x = wall->x_in_texture;
	texture_pixel.y = (int)texture_y;
	texture_y -= texture_pixel.y;
	color = texture_get_color(wall->texture, texture_pixel.x, texture_pixel.y, dark);
	while (y < y_max)
	{
		if (texture_y >= 1.0)
		{
			texture_pixel.y++;
			texture_y -= 1.0;
			color = texture_get_color(wall->texture, texture_pixel.x, texture_pixel.y, dark);
		}
		mlx_pixel_put(win->mlx, win->win, x, y, color);
		texture_y += wall->texture_dy;
		y++;
	}
}

void	draw_wall_small_pixel(t_window *win, int x, t_wall *wall, int dark)
{
	int		color;
	int		y;
	int		y_max;
	double	texture_y;
	t_vec2i	texture_pixel;

	draw_wall_init_loop(&y, &y_max, &texture_y, wall);
	texture_pixel.x = wall->x_in_texture;
	while (y < y_max)
	{
		texture_pixel.y = (int)texture_y;
		color = texture_get_color(wall->texture, texture_pixel.x, texture_pixel.y, dark);
		mlx_pixel_put(win->mlx, win->win, x, y, color);
		texture_y += wall->texture_dy;
		y++;
	}
}

int	x_hit_in_texture(t_texture *texture, t_ray *ray)
{
	if (ray->hit_side == 'n')
		return ((1 - ray->hit_pos.x.box) * texture->width);
	if (ray->hit_side == 's')
		return (ray->hit_pos.x.box * texture->width);
	if (ray->hit_side == 'e')
		return ((1 - ray->hit_pos.y.box) * texture->width);
	return (ray->hit_pos.y.box * texture->width);
}

t_texture	*texture_hit(t_textures *textures, t_ray *ray)
{
	if (ray->hit_side == 'n')
		return (&textures->north);
	if (ray->hit_side == 's')
		return (&textures->south);
	if (ray->hit_side == 'e')
		return (&textures->east);
	return (&textures->west);
}

void	draw_wall(t_window *win, int x, t_ray *ray, t_textures *textures)
{
	t_wall wall;
	double	wall_h;

	wall_h = WIN_H / ray->len;
	if (wall_h < 1.0)
		return ;
	if (wall_h > INT_MAX)
		wall.height = INT_MAX;
	else
		wall.height = (int)wall_h;
	wall.texture = texture_hit(textures, ray);
	wall.x_in_texture = x_hit_in_texture(wall.texture, ray);
	wall.texture_dy = (double)wall.texture->height / wall.height;
	if (wall.texture_dy < 1)
		draw_wall_big_pixel(win, x, &wall, ray->dark);
	else
		draw_wall_small_pixel(win, x, &wall, ray->dark);
}

void	raycasting(t_window *win, t_map *map, t_player *player, t_ray *rays)
{
	t_vec2d	player_vdir;
	double	step_projection;
	t_vec2d	step_proj;
	t_vec2d projection;
	int		x;

	player_vdir.x = cos(player->dir);
	player_vdir.y = sin(player->dir);
	step_projection = 2.0 / WIN_W;
	step_proj.x = -player_vdir.y * step_projection;
	step_proj.y = player_vdir.x * step_projection;
	projection.x = player_vdir.x + player_vdir.y;
	projection.y = player_vdir.y - player_vdir.x;
	x = 0;
	while (x < WIN_W)
	{
		rays->vdir.x = projection.x;
		rays->vdir.y = projection.y;
		dda(rays, map, player, win->height);
		draw_wall(win, x, rays, &map->textures);
		projection.x += step_proj.x;
		projection.y += step_proj.y;
		rays++;
		x++;
	}
}
