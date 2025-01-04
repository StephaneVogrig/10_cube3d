/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:31:39 by aska              #+#    #+#             */
/*   Updated: 2025/01/04 14:37:50 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_bonus.h"
#include "asset_lst_bonus.h"
#include "libft.h"
#include "color.h"

static int get_asset_lst_size(t_asset_lst *head)
{
	int		size;
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

static void asset_buffer_destroy(t_texture *t)
{
	free(t->buffer);
	free(t);
}

int asset_destroy(t_asset *t)
{
	int i;

	if (t->key == NULL || t->value == NULL)
		return (FAIL);
	t->key = ft_tab_f(t->key);
	i = 0;
	while (t->value[i] != NULL)
		asset_buffer_destroy(t->value[i++]);
	ft_free(t->value);
	return (SUCCESS);
}

int asset_set_key_value(t_asset *asset, char *key, int size, int i)
{
	asset->value[i] = ft_calloc(sizeof(t_texture *), (size + 1));
	if (asset->value[i] == NULL)
		return (FAIL);
	asset->key[i] = ft_strdup(key);
	if (asset->key[i] == NULL)
		return (FAIL);
	return (SUCCESS);
}

static int asset_init(t_asset *asset, int size, t_asset_lst *head)
{
	int i;

	asset->key = ft_calloc(sizeof(char *), (size + 1));
	asset->value = ft_calloc(sizeof(void *), (size + 1));
	if (asset->key == NULL || asset->value == NULL)
	{
		free(asset->key);
		free(asset->value);
		return (ft_return(ERROR, FAIL,"asset_init: malloc failed"));
	}
	i = 0;
	while (head != NULL)
	{
		if (asset_set_key_value(asset, head->key, size, i++) == FAIL)
			return (ft_return(ERROR, FAIL,"asset_init: malloc failed"));
		head = head->next;
	}
	return (SUCCESS);
}
static int color_to_buffer(t_rgb *rgb, t_texture *t)
{
	t->buffer = malloc(sizeof(int));
		if (t->buffer == NULL)
			return (ft_return(ERROR, FAIL,"color_to_buffer: malloc failed"));
	t->buffer[0] = rgb->integer;
	t->width = 1;
	t->height = 1;
	return (SUCCESS);
}

int asset_lst_to_array(void *mlx, t_asset *asset, t_asset_lst *head)
{
	int size;
	int i;
	t_rgb rgb;

	size = get_asset_lst_size(head);
	if (asset_init(asset, size, head) == FAIL)
		return (FAIL);
	i = 0;
	while(i != size)
	{
		if (ft_strrchr(head->value, '.') == NULL)
		{
			if (color_set_rgb(&rgb, head->value) == FAIL)
				return (FAIL);
			if (color_to_buffer(&rgb, asset->value[i]) == FAIL)
				return (FAIL);
		}
		else
			if (texture_load_to_buffer(mlx, asset->value[i], head->value) == FAIL)
				return (FAIL);
		head = head->next;
		i++;
	}
	return (SUCCESS);
}
