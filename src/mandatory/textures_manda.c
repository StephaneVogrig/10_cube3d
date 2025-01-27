/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_manda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/27 15:59:23 by aska             ###   ########.fr       */
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
