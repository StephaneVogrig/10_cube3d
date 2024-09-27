/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:35:07 by aska              #+#    #+#             */
/*   Updated: 2024/09/27 18:07:49 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	texture_attribution(void *mlx, t_texture *tex, char *path, char *extension)
{
	if (ft_strcmp(extension, ".jpg") == 0)
		tex->img = mlx_jpg_file_to_image(mlx, path, &tex->img_w, &tex->img_h);
	else if (ft_strcmp(extension, ".bmp") == 0)
		tex->img = mlx_bmp_file_to_image(mlx, path, &tex->img_w, &tex->img_h);
	else if (ft_strcmp(extension, ".png") == 0)
		tex->img = mlx_png_file_to_image(mlx, path, &tex->img_w, &tex->img_h);
	else
		(ft_display(ERROR, "Texture extension not supported"));
	// extension = ft_char_f(extension);
	if (tex->img == NULL)
		return (ft_return(ERROR, FAIL, "Texture attribution failed"));
	return (SUCCESS);
}

int	path_seletor(void *mlx, t_textures *textures, char *key, char *img_path)
{
	char	*extension;

	extension = ft_strrchr(img_path, '.');
	if (extension == NULL)
		return (ft_return(ERROR, FAIL, "Texture extension not found"));
	if (ft_strncmp(key, "NO", 2) == 0)
		return (texture_attribution(mlx, &textures->no, img_path, extension));
	else if (ft_strncmp(key, "SO", 2) == 0)
		return (texture_attribution(mlx, &textures->so, img_path, extension));
	else if (ft_strncmp(key, "WE", 2) == 0)
		return (texture_attribution(mlx, &textures->we, img_path, extension));
	else if (ft_strncmp(key, "EA", 2) == 0)
		return (texture_attribution(mlx, &textures->ea, img_path, extension));
	else if (ft_strncmp(key, "F", 1) == 0)
		return (texture_attribution(mlx, &textures->floor, img_path,
				extension));
	else if (ft_strncmp(key, "C", 1) == 0)
		return (texture_attribution(mlx, &textures->ceil, img_path, extension));
	else
		return (SUCCESS);
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
