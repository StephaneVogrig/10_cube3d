/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:46:11 by svogrig           #+#    #+#             */
/*   Updated: 2025/01/30 17:12:48 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

inline int	texture_get_color(t_texture *t, int x, int y)
{
	return (t->buffer[(x * t->height) + y]);
}

int	texture_load_to_buffer(void *mlx, t_texture *t, char *path)
{
	t_img_mlx	img_mlx;
	int			exit_code;

	ft_bzero(&img_mlx, sizeof(img_mlx));
	exit_code = 0;
	exit_code = img_mlx_load_file(mlx, &img_mlx, path);
	if (exit_code == SUCCESS)
	{
		t->buffer = img_mlx_to_buffer(&img_mlx);
		if (t->buffer == NULL)
			exit_code = ft_return(ERROR, FAIL, "texture_load_to_buffer", path);
		t->height = img_mlx.height;
		t->width = img_mlx.width;
		mlx_destroy_image(img_mlx.mlx, img_mlx.img);
	}
	return (exit_code);
}
