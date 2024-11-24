/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:18:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/24 02:48:40 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "data_bonus.h"

void	data_init(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	data->key.down = 0;
}

int	data_setup(t_data *data, char *map_path)
{
	t_lstmap	*lst_map;
	t_tex_path	tex_path;
	int			exit_code;

	lst_map = NULL;
	ft_bzero(&tex_path, sizeof(tex_path));
	exit_code = file_load(map_path, &lst_map);
	if (exit_code == SUCCESS)
		exit_code = lstmap_extract_info(&lst_map, &data->map, &tex_path,
				map_path);
	delete_all_lstmap(&lst_map);
	if (exit_code == SUCCESS)
		exit_code = map_checker(&data->map, &data->player);
	if (exit_code == SUCCESS)
		exit_code = mlx_setup(&data->win, &tex_path, &data->map.textures);
	data->mlx = data->win.mlx;
	tex_path_clean(&tex_path);
	return (exit_code);
}

void	data_clean(t_data *data)
{
	printf("data_clean\n");
	data->map.grid = ft_tab_f(data->map.grid);
	textures_buffer_clean(&data->map.textures);
	window_destroy(&data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
}
