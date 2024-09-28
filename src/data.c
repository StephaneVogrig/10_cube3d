/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:18:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/28 18:27:21 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	player_setup(t_player *player, t_map *map)
{
	player->grid.x = map->width / 2;
	player->grid.y = map->height / 2;
	player->box.x = 0.5;
	player->box.y = 0.5;
	player->dir = 0;
}

// int	file_load(char *path, t_map *map, t_player *player)
int	file_load(char *path, t_data *data)
{
	printf("map_load\n");
	(void)path;
	(void)data;
	if (map_setup(&data->map) == FAIL)
		return (FAIL);
	// player_setup(&data->player, &data->map);
	// if (texture_setup(&data->map.textures.north, data->mlx,
	// 		"maps/test/ROCKNO.bmp") == FAIL)
	// 	return (FAIL);
	// if (texture_setup(&data->map.textures.south, data->mlx,
	// 		"maps/test/ROCKSO.bmp") == FAIL)
	// 	return (FAIL);
	// if (texture_setup(&data->map.textures.east, data->mlx,
	// 		"maps/test/ROCKEA.bmp") == FAIL)
	// 	return (FAIL);
	// // if (texture_setup(&data->map.textures.west, data->mlx,
	// 		// "maps/test/ROCKWE.bmp") == FAIL)
	// // 	return (FAIL);
	// if (texture_jpg_setup(&data->map.textures.west, data->mlx,
	// 		// "maps/test/svogrig_42.jpeg") == FAIL)
	// 	return (FAIL);
	// // printf("width: %i Height: %i\n", data->map.width, data->map.height);
	// // printf("texture north width: %i Height: %i\n",
	// data->map.tex_north.width,
	// 	data->map.tex_north.height);
	return (SUCCESS);
}

void	data_init(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	data->key.down = 0;
}

int	data_setup(t_data *data, char *pathname)
{
	printf("data_setup\n"); // debug
	(void)pathname;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (FAIL);
	// if (file_load(pathname, &data->map, &data->player) == FAIL)
	// 	return (FAIL);
	// if (file_load(pathname, data) == FAIL)
	// 	return (FAIL);
	// if (window_setup(&data->win, data->mlx) == FAIL)
	// 	return (FAIL);
	// if (minimap_setup(data->mlx, &data->minimap, &data->map) == FAIL)
	// 	return (FAIL);
	return (SUCCESS);
}

void	data_clean(t_data *data)
{
	printf("data_clean\n");
	window_clean(&data->win);
	textures_clean(&data->map.textures, data->mlx);
	if (data->minimap.screen.img)
		mlx_destroy_image(data->mlx, data->minimap.screen.img);
	if (data->minimap.screen.win)
		mlx_destroy_window(data->mlx, data->minimap.screen.win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
}
