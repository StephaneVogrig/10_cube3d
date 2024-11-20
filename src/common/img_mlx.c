/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:41:39 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/11/20 18:22:58 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img_mlx.h"

int	img_mlx_load_file(void *mlx, t_img_mlx *img, char *path)
{
	char	*extension;

	extension = ft_strrchr(path, '.');
	if (extension == NULL)
		return (ft_return(ERROR, 269, "Texture extension not found"));
	if (ft_strcmp(extension, ".jpg") == 0 || ft_strcmp(extension, ".jpeg") == 0)
		img->img = mlx_jpg_file_to_image(mlx, path, &img->width, &img->height);
	else if (ft_strcmp(extension, ".bmp") == 0)
		img->img = mlx_bmp_file_to_image(mlx, path, &img->width, &img->height);
	else if (ft_strcmp(extension, ".png") == 0)
		img->img = mlx_png_file_to_image(mlx, path, &img->width, &img->height);
	else
		(ft_display(ERROR, "Texture extension not supported"));
	if (img->img == NULL)
		return (ft_return(ERROR, 270, "Texture attribution failed"));
	img->mlx = mlx;
	return (SUCCESS);
}

int	*img_mlx_to_buffer(t_img_mlx *img)
{
	int	*buffer;
	int	x;
	int	y;

	buffer = malloc(sizeof(*buffer) * (img->height * img->width));
	if (buffer == NULL)
		return (NULL);
	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			*buffer = mlx_get_image_pixel(img->mlx, img->img, x, y);
			buffer++;
			y++;
		}
		x++;
	}
	return (buffer);
}
