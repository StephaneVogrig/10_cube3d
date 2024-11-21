/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:11:26 by stephane          #+#    #+#             */
/*   Updated: 2024/11/21 13:37:22 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "libft.h"
# include "mlx.h"
# include "stdio.h"
# include "typedef.h"
# include "vec2i.h"
# include "img_mlx.h"

typedef struct s_texture
{
	int			*buffer;
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

int		texture_get_color(t_texture *t, int x, int y);
void	textures_set_mlx(t_textures *t, void *mlx);
void	textures_clean(t_textures *t, void *mlx);
int		texture_load_to_buffer(void *mlx, t_texture *t, char *path);
int		texture_selector(t_textures *textures, char *key,
					char *img_path);

#endif
