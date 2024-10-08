/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:18:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/08 03:01:17 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "data.h"

int	file_load(char *path, t_lstmap *lst_map)
{
	int			fd;

	if (open_file(&fd, path) == FAIL)
		return (FAIL);
	if 

		
	if (chk_box(file_process(data->mlx, &data->map.textures, &fd), EQ, SUCCESS,
			"File Processing") == 1)
		return (ft_return(ERROR, FAIL, "Error to discovery asset"));
	return (SUCCESS);
}

int	map_setup(t_lstmap *lst_map, t_map *map)
{
	if (chk_box(init_map_process(&data->map, &lst_map, fd), EQ, SUCCESS,
			"Initialize temporary map") == 1)
		return (ft_return(ERROR, FAIL, "Error on Initialization Map"));
	if (chk_box(set_var_creation_map(&data->map), EQ, SUCCESS,
			"Setting Map Variables") == 1)
		return (ft_return(ERROR, FAIL, "Error on Allocation Map"));
	if (chk_box(map_creation(&data->map, &lst_map), EQ, SUCCESS,
			"Creating Map") == 1)
		return (ft_return(ERROR, FAIL, "Error on Map Creation"));
	if (chk_box(map_checker(&data->map, &data->player), EQ, SUCCESS,
			"Check Map") == 1)
		return (ft_return(ERROR, FAIL, "Map Invalid"));
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
	
	data_init(data);
	if (mlx_setup(data) == FAIL)
		return (FAIL);
	if (file_load(pathname, lst_map) == FAIL)
		return (ft_return(ERROR, FAIL, "Error on file_load"));
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
