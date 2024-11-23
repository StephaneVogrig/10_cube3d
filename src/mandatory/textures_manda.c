/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_manda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/11/23 16:33:01 by svogrig          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "textures_manda.h"

void textures_buffer_clean(t_textures *t)
{
	free(t->north.buffer);
	free(t->south.buffer);
	free(t->east.buffer);
	free(t->west.buffer);
}
