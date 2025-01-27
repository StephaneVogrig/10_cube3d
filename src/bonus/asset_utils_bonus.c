/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:45:48 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 15:05:04 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_utils_bonus.h"

int	get_asset_lst_size(t_asset_lst *head)
{
	int			size;
	t_asset_lst	*tmp;

	size = 0;
	tmp = head;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	asset_buffer_destroy(t_texture *t)
{
	free(t->buffer);
	free(t);
}

int	asset_set_key_value(t_asset *asset, char *key, int size, int i)
{
	asset->value[i] = ft_calloc(sizeof(t_texture *), (size + 1));
	if (asset->value[i] == NULL)
		return (FAIL);
	asset->key[i] = ft_strdup(key);
	if (asset->key[i] == NULL)
		return (FAIL);
	return (SUCCESS);
}

int	color_to_buffer(t_rgb *rgb, t_texture *t)
{
	t->buffer = malloc(sizeof(int));
	if (t->buffer == NULL)
		return (ft_return(ERROR, FAIL, "color_to_buffer: malloc failed"));
	t->buffer[0] = rgb->integer;
	t->width = 1;
	t->height = 1;
	return (SUCCESS);
}
