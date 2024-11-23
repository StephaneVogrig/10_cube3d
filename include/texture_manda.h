/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manda.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:11:26 by stephane          #+#    #+#             */
/*   Updated: 2024/11/23 15:04:53 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef TEXTURE_MANDA_H
# define TEXTURE_MANDA_H

# include "img_mlx.h"
# include "libft.h"
# include "mlx.h"
# include "stdio.h"
# include "typedef.h"
# include "vec2i.h"

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

int				texture_get_color(t_texture *t, int x, int y);
int				texture_load_to_buffer(void *mlx, t_texture *t, char *path);
void			textures_buffer_clean(t_textures *t);

#endif
