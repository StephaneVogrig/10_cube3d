/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/06 04:05:25 by stephane         ###   ########.fr       */
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
	int	y;
	
	y = d->y_start;
	while (y < d->y_end)
	{
		d->texture_pixel.y = (int)texture_y;
		color = texture_get_color(	d->texture, d->texture_pixel.x,
									d->texture_pixel.y, d->dark);
		mlx_pixel_put(win->mlx, win->win, d->x, y, color);
		texture_y += texture_dy;
		y++;
	}
}

static inline void	draw_texture_enlarged(t_window *win, t_draw *d, double texture_dy,
														double texture_y)
{
	int color;
	int	y;
	int	texture_pixel_y;
	
	texture_pixel_y = (int)texture_y;
	texture_y -= texture_pixel_y;
	color = texture_get_color(d->texture, d->texture_pixel.x,
									texture_pixel_y, d->dark);
	y = d->y_start;
	while (y < d->y_end)
	{
		if (texture_y >= 1.0)
		{
			texture_pixel_y++;
			texture_y -= 1.0;
			color = texture_get_color(	d->texture, d->texture_pixel.x,
										texture_pixel_y, d->dark);
		}
		mlx_pixel_put(win->mlx, win->win, d->x, y, color);
		texture_y += texture_dy;
		y++;
	}
}

void	draw_wall(t_window *win, t_draw *d, int wall_y_start, int wall_h)
{
	double	texture_dy;
	double	texture_y_start;

	texture_dy = (double)d->texture->height / wall_h;
	texture_y_start = (double)wall_y_start * texture_dy;
	if (d->texture->height >= wall_h)
		draw_texture_reduced(win, d, texture_dy, texture_y_start);
	else
		draw_texture_enlarged(win, d, texture_dy, texture_y_start);
}

static inline void	draw_column(t_window *win, int col, t_ray *ray, t_textures *textures)
{
	t_draw	d;
	int		wall_h;
	int		wall_y_start;

	texture_init_hit(textures, ray, &d);
	d.x = col;
	d.dark = ray->dark;
	wall_h = win->height / ray->len;
	if (wall_h < win->height)
	{
		d.y_start = (win->height - wall_h) / 2;
		d.y_end = d.y_start + wall_h;
		// draw_floor(win, textures, &d);
		wall_y_start = 0;
	}
	else
	{
		d.y_start = 0;
		d.y_end = win->height;
		wall_y_start = (wall_h - win->height) / 2;
	}
	draw_wall(win, &d, wall_y_start, wall_h);
}

void	raycasting(t_window *win, t_map *map, t_player *player, t_ray *rays)
{
	t_vec2d	dir;
	double camera;
	double step_camera;
	int	i;

	dir.x = cos(player->dir);
	dir.y = sin(player->dir);
	camera = -1;
	step_camera = 2.0 / win->width;

	i = 0;
	while (i < win->width)
	{
		rays->dir.x = dir.x - dir.y * camera;
		rays->dir.y = dir.y + dir.x * camera;
		dda(rays, map, player, win->height);
		// draw_column(win, i, rays, &map->textures);
		camera += step_camera;
		i++;
		rays++;
	}
}

void	render_draw_wall(t_window *win, t_map *map, t_ray *rays)
{
	int	i;

	i = 0;
	while (i < win->width)
	{
		draw_column(win, i, rays, &map->textures);
		i++;
		rays++;
	}
}
