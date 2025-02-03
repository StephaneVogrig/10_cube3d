/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:41:39 by ygaiffie          #+#    #+#             */
/*   Updated: 2025/02/04 00:08:29 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img_mlx.h"

int	img_mlx_load_file(void *mlx, t_img_mlx *img, char *path)
{
	char	*extension;

	img->mlx = mlx;
	extension = ft_strrchr(path, '.');
	if (extension == NULL)
		return (ft_return(ERROR, FAIL, "Texture extension not found", path));
	if (ft_strcmp(extension, ".jpg") == 0 || ft_strcmp(extension, ".jpeg") == 0)
		img->img = mlx_jpg_file_to_image(mlx, path, &img->width, &img->height);
	else if (ft_strcmp(extension, ".bmp") == 0)
		img->img = mlx_bmp_file_to_image(mlx, path, &img->width, &img->height);
	else if (ft_strcmp(extension, ".png") == 0)
		img->img = mlx_png_file_to_image(mlx, path, &img->width, &img->height);
	else
		(ft_display(ERROR, "Texture extension not supported"));
	if (img->img == NULL)
		return (ft_return(ERROR, FAIL, "mlx_file_to_img function failed", NULL));
	return (SUCCESS);
}

int	*img_mlx_to_buffer(t_img_mlx *img)
{
	int	*buffer;
	int	*head;
	int	x;
	int	y;

	buffer = malloc((img->height * img->width) * sizeof(*buffer));
	if (buffer == NULL)
		return (NULL);
	head = buffer;
	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
			*buffer++ = mlx_get_image_pixel(img->mlx, img->img, x, y++);
		x++;
	}
	return (head);
}

int	img_mlx_destroy_image(void *mlx, t_img_mlx *img)
{
	mlx_destroy_image(mlx, img->img);
	return (SUCCESS);
}
