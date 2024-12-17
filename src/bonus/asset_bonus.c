/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:31:39 by aska              #+#    #+#             */
/*   Updated: 2024/12/17 18:18:01 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_bonus.h"
#include "asset_lst_bonus.h"
#include "id_tex_bonus.h"
#include "libft.h"
#include "debug.h"

static int get_lst_size(t_asset_lst *head)
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
}

int asset_destroy(t_asset *t)
{
	int i;

	t->key = ft_tab_f(t->key);
	i = 0;
	while (t->value[i] != NULL)
	{

		if (t->is_color[i] == FALSE)
		{
			printf("ptr: %p\n", t->value[i]);
			asset_buffer_destroy(t->value[i]);
		}
		i++;
	}
	ft_free(t->value);
	ft_free(t->is_color);
	return (SUCCESS);
}

int asset_lst_to_array(void *mlx, t_asset *textures, t_asset_lst **head)
{
	int size;
	int i;

	size = get_lst_size(*head);
	textures->key = ft_calloc(sizeof(char *), (size + 1));
	textures->value = ft_calloc(sizeof(void *), (size + 1));
	textures->is_color = ft_calloc(sizeof(t_bool), (size + 1));
	if (textures->key == NULL || textures->value == NULL || textures->is_color == NULL)
	{
		free(textures->key);
		free(textures->value);
		free(textures->is_color);
		return (FAIL);
	}
	i = 0;
	while(i < size)
	{
		textures->value[i] = ft_calloc(sizeof(t_texture *), (size + 1));
		if (textures->value[i] == NULL)
		{
			asset_destroy(textures);
			return (FAIL);
		}
		texture_load_to_buffer(mlx, textures->value[i], (*head)->value);
		textures->key[i] = (*head)->key;
		// textures->is_color[i] = (*head)->is_color;
		*head = (*head)->next;
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
				return (((t_texture *)t->value[i]));
		return (NULL);
	}
	while (t->key[++i] != NULL)
		if (t->key[i][1] == *cell)
			return (((t_texture *)t->value[i]));
	return (NULL);
}
