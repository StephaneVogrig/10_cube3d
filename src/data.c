/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:18:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/09/29 10:53:58 by aska             ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
	// ok = map_checker(cub);
	// if (chk_box(ok, EQ, SUCCESS, "Check Map") == 1)
	// 	helltrain(cub, ERROR, 1, "Error on Initialization Map");
	player_setup(&data->player, &data->map);
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
