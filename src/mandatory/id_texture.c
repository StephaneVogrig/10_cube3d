/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:20:06 by aska              #+#    #+#             */
/*   Updated: 2024/11/19 02:20:05 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "id_tex.h"

void	idtex_set_texture_by_id(char* path, t_id_tex id_tex)
{
	t_textures	*t;
	
	t = textures_get_ptr();
	if (id_tex == NO)
		texture_load(t, path);
	else if (id_tex == SO)
		texture_load(t, path);
	else if (id_tex == WE)
		texture_load(t, path);
	else if (id_tex == EA)
		texture_load(t, path);
}

void	*idtex_get_texture_by_id(t_id_tex id_tex)
{
	t_textures	*t;
	
	t = textures_get_ptr();
	if (id_tex == NO)
		return (t->north.img);
	else if (id_tex == SO)
		return (t->south.img);
	else if (id_tex == WE)
		return (t->west.img);
	else if (id_tex == EA)
		return (t->east.img);
	return (NULL);
}