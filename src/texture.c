/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/11/19 16:10:35 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

inline int	texture_get_color(t_texture *t, int x, int y)
{
	return (t->buffer[(x * t->height) + y]);
}

void	textures_set_mlx(t_textures *t, void *mlx)
{
	int i;

	while(i < 8)
		t->tex[i++].mlx = mlx;
}

void	textures_clean(t_textures *t, void *mlx)
{
		int i;

	while(i < 8)
	{
		if (t->tex[i].img)
			mlx_destroy_image(mlx, t->tex[i].img);
		i++;
	}
}


void	mlx_img_to_buffer(t_texture *t, int *buffer, int height, int width)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			*buffer = mlx_get_image_pixel(t->mlx, t->img, x, y);
			buffer++;
			y++;
		}
		x++;
	}
}

int	texture_buffer_init(t_texture *t)
{
	t->buffer = malloc(sizeof(*(t->buffer)) * (t->height * t->width));
	if (t->buffer == NULL)
		return (EXIT_FAILURE);
	mlx_img_to_buffer(t, t->buffer, t->height, t->width);
	return (SUCCESS);
}

int	texture_load(t_texture *t, char *path)
{
	char	*extension;

	extension = ft_strrchr(path, '.');
	if (extension == NULL)
		return (ft_return(ERROR, 269, "Texture extension not found"));
	if (ft_strcmp(extension, ".jpg") == 0 || ft_strcmp(extension, ".jpeg") == 0)
		t->img = mlx_jpg_file_to_image(t->mlx, path, &t->width, &t->height);
	else if (ft_strcmp(extension, ".bmp") == 0)
		t->img = mlx_bmp_file_to_image(t->mlx, path, &t->width, &t->height);
	else if (ft_strcmp(extension, ".png") == 0)
		t->img = mlx_png_file_to_image(t->mlx, path, &t->width, &t->height);
	else
		(ft_display(ERROR, "Texture extension not supported"));
	if (t->img == NULL)
		return (ft_return(ERROR, 270, "Texture attribution failed"));
	return (texture_buffer_init(t));
}

// int	texture_selector(t_textures *textures, char *key, char *img_path)
// {
// 	if (ft_strncmp(key, "NO", 2) == 0)
// 		return (texture_load(&textures->north, img_path));
// 	else if (ft_strncmp(key, "SO", 2) == 0)
// 		return (texture_load(&textures->south, img_path));
// 	else if (ft_strncmp(key, "WE", 2) == 0)
// 		return (texture_load(&textures->west, img_path));
// 	else if (ft_strncmp(key, "EA", 2) == 0)
// 		return (texture_load(&textures->east, img_path));
// 	else
// 		return (SUCCESS);
// }

t_textures *textures_get_ptr(void)
{
	static t_textures textures;
	
	return (&textures);
}