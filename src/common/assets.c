/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:46:11 by svogrig           #+#    #+#             */
/*   Updated: 2024/11/27 03:05:15 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"

void 	array_init(t_assets *assets, t_dictionarie *dict)
{
	int size;

	size = ft_lstsize(dict);
	assets->array_key = malloc(sizeof(char*) * size);
	assets->array_value = malloc(sizeof(t_texture) * size);
}


int assets_load_buffer(void *mlx, t_assets *assets)
{
	t_dictionarie *d_tmp;
	t_texture *t_tmp;

	d_tmp = assets->entry;
	while (d_tmp->next != NULL)
	{
		if (texture_load_to_buffer(mlx, t_tmp, (char*)d_tmp->value) != SUCCESS)
			break;
		
		d_tmp = d_tmp->next;
	}
}

