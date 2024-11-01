/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:18:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/01 17:51:31 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	data_init(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	data->key.down = 0;
}

int	mlx_setup(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ft_return(ERROR, 258, "Error on mlx_init"));
	textures_set_mlx(&data->map.textures, data->mlx);
	return (SUCCESS);
}

int	data_setup(t_data *data, char *map_path)
{
	t_lstmap	*lst_map;
	int			exit_code;

	lst_map = NULL;
	exit_code = mlx_setup(data);
	if (exit_code != SUCCESS)
		return (exit_code);
	exit_code = file_load(map_path, &lst_map);
	if (exit_code != SUCCESS)
		return (exit_code);
	exit_code = lstmap_extraction_info(&lst_map, &data->map, map_path);
	delete_all_lstmap(&lst_map);
	if (exit_code == FAIL)
		return (FAIL);
	if (map_checker(&data->map, &data->player) == FAIL)
		return (ft_return(ERROR, FAIL, "Map Invalid"));
	return (SUCCESS);
}

void	data_clean(t_data *data)
{
	printf("data_clean\n");
	data->map.grid = ft_tab_f(data->map.grid);
	textures_clean(&data->map.textures, data->mlx);
	window_clean(&data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
}
