/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_tex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:20:49 by aska              #+#    #+#             */
/*   Updated: 2024/11/19 01:47:37 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ID_TEX_H
# define ID_TEX_H

#include "texture.h"

typedef enum e_id_tex
{
	NO,
	SO,
	WE,
	EA
}	t_id_tex;

void	idtex_set_texture_by_id(char* path, t_id_tex id_tex);
void	*idtex_get_texture_by_id(t_id_tex id_tex);

#endif // !ID_TEX_H
