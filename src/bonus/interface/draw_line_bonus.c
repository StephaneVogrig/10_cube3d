// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   draw_line_bonus.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/09/12 18:29:37 by svogrig           #+#    #+#             */
// /*   Updated: 2025/01/07 23:54:23 by aska             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "draw_line_bonus.h"

// void	bresenham(t_interface *minimap, t_vec2i a, t_vec2i b, int color)
// {
// 	int		err;
// 	int		e2;
// 	t_vec2i	d;
// 	t_vec2i	s;

// 	d.x = ft_abs(b.x - a.x);
// 	d.y = -ft_abs(b.y - a.y);
// 	s = increase(a, b);
// 	err = d.x + d.y;
// 	while (a.x != b.x || a.y != b.y)
// 	{
// 		e2 = err << 1;
// 		if (e2 >= d.y)
// 		{
// 			err += d.y;
// 			a.x += s.x;
// 		}
// 		else if (e2 <= d.x)
// 		{
// 			err += d.x;
// 			a.y += s.y;
// 		}
// 		mlx_pixel_put(minimap->mlx, minimap->win,a.x, a.y, color);
// 	}
// }

// void	draw_line_hor(t_interface *minimap, t_vec2i a, t_vec2i b, int color)
// {
// 	int		dx;

// 	if (a.x < b.x)
// 		dx = 1;
// 	else
// 		dx = -1;
// 	while (a.x != b.x)
// 	{
// 		mlx_pixel_put(minimap->mlx, minimap->win,a.x, a.y, color);
// 		a.x += dx;
// 	}
// }

// void	draw_line_diag(t_interface *minimap, t_vec2i a, t_vec2i b, int color)
// {
// 	t_vec2i	d;

// 	d = increase(a, b);
// 	while (a.x != b.x)
// 	{
// 		mlx_pixel_put(minimap->mlx, minimap->win,a.x, a.y, color);
// 		a.x += d.x;
// 		a.y += d.y;
// 	}
// }

// void	draw_line_vert(t_interface *minimap, t_vec2i a, t_vec2i b, int color)
// {
// 	int		dy;

// 	if (a.y == b.y)
// 		return ;
// 	if (a.y < b.y)
// 		dy = 1;
// 	else
// 		dy = -1;
// 	while (a.y != b.y)
// 	{
// 		mlx_pixel_put(minimap->mlx, minimap->win,a.x, a.y, color);
// 		a.y += dy;
// 	}
// }

// void	draw_line(t_interface *minimap, t_vec2i a, t_vec2i b, int color)
// {
// 	if ((a.x >= MINIMAP_W && b.x >= MINIMAP_W) || (a.x < 0 && b.x < 0))
// 		return ;
// 	if ((a.y >= MINIMAP_H && b.y >= MINIMAP_H) || (a.y < 0 && b.y < 0))
// 		return ;
// 	if (a.x == b.x)
// 		draw_line_vert(minimap, a, b, color);
// 	else if (a.y == b.y)
// 		draw_line_hor(minimap, a, b, color);
// 	else if (ft_abs(b.x - a.x) == ft_abs(b.y - a.y))
// 		draw_line_diag(minimap, a, b, color);
// 	else
// 		bresenham(minimap, a, b, color);
// }
