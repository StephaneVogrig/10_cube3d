/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:38:29 by svogrig           #+#    #+#             */
/*   Updated: 2025/02/03 21:05:12 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "color.h"
# include "img_mlx.h"
# include "libft.h"
# include "mlx.h"

typedef struct s_img
{
	int	*buffer;
	int	width;
	int	height;
}		t_texture;

void	texture_get_color(t_rgb *dest, t_texture *t, int x, int y);
int		texture_load_to_buffer(void *mlx, t_texture *t, char *path);

#endif