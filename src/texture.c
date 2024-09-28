/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:12:00 by stephane          #+#    #+#             */
/*   Updated: 2024/09/23 22:13:05 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "texture.h"

int	texture_setup(t_texture *t, void *mlx, char *path)
{
	t->img = mlx_bmp_file_to_image(mlx, path, &t->width, &t->height);
	if (t->img == NULL)
		return (FAIL);
	return (SUCCESS);
}

int	texture_jpg_setup(t_texture *t, void *mlx, char *path)
{
	t->img = mlx_jpg_file_to_image(mlx, path, &t->width, &t->height);
	if (t->img == NULL)
		return (FAIL);
	return (SUCCESS);
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
