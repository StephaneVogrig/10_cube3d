/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_manda.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:11:26 by stephane          #+#    #+#             */
/*   Updated: 2025/01/27 16:04:54 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_MANDA_H
# define TEXTURES_MANDA_H

# include "color.h"
# include "texture.h"

typedef struct s_textures
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_rgb		floor_rgb;
	t_rgb		ceil_rgb;
}				t_textures;

void			textures_buffer_clean(t_textures *t);

#endif
