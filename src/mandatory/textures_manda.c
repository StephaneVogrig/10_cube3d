/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_manda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:59:23 by aska              #+#    #+#             */
/*   Updated: 2025/01/28 01:08:23 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures_manda.h"

void	textures_buffer_clean(t_textures *t)
{
	free(t->north.buffer);
	free(t->south.buffer);
	free(t->east.buffer);
	free(t->west.buffer);
}
