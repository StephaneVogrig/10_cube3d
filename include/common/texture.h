/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:38:29 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/25 19:22:56 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "img_mlx.h"
# include "mlx.h"
# include "libft.h"

typedef struct s_img
{
	int			*buffer;
	int			width;
	int			height;
}				t_texture;

int	texture_get_color(t_texture *t, int x, int y);
int	texture_load_to_buffer(void *mlx, t_texture *t, char *path);

#endif