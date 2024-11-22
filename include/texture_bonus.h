/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:27:09 by aska              #+#    #+#             */
/*   Updated: 2024/11/22 06:00:42 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_BONUS_H
# define TEXTURES_BONUS_H

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
	t_texture	tex[14];
}				t_textures;

int				texture_get_color(t_texture *t, int x, int y);
int				texture_load_to_buffer(void *mlx, t_texture *t, char *path);
void			textures_buffer_clean(t_textures *t);

#endif
