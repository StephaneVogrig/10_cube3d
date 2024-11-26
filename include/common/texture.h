/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:06:03 by ygaiffie          #+#    #+#             */
/*   Updated: 2024/11/26 17:00:08 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "img_mlx.h"

typedef struct t_texture
{
	int	*buffer;
	int	width;
	int	height;
}		t_texture;

int		texture_get_color(t_texture *t, int x, int y);
int		texture_load_to_buffer(void *mlx, t_texture *t, char *path);

#endif