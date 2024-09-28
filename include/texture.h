/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:11:26 by stephane          #+#    #+#             */
/*   Updated: 2024/09/28 18:03:28 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "mlx.h"
# include "stdio.h"
# include "typedef.h"

typedef struct s_texture
{
	void		*mlx;
	void		*img;
	int			width;
	int			height;
}				t_texture;

typedef struct s_textures
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_rgb		floor_rgb;
	t_rgb		ceil_rgb;
}				t_textures;

int				texture_setup(t_texture *t, void *mlx, char *path);
void			textures_clean(t_textures *t, void *mlx);
int				texture_jpg_setup(t_texture *t, void *mlx, char *path);

#endif
