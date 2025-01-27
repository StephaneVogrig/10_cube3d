/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:18:30 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/27 18:05:55 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_manda.h"

void	data_init(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	data->key.down = 0;
	data->tg_fov_2 = tan((FOV / 2) * (PI / 180));
}

int	mlx_setup(t_data *data, t_tex_path *tex_path, t_textures *textures)
{
	int	exit_code;

	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ft_return(ERROR, 258, "Error on mlx_init"));
	exit_code = texture_load_to_buffer(data->mlx, &textures->north,
			tex_path->no);
	exit_code |= texture_load_to_buffer(data->mlx, &textures->south,
			tex_path->so);
	exit_code |= texture_load_to_buffer(data->mlx, &textures->east,
			tex_path->ea);
	exit_code |= texture_load_to_buffer(data->mlx, &textures->west,
			tex_path->we);
	data->win.height = WIN_H;
	data->win.width = WIN_W;
	if (exit_code == SUCCESS)
		exit_code = window_setup(&data->win, data->mlx);
	return (exit_code);
}

void	tex_path_clean(t_tex_path *tex_path)
{
	tex_path->no = ft_char_f(tex_path->no);
	tex_path->so = ft_char_f(tex_path->so);
	tex_path->we = ft_char_f(tex_path->we);
	tex_path->ea = ft_char_f(tex_path->ea);
}

int	data_setup(t_data *data, char *map_path)
{
	t_tex_path	tex_path;
	int			exit_code;

	ft_bzero(&tex_path, sizeof(tex_path));
	exit_code = lstmap_extract_info(&data->textures, &data->map, &tex_path,
			map_path);
	if (exit_code == SUCCESS)
		exit_code = map_checker(&data->map, &data->player);
	if (exit_code == SUCCESS)
		exit_code = mlx_setup(data, &tex_path, &data->textures);
	tex_path_clean(&tex_path);
	if (exit_code == SUCCESS)
		exit_code = ray_setup(&data->rays, data->win.width);
	data->scale_screen = (data->win.width / 2) / data->tg_fov_2;
	return (exit_code);
}

void	data_clean(t_data *data)
{
	data->map.grid = ft_tab_f(data->map.grid);
	textures_buffer_clean(&data->textures);
	window_destroy(&data->win);
	ray_destroy(&data->rays);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
}
