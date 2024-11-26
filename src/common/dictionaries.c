/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionaries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:35:10 by aska              #+#    #+#             */
/*   Updated: 2024/11/26 01:25:38 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionarie.h"
#include "libft.h"

static t_dictionaries *create_node(char *key, void *value)
{
	t_dictionaries *new_node;

	new_node = malloc(sizeof(t_dictionaries));
	if (!new_node)
		return (NULL);
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

static void insert_node(t_dictionaries **dict, t_dictionaries *new_node)
{
	t_dictionaries *current;
	t_dictionaries *prev = NULL;

	current = *dict;
	while (current && ft_strcmp(current->key, new_node->key) < 0)
	{
		prev = current;
		current = current->next;
	}
	if (prev == NULL)
	{
		new_node->next = *dict;
		*dict = new_node;
	}
	else
	{
		prev->next = new_node;
		new_node->next = current;
	}
}

int dict_insert(t_dictionaries **dict, char *key, void *value)
{
	t_dictionaries *new_node;

	if (!key || !value)
		return (FAIL);
	new_node = create_node(key, value);
	if (!new_node)
		return (FAIL);
	if (!(*dict))
	{
		*dict = new_node;
		return (SUCCESS);
	}
	insert_node(dict, new_node);
	return (SUCCESS);
}

char *dict_get(t_dictionaries *dict, char *key)
{
	t_dictionaries *current = dict;

	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

void dict_destroy(t_dictionaries **dict)
{
	t_dictionaries *current;
	t_dictionaries *next;

	if (!dict || !*dict)
		return;

	current = *dict;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*dict = NULL;
}
