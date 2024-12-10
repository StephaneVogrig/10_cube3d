/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:31:39 by aska              #+#    #+#             */
/*   Updated: 2024/12/10 19:02:00 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_bonus.h"
#include "id_tex_bonus.h"


t_texture	*asset_get_texture(t_asset *t, char *cell)
{
	char	key[2];

	if (ft_isdigit(*cell) == FALSE)
		return (&t->tex[get_index_by_key(cell)]);
	key[0] = 'W';
	key[1] = *cell;

	return (&t->tex[get_index_by_key(key)]);
}

void textures_buffer_clean(t_asset *t)
{
	int	i;

	i = 0;
	while(t->tex[i].buffer)
	{
		free(t->tex[i].buffer);
		t->tex[i].buffer = NULL;
	}
}
