/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:31:39 by aska              #+#    #+#             */
/*   Updated: 2024/12/20 04:40:04 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_bonus.h"
#include "asset_lst_bonus.h"
#include "id_tex_bonus.h"
#include "libft.h"
#include "debug.h"
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

	printf("asset_destroy\n");
	t->key = ft_tab_f(t->key);
	i = 0;
	while (t->value[i] != NULL)
		asset_buffer_destroy(t->value[i++]);
	ft_free(t->value);
	return (SUCCESS);
}

static int asset_init(t_asset *asset, int size)
{
	asset->key = ft_calloc(sizeof(char *), (size + 1));
	asset->value = ft_calloc(sizeof(void *), (size + 1));
	if (asset->key == NULL || asset->value == NULL)
	{
		free(asset->key);
		free(asset->value);
		return (FAIL);
	}
	return (SUCCESS);
}
static int color_to_buffer(t_rgb *rgb, t_texture *t)
{
	t->buffer = malloc(sizeof(int));
		if (t->buffer == NULL)
			return (FAIL);
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
	if (asset_init(asset, size) == FAIL)
		return (FAIL);
	i = 0;
	while(i < size)
	{
		asset->value[i] = ft_calloc(sizeof(t_texture *), (size + 1));
		if (asset->value[i] == NULL)
			return (FAIL);
		asset->key[i] = head->key;
		if (ft_strrchr(head->value, '.') == NULL)
		{
			color_set_rgb(&rgb, head->value);
			color_to_buffer(&rgb, asset->value[i]);
		}
		else
			texture_load_to_buffer(mlx, asset->value[i], head->value);
		head = head->next;
		i++;
	}
	return (SUCCESS);
}

t_texture	*asset_get_texture(t_asset *t, char *cell)
{
	int i;

	i = -1;
	if (ft_isdigit(*cell) == FALSE)
	{
		while (t->key[++i] != NULL)
			if (*cell == *t->key[i])
				return (t->value[i]);
		return (NULL);
	}
	while (t->key[++i] != NULL)
		if (t->key[i][1] == *cell)
			return (t->value[i]);
	return (NULL);
}
