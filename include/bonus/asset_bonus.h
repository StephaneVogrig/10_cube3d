/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:27:09 by aska              #+#    #+#             */
/*   Updated: 2024/11/25 19:26:33 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_BONUS_H
# define ASSET_BONUS_H

# include "texture.h"
# include "color.h"

typedef struct s_asset
{
	t_texture	tex[14];
}				t_asset;

t_texture	*asset_get_texture(t_asset *t, char *cell);
void	textures_buffer_clean(t_asset *t);

#endif