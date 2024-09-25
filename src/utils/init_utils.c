/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:35:07 by aska              #+#    #+#             */
/*   Updated: 2024/09/25 18:19:44 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	texture_attribution(void *mlx, t_texture *tex, char *path)
{
	tex->img = mlx_png_file_to_image(mlx, path, &tex->img_w, &tex->img_h);
	if (tex->img == NULL)
		return (ft_return(ERROR, FAIL, "Texture attribution failed"));
	return (SUCCESS);
}

int	path_seletor(void *mlx, t_textures *textures, char *key, char *img_path)
{
	if (ft_strncmp(key, "NO", 2) == 0)
		return (texture_attribution(mlx, &textures->no, img_path));
	else if (ft_strncmp(key, "SO", 2) == 0)
		return (texture_attribution(mlx, &textures->so, img_path));
	else if (ft_strncmp(key, "WE", 2) == 0)
		return (texture_attribution(mlx, &textures->we, img_path));
	else if (ft_strncmp(key, "EA", 2) == 0)
		return (texture_attribution(mlx, &textures->ea, img_path));
	else if (ft_strncmp(key, "F", 1) == 0)
		return (texture_attribution(mlx, &textures->floor, img_path));
	else if (ft_strncmp(key, "C", 1) == 0)
		return (texture_attribution(mlx, &textures->ceil, img_path));
	else
		return (SUCCESS);
	// else if (ft_strncmp(key, "F", 1) == 0)
	// 	cub->img->f_path = ft_strdup(img_path);
	// else if (ft_strncmp(key, "C", 1) == 0)
	// 	cub->img->c_path = ft_strdup(img_path);
	// else if (ft_strncmp(key, "BGM", 3) == 0)
	// 	cub->img->bgm_path = ft_strdup(img_path);
	// else
	// 	return (NULL);
}

int	setup_key(char *line, char **key)
{
	*key = ft_substr(line, 0, ft_strlen_endc(line, ' '));
	if (*key == NULL)
		return (ft_return(ERROR, FAIL, "Allocating key failed"));
	return (SUCCESS);
}

int	setup_value(char *line, char *key, char **value)
{
	int	key_len;

	key_len = ft_strlen(key);
	*value = ft_substr(line, key_len, ft_strlen_endc(line + key_len, '\n'));
	if (*value == NULL)
		return (ft_return(ERROR, FAIL, "Allocating texture path failed"));
	return (SUCCESS);
}
