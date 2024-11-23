/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:27:09 by aska              #+#    #+#             */
/*   Updated: 2024/11/23 16:31:34 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef TEXTURES_BONUS_H
# define TEXTURES_BONUS_H

# include "texture.h"

typedef struct s_textures
{
	t_texture	tex[14];
}				t_textures;

void	textures_buffer_clean(t_textures *t);

#endif
