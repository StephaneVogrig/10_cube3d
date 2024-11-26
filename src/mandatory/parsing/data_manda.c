/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:18:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/26 18:04:41 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_manda.h"

void	data_init(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	data->key.down = 0;
}

int	mlx_setup(t_data *data, t_assets *assets)
{
	int	exit_code;

	(void)data;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ft_return(ERROR, 258, "Error on mlx_init"));
	exit_code = asset_load_to_buffer(data->mlx, &textures->north, tex_path->no);
	exit_code |= asset_load_to_buffer(data->mlx, &textures->south,
			tex_path->so);
	exit_code |= asset_load_to_buffer(data->mlx, &textures->east, tex_path->ea);
	exit_code |= asset_load_to_buffer(data->mlx, &textures->west, tex_path->we);
	if (exit_code == SUCCESS)
		exit_code = window_setup(&data->win, data->mlx);
	return (exit_code);
}

int	data_setup(t_data *data, char *map_path)
{
	int			exit_code;
	t_lstmap	*lst_map;

	lst_map = NULL;
	exit_code = file_load(map_path, &lst_map);
	if (exit_code == SUCCESS)
		exit_code = lstmap_extract_info(&data->assets, &data->map, &lst_map,
				map_path);
	if (exit_code == SUCCESS)
		exit_code = map_checker(&data->map, &data->player);
	if (exit_code == SUCCESS)
		exit_code = mlx_setup(data, &data->assets);
	delete_all_lstmap(&lst_map);
	return (exit_code);
}

void	data_clean(t_data *data)
{
	printf("data_clean\n");
	data->map.grid = ft_tab_f(data->map.grid);
	textures_buffer_clean(&data->textures);
	window_destroy(&data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
}
