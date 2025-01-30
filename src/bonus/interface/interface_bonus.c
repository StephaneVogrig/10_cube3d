/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:15:02 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/30 00:39:02 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface_bonus.h"

int	interface_scale(t_map *map)
{
	t_vec2i	scale;

	scale.x = MINIMAP_W / map->width;
	scale.y = MINIMAP_H / map->height;
	if (scale.y < scale.x)
		return (scale.y);
	return (scale.x);
}

void	interface_asset_destroy(t_texture *t)
{
	free(t->buffer);
}

void	interface_destroy(t_interface *interface)
{
	interface_asset_destroy(&interface->fg);
	interface_asset_destroy(&interface->bg);
	interface_asset_destroy(&interface->tiles);
	if (interface->img_fg)
		mlx_destroy_image(interface->mlx, interface->img_fg);
	if (interface->img_map)
		mlx_destroy_image(interface->mlx, interface->img_map);
	if (interface->img_bg)
		mlx_destroy_image(interface->mlx, interface->img_bg);
	if (interface->win)
		mlx_destroy_window(interface->mlx, interface->win);
}

int	interface_asset_setup(t_interface *interface)
{
	int		exit;
	void	*mlx;

	mlx = interface->mlx;
	exit = interface_setup_texture(mlx, &interface->fg, PATH_ASSET_FG);
	if (exit == FAIL)
		return (FAIL);
	exit = interface_setup_texture(mlx, &interface->bg, PATH_ASSET_BG);
	if (exit == FAIL)
		return (FAIL);
	exit = interface_setup_texture(mlx, &interface->tiles, PATH_ASSET_TILES);
	if (exit == FAIL)
		return (FAIL);
	interface_tiles_buffer_index(&interface->tiles_index, &interface->tiles);
	return (exit);
}

int	interface_setup(t_interface *interface, void *mlx, t_window *win,
		t_map *map)
{
	int	width;
	int	height;
	int	exit;

	interface->mlx = mlx;
	exit = interface_asset_setup(interface);
	if (exit != SUCCESS)
		return (exit);
	interface->win = mlx_new_window(mlx, MINIMAP_W, MINIMAP_H, "interface");
	if (interface->win == NULL)
		return (ft_return(ERROR, 25, "mlx_new_window failed",
					"interface_setup"));
	mlx_get_screens_size(mlx, interface->win, &width, &height);
	width = (width + win->width) / 2;
	height = (height - win->height) / 2;
	mlx_set_window_position(mlx, interface->win, width, height);
	interface->scale = interface_scale(map);
	draw_images(interface, map);
	return (exit);
}
