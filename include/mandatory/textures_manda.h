/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_manda.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:11:26 by stephane          #+#    #+#             */
/*   Updated: 2024/11/23 16:32:10 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef TEXTURES_MANDA_H
# define TEXTURES_MANDA_H

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
