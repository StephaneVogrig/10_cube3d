/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/05 18:05:03 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "raycasting.h"

static inline int color_darkened(int color, int dark)
{
	if (dark)
		return (color >> 5) & 0xFF070707;
	return (color);
}

static inline int	texture_get_color(t_texture *t, int x, int y, int dark)
{
	return (color_darkened(mlx_get_image_pixel(t->mlx, t->img, x, y), dark));
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

static inline void	draw_texture_reduced(t_window *win, t_draw *d, double texture_dy,
														double texture_y)
{
	int color;
	
	while (d->pix.y < d->y_max)
	{
		d->texture_pixel.y = (int)texture_y;
		color = texture_get_color(	d->texture, d->texture_pixel.x,
									d->texture_pixel.y, d->dark);
 		mlx_pixel_put(win->mlx, win->win, d->pix.x, d->pix.y, color);
		texture_y += texture_dy;
		d->pix.y++;
	}
}

static inline void	draw_texture_enlarged(t_window *win, t_draw *d, double texture_dy,
														double texture_y)
{
	int color;
	
	d->texture_pixel.y = (int)texture_y;
	texture_y -= d->texture_pixel.y;
	color = texture_get_color(d->texture, d->texture_pixel.x,
									d->texture_pixel.y, d->dark);
	while (d->pix.y < d->y_max)
	{
		if (texture_y >= 1.0)
		{
			d->texture_pixel.y++;
			texture_y -= 1.0;
			color = texture_get_color(	d->texture, d->texture_pixel.x,
										d->texture_pixel.y, d->dark);
		}
 		mlx_pixel_put(win->mlx, win->win, d->pix.x, d->pix.y, color);
		texture_y += texture_dy;
		d->pix.y++;
	}
}

static inline void	draw_wall(t_window *win, t_draw *d, int wall_y, int wall_h)
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


static inline void	draw_floor(t_window *win, t_textures *textures, t_draw *d)
{
	int color_ceil;
	int color_floor;
	int	y_ceil;
	int y_floor;

	y_ceil = 0;
	y_floor = d->y_max;
	color_ceil = color_darkened(textures->ceil_rgb.integer, d->dark);
	color_floor = color_darkened(textures->floor_rgb.integer, d->dark);
	while (y_floor < win->height)
	{
		mlx_pixel_put(win->mlx, win->win, d->pix.x,	y_ceil, color_ceil);
		mlx_pixel_put(win->mlx, win->win, d->pix.x, y_floor, color_floor);
		y_floor++;
		y_ceil++;
	}
}

static inline void	draw_column(t_window *win, int col, t_ray *ray, t_textures *textures)
{
	t_draw	d;
	int		wall_y;
	int		wall_h;

	texture_init_hit(textures, ray, &d);
	d.pix.x = col;
	d.dark = ray->dark;
	wall_h = win->height / ray->len;
	if (wall_h < win->height)
	{
		d.pix.y =  (win->height - wall_h) / 2;
		d.y_max = d.pix.y + wall_h;
		draw_floor(win, textures, &d);
		wall_y = 0;
	}
	else
	{
		d.pix.y = 0;
		d.y_max = win->height;
		wall_y = (wall_h - win->height) / 2;
	}
	draw_wall(win, &d, wall_y, wall_h);
}

void	draw_ceil_floor(t_window *win, t_map *map)
{
	int x;
	int color_ceil;
	int color_floor;
	int	y_ceil;
	int y_floor;

	int lim = win->height / 2;
	color_ceil = map->textures.ceil_rgb.integer;
	color_floor = map->textures.floor_rgb.integer;
	y_ceil = 0;
	y_floor = lim;
	while (y_ceil < lim)
	{
		x = 0;
		while (x < win->width)
		{
			mlx_pixel_put(win->mlx, win->win, x, y_ceil, color_ceil);
			mlx_pixel_put(win->mlx, win->win, x, y_floor, color_floor);
			x++;
		}
		y_ceil++;
		y_floor++;
	}
}

void	raycasting(t_window *win, t_map *map, t_player *player, t_ray *rays)
{
	t_vec2d	dir;
	double camera;
	int	i;

	dir.x = cos(player->dir);
	dir.y = sin(player->dir);
	camera = -1;
	double step_camera = 2.0 / win->width;

	// draw_ceil_floor(win, map);

	i = 0;
	while (i < win->width)
	{
		rays->dir.x = dir.x - dir.y * camera;
		rays->dir.y = dir.y + dir.x * camera;
		dda(rays, map, player, win->height);
		draw_column(win, i, rays, &map->textures);
		camera += step_camera;
		i++;
		rays++;
	}
}
