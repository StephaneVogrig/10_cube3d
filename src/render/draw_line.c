/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:29:37 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/25 16:38:23 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_line.h"

void	bresenham(t_screen *screen, t_vec2i a, t_vec2i b, int color)
{
	int		err;
	int		e2;
	t_vec2i	d;
	t_vec2i	s;

	d.x = ft_abs(b.x - a.x);
	d.y = -ft_abs(b.y - a.y);
	s = increase(a, b);
	err = d.x + d.y;
	while (a.x != b.x || a.y != b.y)
	{
		e2 = err << 1;
		if (e2 >= d.y)
		{
			err += d.y;
			a.x += s.x;
		}
		else if (e2 <= d.x)
		{
			err += d.x;
			a.y += s.y;
		}
		mlx_pixel_put(screen->mlx, screen->win,a.x, a.y, color);
	}
}

void	draw_line_hor(t_screen *screen, t_vec2i a, t_vec2i b, int color)
{
	int		dx;

	if (a.x < b.x)
		dx = 1;
	else
		dx = -1;
	while (a.x != b.x)
	{
		mlx_pixel_put(screen->mlx, screen->win,a.x, a.y, color);
		a.x += dx;
	}
}

void	draw_line_diag(t_screen *screen, t_vec2i a, t_vec2i b, int color)
{
	t_vec2i	d;

	d = increase(a, b);
	while (a.x != b.x)
	{
		mlx_pixel_put(screen->mlx, screen->win,a.x, a.y, color);
		a.x += d.x;
		a.y += d.y;
	}
}

void	draw_line_vert(t_screen *screen, t_vec2i a, t_vec2i b, int color)
{
	int		dy;

	if (a.y == b.y)
		return ;
	if (a.y < b.y)
		dy = 1;
	else
		dy = -1;
	while (a.y != b.y)
	{
		mlx_pixel_put(screen->mlx, screen->win,a.x, a.y, color);
		a.y += dy;
	}
}

void	draw_line(t_screen *screen, t_vec2i a, t_vec2i b, int color)
{
	if ((a.x >= screen->width && b.x >= screen->width) || (a.x < 0 && b.x < 0))
		return ;
	if ((a.y >= screen->height && b.y >= screen->height) || (a.y < 0 && b.y < 0))
		return ;
	if (a.x == b.x)
		draw_line_vert(screen, a, b, color);
	else if (a.y == b.y)
		draw_line_hor(screen, a, b, color);
	else if (ft_abs(b.x - a.x) == ft_abs(b.y - a.y))
		draw_line_diag(screen, a, b, color);
	else
		bresenham(screen, a, b, color);
}
