/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:31:39 by aska              #+#    #+#             */
/*   Updated: 2024/11/23 16:32:55 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "textures_bonus.h"

void textures_buffer_clean(t_textures *t)
{
	int	i;

	i = 0;
	while(t->tex[i].buffer)
	{
		free(t->tex[i].buffer);
		t->tex[i].buffer = NULL;
	}
}
