/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:18:30 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/13 18:14:09 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	data_init(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	data->key.down = 0;
}

int	mlx_setup(t_data *data, t_tex_path *tex_path, t_textures *textures)
{
	int	exit_code;

	(void)data;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ft_return(ERROR, 258, "Error on mlx_init"));
	textures_set_mlx(&data->map.textures, data->mlx);
	exit_code = texture_load(&textures->north, tex_path->no);
	exit_code |= texture_load(&textures->south, tex_path->so);
	exit_code |= texture_load(&textures->east, tex_path->ea);
	exit_code |= texture_load(&textures->west, tex_path->we);
	if (exit_code == SUCCESS)
	exit_code = window_setup(&data->win, data->mlx);
	return (exit_code);
}

void tex_path_clean(t_tex_path *tex_path)
{
	tex_path->no = ft_char_f(tex_path->no);
	tex_path->so = ft_char_f(tex_path->so);
	tex_path->we = ft_char_f(tex_path->we);
	tex_path->ea = ft_char_f(tex_path->ea);
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
		exit_code = mlx_setup(data, &tex_path, &data->map.textures);
	tex_path_clean(&tex_path);
	return (exit_code);
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