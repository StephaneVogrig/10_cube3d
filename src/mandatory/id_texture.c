/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:20:06 by aska              #+#    #+#             */
/*   Updated: 2024/11/20 12:02:27 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "id_tex.h"

int	idtex_set_texture_by_id(char* path, t_id_tex id_tex)
{
	t_textures	*t;
	
	t = textures_get_ptr();
	if (id_tex == NO)
		return (texture_load(&t->tex[0], path));
	else if (id_tex == SO)
		return (texture_load(&t->tex[1], path));
	else if (id_tex == WE)
		return (texture_load(&t->tex[2], path));
	else if (id_tex == EA)
		return (texture_load(&t->tex[3], path));
	else
		return (SUCCESS)
}

void	*idtex_get_texture_by_id(t_id_tex id_tex)
{
	t_textures	*t;
	
	t = textures_get_ptr();
	if (id_tex == NO)
		return (t->tex[0].img);
	else if (id_tex == SO)
		return (t->tex[1].img);
	else if (id_tex == WE)
		return (t->tex[2].img);
	else if (id_tex == EA)
		return (t->tex[3].img);
	return (NULL);
}