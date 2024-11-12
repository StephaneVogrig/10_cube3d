/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/12 22:26:02 by svogrig          ###   ########.fr       */
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

void	texture_init_hit(t_textures * textures, t_ray *ray, t_draw *d)
{
	if (ray->hit_side == 'n')
	{
		d->texture = &textures->north;
		d->texture_pixel.x = (1 - ray->hit_pos.x.box) * d->texture->width;
	}
	else if (ray->hit_side == 's')
	{
		d->texture = &textures->south;
		d->texture_pixel.x = ray->hit_pos.x.box * d->texture->width;
	}
	else if (ray->hit_side == 'e')
	{
		d->texture = &textures->east;
		d->texture_pixel.x = (1 - ray->hit_pos.y.box) * d->texture->width;
	}
	else
	{
		d->texture = &textures->west;
		d->texture_pixel.x = ray->hit_pos.y.box * d->texture->width;
	}
}

void	draw_wall_smaller_win(t_window *win, int x, t_ray *ray, t_textures *textures)
{
	int color;
	int	y;
	int		y_max;
	int	texture_pixel_y;
	double	texture_dy;
	double	texture_y;
	t_draw	d;
	int		wall_h;

	texture_init_hit(textures, ray, &d);
	d.dark = ray->dark;
	wall_h = win->height / ray->len;
	texture_dy = (double)d.texture->height / wall_h;
	texture_y = 0;
	y = (win->height - wall_h) / 2;
	y_max = y + wall_h;
	while (y < y_max)
	{
		texture_pixel_y = (int)texture_y;
		color = texture_get_color(d.texture, d.texture_pixel.x,
									texture_pixel_y, d.dark);
		mlx_pixel_put(win->mlx, win->win, x, y, color);
		texture_y += texture_dy;
		y++;
	}
}

void	draw_wall_bigger_win(t_window *win, int x, t_ray *ray, t_textures *textures)
{
	int color;
	int	y;
	int	texture_pixel_y;
	double	texture_dy;
	double	texture_y;
	t_draw	d;
	int		wall_h;

	texture_init_hit(textures, ray, &d);
	d.dark = ray->dark;
	wall_h = win->height / ray->len;
	texture_dy = (double)d.texture->height / wall_h;
	texture_y = (double)((wall_h - win->height) / 2) * texture_dy;
	texture_pixel_y = (int)texture_y;
	texture_y -= texture_pixel_y;
	color = texture_get_color(d.texture, d.texture_pixel.x,
									texture_pixel_y, d.dark);
	y = 0;
	while (y < WIN_H)
	{
		if (texture_y >= 1.0)
		{
			texture_pixel_y++;
			texture_y -= 1.0;
			color = texture_get_color(d.texture, d.texture_pixel.x,
										texture_pixel_y, d.dark);
		}
		mlx_pixel_put(win->mlx, win->win, x, y, color);
		texture_y += texture_dy;
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
