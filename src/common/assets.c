/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygaiffie <ygaiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:46:11 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/26 17:14:18 by ygaiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"

int assets_load_buffer(void *mlx, t_assets *assets)
{
	t_dictionaries *d_tmp;
	t_texture *t_tmp;

	d_tmp = assets->textures;
	while (d_tmp->next != NULL)
	{
		if (texture_load_to_buffer(mlx, t_tmp, (char*)d_tmp->value) != SUCCESS)
			break;
		
		d_tmp = d_tmp->next;
	}
}

