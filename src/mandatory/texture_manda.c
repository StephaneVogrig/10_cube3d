/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manda.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/11/23 15:04:24 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "texture_manda.h"

inline int	texture_get_color(t_texture *t, int x, int y)
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
		mlx_destroy_image(mlx, img_mlx.img);
	}
	return (exit_code);
}

void textures_buffer_clean(t_textures *t)
{
	free(t->north.buffer);
	free(t->south.buffer);
	free(t->east.buffer);
	free(t->west.buffer);
}


