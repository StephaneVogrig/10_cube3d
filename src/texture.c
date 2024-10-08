/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:12:00 by stephane          #+#    #+#             */
/*   Updated: 2024/10/03 10:08:53 by svogrig          ###   ########.fr       */
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
