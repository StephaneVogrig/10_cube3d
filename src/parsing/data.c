/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:18:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/10/03 09:26:16 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

int	file_load(char *path, t_data *data)
{
	int			fd;
	t_lstmap	*lst_map;

	lst_map = NULL;
	if (chk_box(open_file(&fd, path), EQ, SUCCESS, path) == 1)
		return (ft_return(ERROR, FAIL, "Error to open file"));
	if (chk_box(file_process(data->mlx, &data->map.textures, &fd), EQ, SUCCESS,
			"File Processing") == 1)
		return (ft_return(ERROR, FAIL, "Error to discovery asset"));
	if (chk_box(init_map_process(&data->map, &lst_map, fd), EQ, SUCCESS,
			"Initialize temporary map") == 1)
		return (ft_return(ERROR, FAIL, "Error on Initialization Map"));
	if (chk_box(set_var_creation_map(&data->map), EQ, SUCCESS,
			"Setting Map Variables") == 1)
		return (ft_return(ERROR, FAIL, "Error on Allocation Map"));
	if (chk_box(map_creation(&data->map, &lst_map), EQ, SUCCESS,
			"Creating Map") == 1)
		return (ft_return(ERROR, FAIL, "Error on Map Creation"));
	if (chk_box(map_checker(&data->map, &data->player), EQ, SUCCESS, "Check Map") == 1)
		return (ft_return(ERROR, FAIL, "Map Invalid"));
	return (SUCCESS);
}

void	data_init(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	data->key.down = 0;
}

int	data_setup(t_data *data, char *pathname)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ft_return(ERROR, FAIL, "Error on mlx_init"));
	chk_box(SUCCESS, EQ, SUCCESS, "mlx initialization");
	textures_set_mlx(&data->map.textures, data->mlx);
	if (file_load(pathname, data) == FAIL)
		return (ft_return(ERROR, FAIL, "Error on file_load"));
	if (window_setup(&data->win, data->mlx) == FAIL)
		return (ft_return(ERROR, FAIL, "Error on window_setup"));
	if (minimap_setup(data->mlx, &data->minimap, &data->map) == FAIL)
		return (ft_return(ERROR, FAIL, "Error on minimap_setup"));
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
