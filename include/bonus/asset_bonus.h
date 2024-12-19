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

# include "color.h"
# include "texture.h"
# include "asset_lst_bonus.h"

typedef struct s_asset
{
	char		**key;
	void		**value;
	t_bool		*is_color;
	t_texture	tex[14];
}				t_asset;

int asset_lst_to_array(void *mlx, t_asset *textures, t_asset_lst **head);
int asset_destroy(t_asset *t);
t_texture	*asset_get_texture(t_asset *t, char *cell);
void print_asset_array(t_asset *t);
int	get_index_by_key_cell(t_asset *t, char *key);

// void			textures_buffer_clean(t_asset *t);

#endif
