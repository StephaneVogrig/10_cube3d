/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionarie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aska <aska@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:35:10 by aska              #+#    #+#             */
/*   Updated: 2024/11/27 03:23:05 by aska             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionarie.h"
#include "libft.h"

static t_dictionarie *create_node(char *key, void *value)
{
	t_dictionarie *new_node;

	new_node = malloc(sizeof(t_dictionarie));
	if (!new_node)
		return (NULL);
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

static void insert_node(t_dictionarie **dict, t_dictionarie *new_node)
{
	t_dictionarie *current;
	t_dictionarie *prev = NULL;

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

int dict_insert(t_dictionarie **dict, char *key, void *value)
{
	t_dictionarie *new_node;

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

char *dict_get(t_dictionarie *dict, char *key)
{
	t_dictionarie *current = dict;

	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

void dict_destroy(t_dictionarie **dict)
{
	t_dictionarie *current;
	t_dictionarie *next;

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

static int ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void set_array_from_list(t_dictionarie *dict, char **array_key, t_texture *array_texture)
{
	int i;
	t_dictionarie *current;

	i = 0;
	current = dict;
	while (current)
	{
		array_key[i] = current->key;
		array_texture[i] = 
		current = current->next;
		i++;
	}