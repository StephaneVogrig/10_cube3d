/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:18:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/22 13:03:13 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

int	file_load(char *path, t_lstmap **lst_map)
{
	int	fd;
	int	exit_code;

	if (open_file(&fd, path) == FAIL)
		return (FAIL);
	exit_code = file_to_lst_map(fd, lst_map);
	exit_code |= close_file(&fd);
	return (exit_code);
}

void	data_init(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	data->key.down = 0;
}

int	mlx_setup(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ft_return(ERROR, FAIL, "Error on mlx_init"));
	if (window_setup(&data->win, data->mlx) == FAIL)
		return (FAIL);
	if (minimap_setup(data->mlx, &data->minimap, &data->map) == FAIL)
		return (FAIL);
	textures_set_mlx(&data->map.textures, data->mlx);
	return (chk_box(SUCCESS, EQ, SUCCESS, "mlx initialization"));
}

int	data_setup(t_data *data, char *pathname)
{
	t_lstmap	*lst_map;

	lst_map = NULL;
	data_init(data);
	// if (mlx_setup(data) == FAIL)
	// 	return (FAIL);
	if (file_load(pathname, &lst_map) == FAIL)
		return (FAIL);
	int exit_code = map_setup(&data->mlx, &lst_map, &data->map);
	// if (map_setup(&data->mlx, &lst_map, &data->map) == FAIL)
	// {
	// 	delete_all_lstmap(&lst_map);
	// 	return (FAIL);
	// }
	delete_all_lstmap(&lst_map);
	if (exit_code == FAIL)
		return (FAIL);
	if (map_checker(&data->map, &data->player) == 1)
		return (ft_return(ERROR, FAIL, "Map Invalid"));
	return (SUCCESS);
}

void	data_clean(t_data *data)
{
	printf("data_clean\n");
	data->map.grid = ft_tab_f(data->map.grid);
	window_clean(&data->win);
	textures_clean(&data->map.textures, data->mlx);
	if (data->minimap.screen.img)
		mlx_destroy_image(data->mlx, data->minimap.screen.img);
	if (data->minimap.screen.win)
		mlx_destroy_window(data->mlx, data->minimap.screen.win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
}
