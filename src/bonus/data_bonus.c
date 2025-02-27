/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:18:30 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/05 20:37:01 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_bonus.h"

void	data_init(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	data->key.down = 0;
	data->tg_fov_2 = tan((FOV / 2) * (PI / 180));
	data->collision_enable = 1;
	data->fog_enable = 1;
}

int	data_setup(t_data *data, char *map_path)
{
	t_asset_lst		*asset_lst;
	t_sprite_lst	*sprite_lst;
	int				exit_code;

	asset_lst = NULL;
	sprite_lst = NULL;
	exit_code = lstmap_extract_info(&data->map, map_path, &asset_lst,
			&sprite_lst);
	if (exit_code == SUCCESS)
		exit_code = map_setup(&data->map, &data->player);
	if (exit_code == SUCCESS)
		exit_code = mlx_setup(&data->win, &data->textures, &asset_lst);
	data->mlx = data->win.mlx;
	delete_all_asset_lst(&asset_lst);
	if (exit_code == SUCCESS)
		exit_code = ray_setup(&data->rays, data->win.width);
	if (exit_code == SUCCESS)
		exit_code = sprite_setup(&data->sprite, sprite_lst, &data->textures);
	delete_all_sprite(&sprite_lst);
	if (exit_code == SUCCESS)
		exit_code = interface_setup(&data->minimap, data->mlx, &data->win);
	if (exit_code == SUCCESS)
		data->scale_screen = (data->win.width / 2) / data->tg_fov_2;
	return (exit_code);
}

void	data_clean(t_data *data)
{
	ft_tab_f(data->map.grid);
	asset_destroy(&data->textures);
	window_destroy(&data->win);
	ray_destroy(&data->rays);
	interface_destroy(&data->minimap);
	sprite_destroy(&data->sprite);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
}
