/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:31:39 by aska              #+#    #+#             */
/*   Updated: 2025/01/27 14:56:51 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_bonus.h"
#include "asset_utils_bonus.h"

int	asset_destroy(t_asset *t)
{
	int	i;

	if (t->key == NULL || t->value == NULL)
		return (FAIL);
	t->key = ft_tab_f(t->key);
	i = 0;
	while (t->value[i] != NULL)
		asset_buffer_destroy(t->value[i++]);
	free(t->value);
	return (SUCCESS);
}

static int	asset_init(t_asset *asset, int size, t_asset_lst *head)
{
	int	i;

	asset->key = ft_calloc(sizeof(char *), (size + 1));
	asset->value = ft_calloc(sizeof(void *), (size + 1));
	if (asset->key == NULL || asset->value == NULL)
	{
		free(asset->key);
		free(asset->value);
		return (ft_return(ERROR, FAIL, "asset_init: malloc failed"));
	}
	i = 0;
	while (head != NULL)
	{
		if (asset_set_key_value(asset, head->key, size, i++) == FAIL)
			return (ft_return(ERROR, FAIL, "asset_init: malloc failed"));
		head = head->next;
	}
	return (SUCCESS);
}

int	asset_lst_to_array(void *mlx, t_asset *asset, t_asset_lst *head)
{
	int		size;
	int		i;
	t_rgb	rgb;

	size = get_asset_lst_size(head);
	if (asset_init(asset, size, head) == FAIL)
		return (FAIL);
	i = 0;
	while (i != size)
	{
		if (ft_strrchr(head->value, '.') == NULL)
		{
			if (color_set_rgb(&rgb, head->value) == FAIL)
				return (FAIL);
			if (color_to_buffer(&rgb, asset->value[i]) == FAIL)
				return (FAIL);
		}
		else if (texture_load_to_buffer(mlx, asset->value[i],
				head->value) == FAIL)
			return (FAIL);
		head = head->next;
		i++;
	}
	return (SUCCESS);
}
