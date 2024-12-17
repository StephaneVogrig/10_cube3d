/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:18:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/12/17 17:11:09 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_bonus.h"
#include "debug.h"

void	data_init(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	data->key.down = 0;
}

int	data_setup(t_data *data, char *map_path)
{
	t_asset_lst		*asset_lst;
	t_sprite_lst	*sprite_lst;
	int				exit_code;

	asset_lst = NULL;
	sprite_lst = NULL;
	exit_code = lstmap_extract_info(&data->map, map_path, &asset_lst, &sprite_lst);
	if (exit_code == SUCCESS)
		exit_code = map_checker(&data->map, &data->player);
	if (exit_code == SUCCESS)
		exit_code = mlx_setup(&data->win, &data->textures, &asset_lst);
	data->mlx = data->win.mlx;
	delete_all_asset_lst(&asset_lst);
	// if (exit_code == SUCCESS)
	// 	exit_code =	sprite_setup(&data->sprite);
	// print_sprite_lst(sprite_lst);
	delete_all_sprite(&sprite_lst);
	return (exit_code);
}

void	data_clean(t_data *data)
{
	printf("data_clean\n");
	data->map.grid = ft_tab_f(data->map.grid);
	asset_destroy(&data->textures);
	window_destroy(&data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	sprite_destroy(&data->sprite);
}
