/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:35:07 by aska              #+#    #+#             */
/*   Updated: 2024/10/22 09:26:09 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_utils.h"

int	texture_attribution(void *mlx, t_texture *tex, char *path)
{
	char	*extension;

	(void)tex;
	(void)mlx;
	extension = ft_strrchr(path, '.');
	if (extension == NULL)
		return (ft_return(ERROR, FAIL, "Texture extension not found"));
	if (ft_strcmp(extension, ".jpg") == 0)
	{
		printf("IMG.JPG\n");
		tex->img = mlx_jpg_file_to_image(mlx, path, &tex->width, &tex->height);
	}
	else if (ft_strcmp(extension, ".bmp") == 0)
	{
		printf("IMG.BMP\n");
		tex->img = mlx_bmp_file_to_image(mlx, path, &tex->width, &tex->height);
	}
	else if (ft_strcmp(extension, ".png") == 0)
	{
		printf("IMG.PNG\n");
		tex->img = mlx_png_file_to_image(mlx, path, &tex->width, &tex->height);
	}
	else
		(ft_display(ERROR, "Texture extension not supported"));
	if (tex->img == NULL)
		return (ft_return(ERROR, FAIL, "Texture attribution failed"));
	return (SUCCESS);
}

int	path_seletor(void *mlx, t_textures *textures, char *key, char *img_path)
{
	if (ft_strncmp(key, "NO", 2) == 0)
		return (texture_attribution(mlx, &textures->north, img_path));
	else if (ft_strncmp(key, "SO", 2) == 0)
		return (texture_attribution(mlx, &textures->south, img_path));
	else if (ft_strncmp(key, "WE", 2) == 0)
		return (texture_attribution(mlx, &textures->west, img_path));
	else if (ft_strncmp(key, "EA", 2) == 0)
		return (texture_attribution(mlx, &textures->east, img_path));
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

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (FALSE);
	while (line[i] != '\n')
	{
		if (line[i] != ' ')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_map_valid(char *line)
{
	int i;

	if (line == NULL)
		return (FALSE);
	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isthis(line[i], " 01NSEW\n") == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}