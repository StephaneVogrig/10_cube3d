/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_mlx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:42:59 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/11/20 18:26:47 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_MLX_H
#define IMG_MLX_H

#include "libft.h"
#include "typedef.h"
#include "mlx.h"

typedef struct s_img_mlx
{
	void		*mlx;
	void		*img;
	int			width;
	int			height;
} t_img_mlx;

int img_mlx_load_file(void *mlx, t_img_mlx *t, char *path);
int	*img_mlx_to_buffer(t_img_mlx *img);

#endif
