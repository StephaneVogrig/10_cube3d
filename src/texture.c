/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:12:00 by stephane          #+#    #+#             */
/*   Updated: 2024/11/12 02:19:23 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

void	textures_set_mlx(t_textures *t, void *mlx)
{
	t->north.mlx = mlx;
	t->south.mlx = mlx;
	t->east.mlx = mlx;
	t->west.mlx = mlx;
}

void	textures_clean(t_textures *t, void *mlx)
{
	if (t->north.img)
		mlx_destroy_image(mlx, t->north.img);
	if (t->south.img)
		mlx_destroy_image(mlx, t->south.img);
	if (t->east.img)
		mlx_destroy_image(mlx, t->east.img);
	if (t->west.img)
		mlx_destroy_image(mlx, t->west.img);
}

int	texture_load(t_texture *t, char *path)
{
	char	*extension;
	int exit_code;

	exit_code = SUCCESS;
	extension = ft_strrchr(path, '.');
	if (extension == NULL)
		exit_code = ft_return(ERROR, 269, "Texture extension not found");
	if (ft_strcmp(extension, ".jpg") == 0 || ft_strcmp(extension, ".jpeg") == 0)
		t->img = mlx_jpg_file_to_image(t->mlx, path, &t->width, &t->height);
	else if (ft_strcmp(extension, ".bmp") == 0)
		t->img = mlx_bmp_file_to_image(t->mlx, path, &t->width, &t->height);
	else if (ft_strcmp(extension, ".png") == 0)
		t->img = mlx_png_file_to_image(t->mlx, path, &t->width, &t->height);
	else if (t->img == NULL)
		exit_code = ft_return(ERROR, 270, "Texture attribution failed");
	else
		exit_code = ft_return(ERROR, 271, "Texture extension not supported");
	return (exit_code);
}

int	texture_selector(t_textures *textures, char *key, char *img_path)
{
	if (ft_strncmp(key, "NO", 2) == 0)
		return (texture_load(&textures->north, img_path));
	else if (ft_strncmp(key, "SO", 2) == 0)
		return (texture_load(&textures->south, img_path));
	else if (ft_strncmp(key, "WE", 2) == 0)
		return (texture_load(&textures->west, img_path));
	else if (ft_strncmp(key, "EA", 2) == 0)
		return (texture_load(&textures->east, img_path));
	else
		return (SUCCESS);
}