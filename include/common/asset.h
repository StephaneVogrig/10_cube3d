/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:06:58 by aska              #+#    #+#             */
/*   Updated: 2024/11/25 19:23:53 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_V2_H
# define TEXTURE_V2_H

# include "libft.h"
# include "img_mlx.h"

typedef struct s_img
{
	int			*buffer;
	int			width;
	int			height;
}				t_texture;

typedef struct s_textures
{
	t_texture	tex[14];
	
}				t_textures;

int	texture_get_color(t_texture *t, int x, int y);

#endif