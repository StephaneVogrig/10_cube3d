/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:15:48 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/06 19:31:48 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "raycasting.h"

int color_darkened(int color, int dark)
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

void	draw_texture_reduced(t_window *win, t_draw *d, double texture_dy,
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

void	draw_texture_enlarged(t_window *win, t_draw *d, double texture_dy,
														double texture_y)
{
	int color;
	
	d->texture_pixel.y = (int)texture_y;
	texture_y -= d->texture_pixel.y;
		color = texture_get_color(	d->texture, d->texture_pixel.x,
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

void	draw_column(t_window *win, int col, t_ray *ray, t_textures *textures)
{
	t_draw	d;
	int		wall_y;
	int		wall_h;
	int		ceil_h;

	texture_init_hit(textures, ray, &d);
	d.pix.x = col;
	d.dark = ray->dark;
	wall_h = win->height / ray->len;
	ceil_h = (win->height - wall_h) / 2;
	if (ray->len > 1.0)
	{
		d.pix.y = ceil_h;
		d.y_max = wall_h + ceil_h;
		draw_wall(win, &d, 0, wall_h);
	}
	else
	{
		d.pix.y = 0;
		d.y_max = win->height;
		wall_y = (wall_h - win->height) / 2;
		draw_wall(win, &d, wall_y, wall_h);
	}
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
	step_camera = 2.0 / WIN_W;
	i = 0;
	while (i < WIN_W)
	{
		rays->dir.x = dir.x - dir.y * camera;
		rays->dir.y = dir.y + dir.x * camera;
		dda(rays, map, player, win->height);
		draw_column(win, i, rays, &map->textures);
		camera += step_camera;
		rays++;
		i++;
	}
}
