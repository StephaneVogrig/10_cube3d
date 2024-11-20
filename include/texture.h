/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:11:26 by stephane          #+#    #+#             */
/*   Updated: 2024/11/20 16:46:01 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "libft.h"
# include "mlx.h"
# include "stdio.h"
# include "typedef.h"
# include "vec2i.h"

typedef struct s_texture
{
	void		*mlx;
	void		*img;
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
int		texture_load_to_buffer(t_texture *t, char *path);
int		texture_selector(t_textures *textures, char *key,
					char *img_path);

#endif
