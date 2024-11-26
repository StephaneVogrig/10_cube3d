/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:46:11 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/26 12:23:05 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

int	texture_get_color(t_texture *t, int x, int y)
{
	return (t->buffer[(x * t->height) + y]);
}

int	texture_load_to_buffer(void *mlx, t_texture *t, char *path)
{
	t_img_mlx	img_mlx;
	int			exit_code;

	exit_code = img_mlx_load_file(mlx, &img_mlx, path);
	if (exit_code == SUCCESS)
	{
		t->buffer = img_mlx_to_buffer(&img_mlx);
		if (t->buffer == NULL)
			exit_code = ft_return(ERROR, 273, "Texture Buffer allocation failure");
		t->height = img_mlx.height;
		t->width = img_mlx.width;
		img_mlx_destroy_image(mlx, img_mlx.img);
	}
	return (exit_code);
}
