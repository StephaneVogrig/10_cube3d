/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:18:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/26 16:35:45 by aska             ###   ########.fr       */
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
	if (window_setup(&data->win, data->mlx) == FAIL)
		return (FAIL);
	textures_set_mlx(&data->map.textures, data->mlx);
	return (chk_box(SUCCESS, EQ, SUCCESS, "mlx initialization"));
}

int	data_setup(t_data *data, char *pathname)
{
	t_lstmap	*lst_map;
	int			exit_code;

	lst_map = NULL;
	data_init(data);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ft_return(ERROR, FAIL, "Error on mlx_init"));
	if (file_load(pathname, &lst_map) == FAIL)
		return (FAIL);
	exit_code = lstmap_extraction_info(data->mlx, &lst_map, &data->map);
	delete_all_lstmap(&lst_map);
	if (exit_code == FAIL)
		return (FAIL);
	if (map_checker(&data->map, &data->player) == FAIL)
		return (ft_return(ERROR, FAIL, "Map Invalid"));
	if (mlx_setup(data) == FAIL)
		return (FAIL);
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
